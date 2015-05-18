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

 satu node dijkstranya isinya :
-Expected distance = (distance dari center + distance ke edge terdekat = (min(x - 1, y - 1, R - y, C - x)) )
-Y
-X
-Distance
-Difference

sorted based on that order
 
 */
 

int R,C,n;
int map[909][909];
int state[909][909];
int ax[4]={0, -1, 1, 0};
int ay[4]={-1, 0, 0, 1};
int minVal, minR, minC;

struct da{
    int expDist, x, y, dist, diff;
    bool operator < (da A) const{
       return expDist > A.expDist
       || (expDist == A.expDist && y > A.y)
       || (expDist == A.expDist && y == A.y && x > A.x)
       || (expDist == A.expDist && y == A.y && x == A.x && dist > A.dist)
       || (expDist == A.expDist && y == A.y && x == A.x && dist == A.dist && diff > A.diff);
    }
   da (int a, int b, int c, int d) {
      x = a;
      y = b;
      dist = c;
      expDist = min(min(x - 1, y - 1), min( R - y, C - x));
      diff = d;
   }
};

priority_queue<da> q;

int bfs(int yo, int xo) {
    state[yo][xo] = 0;
    q.push(da(xo, yo, 0, 200000000));
    int foundVal, foundX, foundY;
    foundVal = foundX = foundY = 200000000;
    
    while (!q.empty()) {
        da now = q.top();
        q.pop();
        
        if (now.expDist > foundVal) return 0;
        
        //printf("%d %d %d %d\n", now.y, now.x, now.dist, now.diff);
        
        for (int i=0; i<=3; i++) {
            
            if ((0 <= (now.y + ay[i]) && (now.y + ay[i]) < R)
             && (0 <= (now.x + ax[i]) && (now.x + ax[i]) < C)) {
                
                
                if ((now.diff >= map[now.y][now.x] - map[now.y + ay[i]][now.x + ax[i]])
                    && (map[now.y][now.x] - map[now.y + ay[i]][now.x + ax[i]] >= 0)
                    && (state[now.y + ay[i]][now.x + ax[i]] + 1 > now.dist)) {
                    
                    q.push(da(now.x + ax[i], now.y + ay[i], now.dist + 1, map[now.y][now.x] - map[now.y + ay[i]][now.x + ax[i]]));
                    state[now.y + ay[i]][now.x + ax[i]] = now.dist + 1;
                    //prev[now.y + ay[i]][now.x + ax[i]] = map[now.y][now.x];
                    
                    //printf("%d %d %d %d\n", now.y + ay[i], now.x + ax[i], now.dist, now.prev);
                    
                    //path found
                    if ((now.y + ay[i] == 0) || (now.y + ay[i] == R-1) || (now.x + ax[i] == 0) || (now.x + ax[i] == C-1)) {
                    
                        if ((now.dist + 1 <= foundVal)
                        && ((now.y + ay[i] < foundY)
                            || ((now.y + ay[i] == foundY) && ((now.x + ax[i])< foundX)))) {
                            foundVal = now.dist + 1;
                            foundY = now.y + ay[i];
                            foundX = now.x + ax[i];
                        }
                    }
                    
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
            state[i][j] = 200000000;
        }
    }
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
   //int n;
	scanf("%d", &n);
    R = 2 * n + 1;
    C = R;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &map[i][j]);
            state[i][j] = 200000000;
        }
    }
    //minVal = 200000000;
    bfs(n,n);
    //printMap();
    minR = 200000000, minC = 200000000, minVal = 200000000;
    int i,j;
    
    for (i = 1; i < R-1; i++) {
        j = 0;
        if ((minVal > state[i][j]) || ((minVal == state[i][j]) && ((i < minR) || ((i == minR) && (j < minC))))) {
            minR = i;
            minC = j;
            minVal = state[i][j];
        }
    }
    for (int i = 1; i < R-1; i++) {
        j = C-1;
        if ((minVal > state[i][j]) || ((minVal == state[i][j]) && ((i < minR) || ((i == minR) && (j < minC))))) {
            minR = i;
            minC = j;
            minVal = state[i][j];
        }
    }
    for (int j = 1; j < C-1; j++) {
        i = 0;
        if ((minVal > state[i][j]) || ((minVal == state[i][j]) && ((i < minR) || ((i == minR) && (j < minC))))) {
            minR = i;
            minC = j;
            minVal = state[i][j];
        }
    }
    for (int j = 1; j < C-1; j++) {
        i = R-1;
        if ((minVal > state[i][j]) || ((minVal == state[i][j]) && ((i < minR) || ((i == minR) && (j < minC))))) {
            minR = i;
            minC = j;
            minVal = state[i][j];
        }
    }
    
    if (minVal == 200000000) {
        printf("IMPOSSIBLE\n");
    } else {
        printf("%d\n%d %d\n", minVal, minR+1, minC+1);
    }
    
    
	return 0;
}
