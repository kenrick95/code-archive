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
 
/* Problem: Perjalanan Teringan
 * URL: http://tokilearning.org/training/7/chapter/75/problem/416
 */
 
int R, C, map[1010][1010], dist[1010][1010];
int ra, ca, rb, cb;
 
struct vertex {
    int r, c;
    vertex (int _r, int _c) {
        r = _r;
        c = _c;
    }
    vertex() {
        r = 0;
        c = 0;
    };
};
struct da {
    vertex node;
    int dist;
    bool operator < (da A) const{ return dist > A.dist; }
     
    da (vertex _node, int _dist) {
        node = _node;
        dist = _dist;
    }
};
 
int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    // BFS/ Dijkstra
    // dist[][]
     
    scanf("%d %d", &R, &C);
    // NOTE: index starting from 1 (ONE)!!
    for (int i = 0; i <= R + 1; i++) {
        for (int j = 0; j <= C + 1; j++) {
            map[i][j] = -1;
        }
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    scanf("%d %d", &ra, &ca);
    scanf("%d %d", &rb, &cb);
     
    for (int i = 0; i <= R + 1; i++) {
        for (int j = 0; j <= C + 1; j++) {
            dist[i][j] = 1000000007;
        }
    }
    dist[ra][ca] = 0;
     
    priority_queue<da> pq;
    pq.push(da(vertex(ra, ca), dist[ra][ca]));
     
    while (!pq.empty()) {
        da now = pq.top();
        pq.pop();
        int cost;
         
        // Go down
        cost = dist[now.node.r][now.node.c];
        for (int i = now.node.r + 1; i <= R; i++) {
            if (map[i][now.node.c] == -1) break;
            cost = max(cost, map[i][now.node.c]);
             
            if (dist[i][now.node.c] > cost) {
                dist[i][now.node.c] = cost;
                pq.push(da(vertex(i, now.node.c), cost));
            }
        }
         
         
        // Go up
        cost = dist[now.node.r][now.node.c];
        for (int i = now.node.r - 1; i >= 1; i--) {
            if (map[i][now.node.c] == -1) break;
            cost = max(cost, map[i][now.node.c]);
             
            if (dist[i][now.node.c] > cost) {
                dist[i][now.node.c] = cost;
                pq.push(da(vertex(i, now.node.c), cost));
            }
        }
        // Go left
        cost = dist[now.node.r][now.node.c];
        for (int i = now.node.c + 1; i <= C; i++) {
            if (map[now.node.r][i] == -1) break;
            cost = max(cost, map[now.node.r][i]);
             
            if (dist[now.node.r][i] > cost) {
                dist[now.node.r][i] = cost;
                pq.push(da(vertex(now.node.r, i), cost));
            }
        }
        // Go right
        cost = dist[now.node.r][now.node.c];
        for (int i = now.node.c - 1; i >= 1; i--) {
            if (map[now.node.r][i] == -1) break;
            cost = max(cost, map[now.node.r][i]);
             
            if (dist[now.node.r][i] > cost) {
                dist[now.node.r][i] = cost;
                pq.push(da(vertex(now.node.r, i), cost));
            }
        }
         
    }
     
     
   /* for (int i = 0; i <= R + 1; i++) {
        for (int j = 0; j <= C + 1; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }*/
     
    printf("%d\n", dist[rb][cb]);
     
    return 0;
}
