#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cassert>
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
struct point {
  int x, y;
  point(int x, int y) : x(x), y(y) {}
  point() { x = y = 0; }
  bool operator < (point A) const {
    return x < A.x || (x == A.x && y < A.y);
  }
};
map<point, vector<point> > sw;
bool ma[128][128];
bool vis[128][128];
int ans = 0;
queue<point> q;
const int dir[4][4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;

int main(){
    freopen("lightson.in","r",stdin);
    freopen("lightson.out","w",stdout);
    scanf("%d %d", &n, &m);
    memset(ma, 0, sizeof ma);
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < m; i++) {
      int a, b, c, d;
      scanf("%d %d %d %d", &a, &b, &c, &d);
    //  if (sw.count(point(a, b)) > 0) {
        sw[point(a, b)].push_back(point(c, d));
      //} else {}
    }
    q.push(point(1, 1));
    ma[1][1] = true;
    ans = 0;
    while (!q.empty()) {
      point head = q.front();
      q.pop();
      //printf("[%d %d]\n", head.x, head.y);

      //printf("[%d %d] %d\n", head.x, head.y, can);

      for (int i = 0; i < sw[point(head.x, head.y)].size(); i++) {
        point cur = sw[point(head.x, head.y)][i];
        if (!ma[cur.x][cur.y]) {
          ma[cur.x][cur.y] = true;
        }
        bool can = !vis[cur.x][cur.y];
        for (int i = 0; i < 4; i++) {
          can |= vis[cur.x + dir[i][0]][cur.y + dir[i][1]];
        }
        if (can)
          q.push(point(cur.x, cur.y));
        //printf("[%d %d] %d %d\n", head.x, head.y, cur.x, cur.y);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        ans += ma[i][j];
      }
    }
    printf("%d\n", ans);
    return 0;
}
