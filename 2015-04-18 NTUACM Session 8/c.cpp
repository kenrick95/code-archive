#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
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

int V;
struct edge {
    int t;
    int c;
};
struct node {
    int n;
    vector<edge> e;
};
node ma[10010];
struct da{
   int cur, dist;
   bool operator < (da A) const{ return dist>A.dist; }
   da (int a,int c) {
      cur=a;
      dist=c;
   }
};

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int a, b;
    scanf("%d %d %d", &V, &a, &b);
    int x, y, z;
    for (int i = 0; i < V; i++) {
        y = 0;
        scanf("%d", &x);
        node a;
        a.n = x;
        for (int j = 0; j < x; j++) {
            scanf("%d", &z);
            edge e;
            e.t = z;
            e.c = min(1, y++);
            a.e.push_back(e);
        }
        ma[i+1] = a;
    }

    int dist[10010];
    priority_queue<da> q;
    for (int i = 0; i <= V; i++) {
        dist[i] = INF;
        // printf("[%d]: ", i);
        // for (int j = 0; j < ma[i].n; j++) {
        //     printf("%d<%d> ", ma[i].e[j].t, ma[i].e[j].c);
        // }
        // printf("\n");
    }
    dist[a] = 0;
    q.push(da(a, 0));
    while (!q.empty()) {
        da h = q.top();
        for (int i = 0; i < ma[h.cur].n; i++) {
            if (dist[h.cur] + ma[h.cur].e[i].c < dist[ma[h.cur].e[i].t]) {
                dist[ma[h.cur].e[i].t] = dist[h.cur] + ma[h.cur].e[i].c;
                q.push(da(ma[h.cur].e[i].t, dist[ma[h.cur].e[i].t]));
            }
        }
        q.pop();
    }
    if (dist[b] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[b]);
    }
    

    return 0;
}
