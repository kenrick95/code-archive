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
 * @problem Colourful Flowers
 * @url     https://uva.onlinejudge.org/external/111/11152.html
 * @status  AC
 */


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    double a, b, c;
    double s;
    double r, R, A, Ar, AR;
    double const PI = acos(-1.);
    while (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        s = (a + b + c) / 2.;
        A = sqrt(s * (s - a) * (s - b) * (s - c));
        r = A / s;
        R = a * b * c / 4. / A;
        Ar = PI * r * r;
        AR = PI * R * R;
        printf("%.4lf %.4lf %.4lf\n", (AR - A), (A - Ar), (Ar));
    }
    return 0;
}
