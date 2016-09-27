#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
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
  point() : x(0), y(0) {};
  point(int x, int y) : x(x), y(y) {};
};
int sqrsum(point a, point b) {
  return abs(a.x - b.x) * abs(a.x - b.x) + abs(a.y - b.y) * abs(a.y - b.y);
}
// struct line {
//   point o1, o2;
//   int len;
//   line() { o1 = o2 = point(0, 0); len = 0; };
//   line(point o1, point o2) : o1(o1), o2(o2) { len = sqrsum(o1, o2); }
// };
struct len {
  int p;
  int s;
  len() : s(0), p(0) {};
  len(int p, int s) : s(s), p(p) {};
};

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T, n, x, y;
    point p[2048];
    vector<len> l[2048];
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
      scanf("%d", &n);
      for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        p[i] = point(x, y);
      }
      // int k = 0;;
      // for (int i = 0; i < n; i++) {
      //   for (int j = i + 1; j < n; j++) {
      //     l[k++] = line(p[i], p[j]);
      //   }
      // }

      for (int i = 0; i < n; i++) {
        int t;
        for (int j = i + 1; j < n; j++) {
          t = sqrsum(p[i], p[j]);
          l[i].push_back(len(j, t));
        }
      }

    }
    return 0;
}
