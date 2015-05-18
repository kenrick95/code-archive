#include <iostream>
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

/* Problem: Les Piano
 * URL: http://tokilearning.org/training/7/chapter/75/problem/426
 */
 
//int cost[2502][2502];
int dist[2502];
int V, E, st, en;

struct da {
    int node, dist;
    bool operator < (da A) const{ return dist > A.dist; }
    da (int _node, int _dist) {
        node = _node;
        dist = _dist;
    }
};
vector <int> j[2502], jc[2502];

int main(){
	scanf("%d %d %d %d", &V, &E, &st, &en);
    int f, t, c;
    for (int i = 0; i < V + 1; i++) {
        /*for (int j = 0; j < V + 1; j++) {
            cost[i][j] = 1000000009;
        }*/
        dist[i] = 1000000009;
    }
    
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &f, &t, &c);
        /*cost[f][t] = c;
        cost[t][f] = c;*/
        j[f].push_back(t);
        j[t].push_back(f);
        jc[f].push_back(c);
        jc[t].push_back(c);
    }
    dist[st] = 0;
    
    priority_queue<da> pq;
    pq.push(da(st, dist[st]));
    while (!pq.empty()) {
        da now = pq.top();
        pq.pop();
        int size = j[now.node].size();
        
        for (int i = 0; i < size; i++) {
            if (dist[j[now.node][i]] > dist[now.node] + jc[now.node][i]) {
                dist[j[now.node][i]] = dist[now.node] + jc[now.node][i];
                pq.push(da(j[now.node][i], dist[now.node] + jc[now.node][i]));
            }
        }
    }
    printf("%d\n", dist[en]);
    
	return 0;
}
