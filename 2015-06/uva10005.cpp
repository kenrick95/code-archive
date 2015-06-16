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
 * @status  AC
 */
struct point {
    double x, y;
    point() { x = y = 0.; };
    point(double _x, double _y) : x(_x), y(_y) {};
};
bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - .25;
    if (det < 0.0)
        return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * .5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * .5 + (p2.x - p1.x) * h;
    return true;
}
double dist(point A, point B) {
    return hypot(A.x - B.x, A.y - B.y);
}
int sqrdist(point A, point B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int n;
    vector<point> P;
    int t = 0;
    while (scanf("%d", &n) == 1) {
        if (n == 0)
            break;
        P.clear();
        double R, x, y;
        // printf("TC %d\n", ++t);

        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &y);
            P.push_back(point(x, y));
        }
        scanf("%lf", &R);

        bool can = true, meh1, meh2;
        point temp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sqrdist(P[i], P[j]) > R * R * 4.) {
                    can = false;
                    break;
                }
            }
            if (!can)
                break;
        }
        // if (!can)
        //     printf("Give up 1!\n");
        bool really_can = false;
        if (can) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    meh1 = false, meh2 = false;
                    if (circle2PtsRad(P[i], P[j], R, temp)) {
                        for (int k = 0; k < n; k++) {
                            if (sqrdist(temp, P[k]) > R * R) {
                                meh1 = true;
                                break;
                            }
                        }
                        if (!meh1) {
                            // printf("Yay 1!\n");
                            really_can = true;
                            break;
                        }
                    }
                    if (!really_can && circle2PtsRad(P[j], P[i], R, temp)) {
                        for (int k = 0; k < n; k++) {
                            if (sqrdist(temp, P[k]) > R * R) {
                                meh2 = true;
                                break;
                            }
                        }
                        if (!meh2) {
                            // printf("Yay 2!\n");
                            really_can = true;
                            break;
                        }
                    }
                }
                if (really_can)
                    break;
            }
        }
        if (really_can || n <= 1 || (n == 2 && dist(P[0], P[1]) <= R)) {
            printf("The polygon can be packed in the circle.\n");
        } else {
            printf("There is no way of packing that polygon.\n");
        }
    }
    return 0;
}
