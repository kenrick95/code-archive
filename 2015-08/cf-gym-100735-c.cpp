#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem 
 * @url     
 * @status  
 */
struct coord
{
    int x, y;
    coord() { x = y = 0; }
    coord(int _x, int _y) { x = _x; y = _y; }
};

struct state
{
    coord A, G;
    state() { A = coord(0, 0); G = coord(0, 0); }
};

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int R, C;
    char ma[32][32];
    int dist[25][25][25][25];
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        scanf("%s", ma[i]);
    }
    int ax, ay, gx, gy, px, py; // A --> P, avoiding G
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < R; k++)
                for (int l = 0; l < C; l++)
                    dist[i][j][k][l] = INF;
            if (ma[i][j] == 'A') {
                ay = i;
                ax = j;
            } else if (ma[i][j] == 'G') {
                gy = i;
                gx = j;
            } else if (ma[i][j] == 'P') {
                py = i;
                px = j;
            }
        }
    }
    queue<state> q;
    // map<state, int> dist;
    state head, child;
    head.A = coord(ax, ay);
    head.G = coord(gx, gy);
    q.push(head);
    dist[ay][ax][gy][gx] = 0;

    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    while(!q.empty()) {
        head = q.front();

        // printf("%d %d %d %d: %d [%c]\n", head.A.x, head.A.y, head.G.x, head.G.y, dist[head.A.y][head.A.x][head.G.y][head.G.x], ma[head.A.y][head.A.x]);
        if (ma[head.A.y][head.A.x] == 'P') {
            printf("%d\n", dist[head.A.y][head.A.x][head.G.y][head.G.x]);
            return 0;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            child.A.x = head.A.x + dir[i][0];
            child.A.y = head.A.y + dir[i][1];
        
            if (0 <= child.A.x && child.A.x < C &&
                0 <= child.A.y && child.A.y < R &&
                !(child.A.x == child.G.x && child.A.y == child.G.y) &&
                ma[child.A.y][child.A.x] != 'X'

            ) {
                child.G.x = head.G.x;
                child.G.y = head.G.y;
                if (child.A.x < child.G.x && ma[child.G.y][child.G.x - 1] != 'X'
                    && 0 <= child.G.x - 1 && child.G.x - 1 < C && 0 <= child.G.y && child.G.y < R)
                    child.G.x -= 1;
                else if (child.A.x > child.G.x && ma[child.G.y][child.G.x + 1] != 'X'
                    && 0 <= child.G.x + 1 && child.G.x + 1 < C && 0 <= child.G.y && child.G.y < R)
                    child.G.x += 1;
                else {
                    if (child.A.y < child.G.y && ma[child.G.y - 1][child.G.x] != 'X'
                    && 0 <= child.G.x && child.G.x < C && 0 <= child.G.y - 1&& child.G.y - 1 < R) {
                        child.G.y -= 1;
                    } else if (ma[child.G.y + 1][child.G.x] != 'X'
                    && 0 <= child.G.x && child.G.x < C && 0 <= child.G.y + 1 && child.G.y + 1 < R) {
                        child.G.y += 1;
                    }
                }

                if (child.A.x != child.G.x || child.A.y != child.G.y &&
                dist[child.A.y][child.A.x][child.G.y][child.G.x] > dist[head.A.y][head.A.x][head.G.y][head.G.x] + 1) {
            // printf("   %d %d %d %d: [%d] > [%d] + 1\n", child.A.x, child.A.y, child.G.x, child.G.y, dist[child.A.y][child.A.x][child.G.y][child.G.x], dist[head.A.y][head.A.x][head.G.y][head.G.x]);
                    dist[child.A.y][child.A.x][child.G.y][child.G.x] = dist[head.A.y][head.A.x][head.G.y][head.G.x] + 1;
                    q.push(child);
                }
            }
        }

    }
    printf("-1\n");
    return 0;
}
