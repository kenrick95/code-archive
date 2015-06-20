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
 * @problem Bounding box
 * @url     https://uva.onlinejudge.org/external/105/p10577.pdf
 * @status  
 */

const double PI = acos(-1.0);
const double EPS = 1e-9;
struct point {
    double x, y;
    point() { x = y = 0.; };
    point(double _x, double _y) : x(_x), y(_y) {};
};
double DEG_to_RAD(double theta) {
    return theta * PI / 180.0;
};
point rotate (point p, double theta) {
    double rad = DEG_to_RAD(theta);
    return point (p.x * cos(rad) - p.y * sin(rad),
                  p.x * sin(rad) + p.y * cos(rad));
}
struct line {
    double a, b, c;
};
void pointToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    }
    else {
        l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double) (l.a * p1.x) - p1.y;
    }
}
struct vec {
    double x, y;
    vec() { x = y = 0.0; }
    vec(double _x, double _y) : x(_x), y(_y) {};
};
vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}
int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    
    int n, T = 0;
    double x, y;
    vector<point> P;

    while (scanf("%d", &n) == 1) {
        if (n == 0)
            break;
        double minX, minY, maxX, maxY;
        for (int i = 0; i < 3; i++) {
            scanf("%lf %lf", &x, &y);
            P.push_back(point(x, y));
            if (i == 0) {
                minX = maxX = x;
                minY = maxY = y;
            }
            minX = min(minX, x);
            maxX = max(maxX, x);
            minY = min(minY, y);
            maxY = max(maxY, y);
        }
        point A = P[0], B = P[1], C = P[2];
        point mAB = point((A.x + B.x) / 2., (A.y + B.y) / 2.),
              mBC = point((C.x + B.x) / 2., (C.y + B.y) / 2.);
        vec AB = toVec(A, B), BC = toVec(B, C);
        vec mab = 

        double area = (maxX - minX) * (maxY - minY);
        printf("Polygon %d: %.3lf\n", ++T, area);

    }

    return 0;
}
