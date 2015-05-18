#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem RACING
 * @url     uVa 1234
 * @status  AC
 */

struct edge {
    int64 from, to, cost;
    // edge(int f, int t, int c) {
    //     from = f;
    //     to = t;
    //     cost = c;
    // }
} e[100010];
int V, E;
int parent[10010], rank[10010];

bool comp(edge A, edge B) {
    return A.cost > B.cost; // Max Spanning Tree
}

void make_set(int u) {
    parent[u] = u;
    rank[u] = 0;
}
int find_set (int u) {
    if (parent[u] == u)
        return u;
    else
        return parent[u] = find_set(parent[u]);
}
void merge_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (rank[u] < rank[v])
        parent[v] = u;
    else if (rank[u] > rank[v])
        parent[u] = v;
    else {
        parent[u] = v;
        rank[v]++;
    }
}
int64 mst() {
    sort(e, e+E, comp);
    for (int i = 0; i < V; i++) {
        make_set(i);
    }

    int u, v;
    int64 ans = 0;
    for (int i = 0; i < E; i++) {
        u = find_set(e[i].from);
        v = find_set(e[i].to);
        if (u != v) {
            ans += e[i].cost;
            merge_set(e[i].from, e[i].to);
        }
    }

    for (int i = 0; i < V; i++)
        find_set(i);

    return ans;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T;
    int64 total;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &V, &E);
        total = 0;
        for (int i = 0; i < E; i++) {
            scanf("%lld %lld %lld", &e[i].from, &e[i].to, &e[i].cost);

            // 1-based -_-
            e[i].from--;
            e[i].to--;

            total += e[i].cost;
        }
        printf("%lld\n", total - mst());
    }
    scanf("%d", &T);
    return 0;
}
