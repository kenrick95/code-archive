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
 * @problem 10:6:2
 * @url     https://uva.onlinejudge.org/external/125/p12578.pdf
 * @status  AC
 */

const double PI = acos(-1.);

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        double L;
        scanf("%lf", &L);
        double circle = PI * L * .2 * L * .2;
        double non_circle = L * .6 * L - circle;
        printf("%.2lf %.2lf\n", circle, non_circle);
    }
    return 0;
}
