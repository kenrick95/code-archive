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
 * @problem Packing Polygons
 * @url     https://uva.onlinejudge.org/external/100/p10005.pdf
 * @status  WA
 */
struct point {
    double x, y;
    point() { x = y = 0.; };
    point(double _x, double _y) : x(_x), y(_y) {};
};

double dist(point A, point B) {
    return hypot(A.x - B.x, A.y - B.y);
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int n;
    vector<point> P;
    while (scanf("%d", &n) == 1) {
        if (n == 0)
            break;
        P.clear();
        double R, x, y;

        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &y);
            P.push_back(point(x, y));
        }
        scanf("%lf", &R);

        bool can = true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dist(P[i], P[j]) > R * 2.) {
                    can = false;
                    break;
                }
            }
            if (!can)
                break;
        }
        if (can) {
            printf("The polygon can be packed in the circle.\n");
        } else {
            printf("There is no way of packing that polygon.\n");
        }
    }
    return 0;
}
