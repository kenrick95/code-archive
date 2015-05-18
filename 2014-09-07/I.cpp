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
   int x, y, ch;
   da (int a, int b, int c) {
      x = a;
      y = b;
      ch = c;
   }
};

int R,C,S;
char a[1005][1005];
int state[1005][1005];
int ax[4]={1,0,-1,0};
int ay[4]={0,1,0,-1};

queue<da> q;

int bfs(int xo, int yo, int ch) {
    state[yo][xo] = ch;
    q.push(da(xo, yo, ch));
    
    while (!q.empty()) {
        da now = q.front();
        q.pop();
        printf("%d %d %d\n", now.x, now.y, now.ch);
        for (int i=0; i<=3; i++) {
            
            if ((0 <= (now.y + ay[i]) && (now.y + ay[i]) < R)
             && (0 <= (now.x + ax[i]) && (now.x + ax[i]) < C)) {
                if (a[now.y + ay[i]][now.x + ax[i]] == '.') {
                    if (state[now.y + ay[i]][now.x + ax[i]] * now.ch == -1) {
                        return ch * (xo + 1);
                    }
                    if (state[now.y + ay[i]][now.x + ax[i]] == 0) {
                        q.push(da(now.x + ax[i], now.y + ay[i], now.ch));
                        state[now.y + ay[i]][now.x + ax[i]] = now.ch;
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

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	
    while (scanf("%d %d %d", &R, &C, &S) != EOF) {
        for (int i = 0; i < R; i++) {
            scanf("%s", a[i]);
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                state[i][j] = 0;
            }
        }
        //1: alien
        int check = 0;
        for (int i = 0; i < C; i++) {
            if (a[0][i] == '.') {
                check = bfs(i, 0, 1);
            }
        }
        for (int i = 0; i < C; i++) {
            if (state[R-1][i] == 1) {
                check = -1;
                break;
            }
            if (a[R-1][i] == '.') {
                check = bfs(i, R-1, -1);
                if (check != 0) {
                    break;
                }
            }
        }
        if (check != 0) {
            int col;
            for (int k = 0; k < S; k++) {
                scanf("%d", &col);
            }
            printf("0\n");
            //printMap();
        } else {
            int col, row;
            for (int k = 0; k < S; k++) {
                scanf("%d", &col);
                if (check != 0) continue;
                if (col > 0) {
                    row = 0;
                    while (a[row][col-1] == '.') {
                        row++;
                        if (row == R-1) break;
                    }
                    a[row][col-1] = '.';
                    check = bfs(col-1, row, 1);
                } else {
                    row = R-1;
                    while (a[row][-col-1] == '.') {
                        row--;
                        if (row == 0) break;
                    }
                    a[row][-col-1] = '.';
                    check = bfs(-col-1, row, -1);
                }
                printMap();
            }
            if (check == 0) {
                printf("X\n");
            } else {
                printf("%d\n", check);
            }
            
            
            //printMap();
            /*
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    printf("%c", a[i][j]);
                }
                printf("\n");
            }*/
        }
        
        
        
        
    }
	return 0;
}
