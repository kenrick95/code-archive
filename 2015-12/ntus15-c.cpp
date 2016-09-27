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
int V, E;

struct d {
  int n, c;
  d(int _n, int _c) : n(_n), c(_c) {}
  d() { n = c = 0; }
  bool operator < (d A) const {
    return c < A.c || (c == A.c && n < A.n);
  }
};
vector<d> m[10240];
int dist[10240], cnt[10240];

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);

    while (scanf("%d %d", &V, &E) != EOF) {
      int x, y, c;
      for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &x, &y, &c);
        m[x].push_back(d(y, c));
        m[y].push_back(d(x, c));
      }
      for (int i = 0; i < V; i++) {
        dist[i] = INF;
        cnt[i] = 0;
      }
      priority_queue<d> pq;
      pq.push(d(0, 0));

      dist[0] = 0;

      while (!pq.empty()) {
        d head = pq.top();
        printf("%d %d\n", head.n, head.c);
        pq.pop();
        for (int i = 0; i < m[head.n].size(); i++) {
          if (dist[head.n] + m[head.n][i].c < dist[m[head.n][i].n]) {
            dist[m[head.n][i].n] = dist[head.n] + m[head.n][i].c;
            cnt[m[head.n][i].n] = cnt[head.n];
            pq.push(d(m[head.n][i].n, dist[head.n] + m[head.n][i].c));
          } else if (dist[head.n] + m[head.n][i].c == dist[m[head.n][i].n]) {
            cnt[m[head.n][i].n]++;
            //pq.push(d(m[head.n][i].n, dist[head.n] + m[head.n][i].c));
          }
        }
      }
      for (int i = 0; i < V; i++) {
        printf("[%3d] dist: %10d, cnt %10d\n", i, dist[i], cnt[i]);
      }

      printf("%d\n", cnt[V - 1]);
      printf("%d\n", dist[V - 1]);
    }
    return 0;
}
