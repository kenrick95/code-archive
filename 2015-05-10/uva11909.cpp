#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000007
#define PI 3.14159265358
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem uVa 11909
 * @url     http://uva.onlinejudge.org/external/119/p11909.pdf
 * @status  AC
 */


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int l, w, h, d;
    while (scanf("%d %d %d %d", &l, &w, &h, &d) != EOF) {
        double x = 1. * h - l * tan(d * PI / 180.);
        if (x > 0.)
            printf("%.3lf mL\n", (1. * w) * (1. * l) * (1. * h + x) / 2.);
        else
            printf("%.3lf mL\n", (1. * w) * (1. * h) * (1. * h) * tan((90 - d) * PI / 180.) / 2.);
    }
    return 0;
}
