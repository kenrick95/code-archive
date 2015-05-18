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

const double PI = acos(-1.0);
const double EPS = 1e-9;
/**
 * @problem  uva 10263 - Railway
 * @url    http://uva.onlinejudge.org/external/102/p10263.pdf
 * @status  AC
 */


struct point {
    double x, y;
    point() { x = y = 0.; };
    point(double _x, double _y) : x(_x), y(_y) {};
};

double sqrsum(point a) {
    return a.x * a.x + a.y * a.y;
};

double sqrdist(point a, point b) {
    return sqrsum(point(a.x - b.x, a.y - b.y));
};

double dist(point a, point b) {
    return sqrt(sqrdist(a, b));
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
bool areParallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true;
}

struct vec {
    double x, y;
    vec() { x = y = 0.0; }
    vec(double _x, double _y) : x(_x), y(_y) {};
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s);
}
point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}
double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}
/**
 * distance from P to vector AB.
 * a, b must be different
 * 
 * @param  p point P
 * @param  a point A
 * @param  b point B
 * @param  c closest point at vector AB from P
 * @return   |PC|
 */
double distToLine(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

/**
 * distance from P to line segment AB
 * @param  p point P
 * @param  a point A
 * @param  b point B
 * @param  c closest point at line segment AB from P
 * @return   |PC|
 */
double distToSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if (u > 1.0) {
        c = point(b.x, b.y);
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
}

vector<point> P;

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    point M;
    double x, y;
    int N;
    while (scanf("%lf", &x) != EOF) {
        scanf("%lf", &y);
        M = point(x, y);
        P.clear();

        scanf("%d", &N);
        if (N == 0) {
            point ans = M;
            printf("%.4lf\n", ans.x);
            printf("%.4lf\n", ans.y);
            continue;
        }
        for (int i = 0; i <= N; i++) { // there are N+1 points!
            scanf("%lf", &x);
            scanf("%lf", &y);
            P.push_back(point(x, y));
        }

        point ans, temp;
        double adist = (double) INF;
        for (int i = 0; i < N; i++) {
            if (distToSegment(M, P[i], P[i+1], temp) < adist) {
                ans = temp;
                adist = dist(M, temp);
            }
        }
        printf("%.4lf\n", ans.x);
        printf("%.4lf\n", ans.y);
    }
    return 0;
}
