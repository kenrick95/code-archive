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
int T;
int n;
int tkn[128];
struct point {
  int x, y;
  point () : x(0), y(0) {}
  point (int _x, int _y) : x(_x), y(_y) {}
  int sqrsum() {
    return x * x + y * y;
  }
} P[128];

bool comp (point A, point B) {
  return A.sqrsum() > B.sqrsum();
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int x, y;
    while (scanf("%d", &n) != EOF) {
      if (n == 0)
        break;
      for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        P[i] = point(x, y);
        tkn[i] = false;
      }
      sort(P, P + n, comp);


      int sx = 0, sy = 0;
      // maximze to x positive, y positive
      for (int i = 0; i < n; i++) {
        if (P[i].x >= 0 && P[i].y >= 0) {
          sx += P[i].x; sy += P[i].y;
          tkn[i] = true;
        } else if (P[i].x <= 0 && P[i].y <= 0) {
          sx += -P[i].x; sy += -P[i].y;
          tkn[i] = true;
        }
      }
      for (int i = 0; i < n; i++) {
        if (!tkn[i] && sx * P[i].x >= - sy * P[i].y) {
          sx += P[i].x; sy += P[i].y;
          tkn[i] = true;
        } else if (!tkn[i]) {
          sx += -P[i].x; sy += -P[i].y;
          tkn[i] = true;
        }
      }

      //printf("%d %d\n", sx, sy);
      printf("%.3lf\n", hypot(sx, sy));
    }
    return 0;
}
