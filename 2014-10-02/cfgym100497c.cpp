#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */
 
struct da{
   int x, y, dist, prev;
   da (int a, int b, int c, int d) {
      x = a;
      y = b;
      dist = c;
      prev = d;
   }
};

int R,C;
int map[909][909];
int state[909][909];
//int prev[1023][1023];
int ax[4]={1,0,-1,0};
int ay[4]={0,1,0,-1};

queue<da> q;

int bfs(int yo, int xo) {
    state[yo][xo] = 0;
    prev[yo][xo] = map[yo][xo];
    q.push(da(xo, yo, 0, map[yo][xo]));
    
    while (!q.empty()) {
        da now = q.front();
        q.pop();
        
        //printf("%d %d %d %d\n", now.y, now.x, now.dist, now.prev);
        int dPrev = map[now.y][now.x] - now.prev;
        for (int i=0; i<=3; i++) {
            
            if ((0 <= (now.y + ay[i]) && (now.y + ay[i]) < R)
             && (0 <= (now.x + ax[i]) && (now.x + ax[i]) < C)) {
                
                if ((map[now.y + ay[i]][now.x + ax[i]] - map[now.y][now.x] >= dPrev)
                    && (state[now.y + ay[i]][now.x + ax[i]] + 1 > now.dist)) {
                    
                    q.push(da(now.x + ax[i], now.y + ay[i], now.dist + 1, map[now.y][now.x]));
                    state[now.y + ay[i]][now.x + ax[i]] = now.dist + 1;
                    //prev[now.y + ay[i]][now.x + ax[i]] = map[now.y][now.x];
                    
                }
            }
            
            
        }
    }
    return 0;
    //printf("\n");
}

void printMap() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", state[i][j]);
        }
        printf("\n");
    }
}
void resetState() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            state[i][j] = 9999999;
        }
    }
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int n;
	scanf("%d", &n);
    R = 2 * n + 1;
    C = R;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &map[i][j]);
            state[i][j] = 9999999;
            //prev[i][j] = 0;
        }
    }
    int minR = 9999999, minC = 9999999, minVal = 9999999;
    int i,j;
    
    for (i = 1; i < R-1; i++) {
        j = 0;
        
        resetState();
        bfs(i, j);
        //printMap();
        //printf("\n\n");
        if ((minVal > state[n][n]) || ((minVal == state[n][n]) && ((i < minR) || ((i == minR) && (j < minC))))) {
            minR = i;
            minC = j;
            minVal = state[n][n];
        }
    }
    for (int i = 1; i < R-1; i++) {
        j = C-1;
        
        resetState();
        bfs(i, j);
        //printMap();
        //printf("\n\n");
        if ((minVal > state[n][n]) || ((minVal == state[n][n]) && ((i < minR) || ((i == minR) && (j < minC))))) {
            minR = i;
            minC = j;
            minVal = state[n][n];
        }
    }
    for (int j = 1; j < C-1; j++) {
        i = 0;
        
        resetState();
        bfs(i, j);
        //printMap();
        //printf("\n\n");
        if ((minVal > state[n][n]) || ((minVal == state[n][n]) && ((i < minR) || ((i == minR) && (j < minC))))) {
            minR = i;
            minC = j;
            minVal = state[n][n];
        }
    }
    for (int j = 1; j < C-1; j++) {
        i = R-1;
        
        resetState();
        bfs(i, j);
        //printMap();
        //printf("\n\n");
        //printf("a: %d %d %d\n", minVal, minR, minC);
        //printf("b: %d %d %d\n", state[n][n], i, j);
        if ((minVal > state[n][n]) || ((minVal == state[n][n]) && ((i < minR) || ((i == minR) && (j < minC))))) {
            minR = i;
            minC = j;
            minVal = state[n][n];
        }
    }
    if (minVal == 9999999) {
        printf("IMPOSSIBLE\n");
    } else {
        printf("%d %d %d\n", minVal, minR+1, minC+1);
    }
    
    
	return 0;
}
