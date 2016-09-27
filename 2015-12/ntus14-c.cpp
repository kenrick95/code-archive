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

int n, m;
char c[1024];
char pos[2048];

int cv(char v) {
  if (v == 'A')
    return 11;
  else if (v == 'K' || v == 'Q' || v == 'J')
    return 10;
  return v - '0';
}
double sav[2048];

double f(int i) {
  if (i <= 0)
    return 0.0;
  //printf("%d\n", i);
  if (sav[i] > -1)
    return sav[i];

  double ret = 0.0;
  if (i <= 10) {
    ret = 0.1;
  }
  for (int k = 2; k <= 11; k++) {
    //if (pos[i - k] > 0)
    //  printf("%d %d %d\n", cv(pos[i - k]), i, k);
    if (i > k && pos[i - k] > 0 && k == cv(pos[i - k]))
      ret += f(i - k);
    else if (k == 10)
      ret += f(i - k) / 13. * 4;
    else
      ret += f(i - k) / 13.;
  }
  printf("%d %lf\n", i, ret);
  return sav[i] = ret;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);

    while (scanf("%d %d", &n, &m) != EOF) {
      int cur = m, prev = m;
      memset(pos, 0, sizeof pos);
      for (int i = 0; i < 2048; i++) {
        sav[i] = -1.;
      }
      fgets(c, 1024, stdin);
      fgets(c, 1024, stdin);
      for (int i = 0; i < n * 2; i++) {
        //printf("[%c]", c[i]);
        if (('2' <= c[i] && c[i] <= '9') || c[i] == 'J' || c[i] == 'K' || c[i] == 'A' || c[i] == 'Q') {
          pos[cur] = c[i];
          //printf("cur: %d; pos[cur]: %d\n", cur, pos[cur]);
          prev = cur;
          cur += cv(c[i]);
        }

      }
      printf("%.20lf\n", f(prev));
      //for (int i = prev; i <= cur; i++)
      //  printf("%.20lf\n", f(i));
    }
    return 0;
}
