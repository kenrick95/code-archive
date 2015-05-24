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
 * @problem Median (uVa 10347)
 * @url    http://uva.onlinejudge.org/external/103/p10347.pdf
 * @status  AC
 */


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    double ma, mb, mc;
    const double eps = 1e-9;
    double area, sigma, temp;
    while (scanf("%lf %lf %lf", &ma, &mb, &mc) == 3) {
        sigma = (double) (ma + mb + mc) / 2.;
        temp = sigma * (sigma - ma) * (sigma - mb) * (sigma - mc);
        if (temp <= eps || ma <= eps || mb <= eps || mc <= eps) {
            printf("-1.000\n");
        } else {
            area = 4. * sqrt(temp) / 3.;
            printf("%0.3lf\n", area);
        }
    }
    return 0;
}
