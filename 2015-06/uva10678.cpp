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
 * @problem The Grazing Cow
 * @url     https://uva.onlinejudge.org/external/106/10678.html
 * @status  AC
 */

double sqr(double num) {
    return num * num;
}
const double pi = 2. * acos(0);

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T;
    double D, L;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%lf %lf", &D, &L);
        double smaj, smin;
        smaj = L / 2.;// D / 2 + (L - D) / 2;
        smin = sqrt(sqr(L / 2.) - sqr(D / 2.));
        printf("%.3lf\n", pi * smaj * smin);
    }
    return 0;
}
