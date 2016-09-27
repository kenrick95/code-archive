#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cassert>
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

struct cpx {
  cpx() {}
  cpx(double aa): a(aa), b(0) {}
  cpx(double aa, double bb) : a(aa), b(bb) {}
  double a, b;
  double modsq(void) const {
    return a * a + b * b;
  }
  cpx bar(void) const {
    return cpx(a, -b);
  }
};
cpx operator + (cpx a, cpx b) {
  return cpx(a.a + b.a, a.b + b.b);
}
cpx operator * (cpx a, cpx b) {
  return cpx(a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a);
}
cpx operator / (cpx a, cpx b) {
  cpx r = a * b.bar();
  return cpx(r.a / b.modsq(), r.b / b.modsq());
}
cpx EXP(double theta) {
  return cpx(cos(theta), sin(theta));
}
const double two_pi = 4 * acos(0);

void FFT(cpx *in, cpx *out, int step, int size, int dir) {
  if (size < 1) return;
  if (size == 1) {
    out[0] = in[0];
    return;
  }
  FFT(in, out, step * 2, size / 2, dir);
  FFT(in + step, out + size / 2, step * 2, size / 2, dir);
  for (int i = 0; i < size / 2; i++) {
    cpx even = out[i];
    cpx odd = out[i + size / 2];
    out[i] = even + EXP(dir * two_pi * i / size) * odd;
    out[i + size / 2] = even + EXP(dir * two_pi * (i + size / 2) / size) * odd;
  }
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int N, M, x[262145];
    while (scanf("%d", &N) != EOF) {
      for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
      }

      cpx a[262145], b[262145];
      cpx A[262145], B[262145];
      for (int i = 0; i < N; i++) {
        a[i] = cpx(x[i], 1);
        b[i] = cpx(1, -x[i]);
      }
      // size = 2 ^ k > N, nearest to N;
      int size = 1;
      while (size < N) {
        size *= 2;
      }
      for (int i = N; i < size; i++) {
        a[i] = cpx(0, 0);
        b[i] = cpx(0, 0);
      }

      FFT(a, A, 1, size, 1);
      FFT(b, B, 1, size, 1);

      cpx AB[262145];
      for (int i = 0; i < size; i++)
        AB[i] = A[i] * B[i];

      cpx aconvb[262145];
      FFT(AB, aconvb, 1, size, -1);

      for (int i = 0; i < size; i++)
        aconvb[i] = aconvb[i] / size;

      for (int i = 0; i < size; i++) {
        printf("%7.2lf, %7.2lf\n", aconvb[i].a, aconvb[i].b);
      }
      printf("\n");



      scanf("%d", &M);
      int q;
      for (int i = 0; i < M; i++) {
        scanf("%d", &q);
      }
    }
    return 0;
}
