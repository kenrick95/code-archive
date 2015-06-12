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
 * @problem Area
 * @url     https://uva.onlinejudge.org/external/105/p10589.pdf
 * @status  AC
 */

struct point
{
    double x,y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};
struct circle
{
    point center;
    double radius;
    circle() { center = point(0, 0); radius = 0.0; }
    circle(point _center, double _radius) : center(_center), radius(_radius) {}
};
bool in_circle(circle c, point p) {
    return hypot(c.center.x - p.x, c.center.y - p.y) <= c.radius;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int N; double a;
    double x, y;
    vector<point> P;

    while (scanf("%d %lf", &N, &a) == 2) {
        if (N == 0)
            break;
        int m = 0;
        point p;
        circle c1, c2, c3, c4;
        c1 = circle(point(0,0), a);
        c2 = circle(point(0,a), a);
        c3 = circle(point(a,0), a);
        c4 = circle(point(a,a), a);
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", &x, &y);
            p = point(x,y);
            P.push_back(p);
            if (in_circle(c1, p)
                && in_circle(c2, p)
                && in_circle(c3, p)
                && in_circle(c4, p)
                )
                m++;
        }
        printf("%.5lf\n", m * a * a / N);
    }
    return 0;
}
