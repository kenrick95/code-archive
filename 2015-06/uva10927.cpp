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
 * @problem Bright lights
 * @url     https://uva.onlinejudge.org/external/109/10927.html
 * @status  AC
 */


struct point
{
    double x,y,z;
    point() { x = y = z = 0.0; }
    point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};
struct polar
{
    double theta, dist, height;
    point p;
    polar() { theta = dist = height = 0.0; p = point(0,0,0); }
    polar(double _t, double _d, double _h, point _p) : theta(_t), dist(_d), height(_h), p(_p) {}
};

bool cmp_theta(polar A, polar B) {
    return A.theta < B.theta || (A.theta == B.theta && A.dist < B.dist) || (A.theta == B.theta && A.dist == B.dist && A.height < B.height);
}
bool cmp_p(polar A, polar B) {
    return A.p.x < B.p.x || (A.p.x == B.p.x && A.p.y < B.p.y);
}
int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int N;
    point p;
    polar po;
    vector<polar> Po;
    vector<polar> Inv;
    double x,y,z;
    int T = 0;
    while (scanf("%d", &N) == 1) {
        if (N == 0)
            break;
        Po.clear();
        Inv.clear();
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf %lf", &x, &y, &z);
            p = point(x, y, z);
            po = polar(atan2(y, x), hypot(x, y), z, p);
            Po.push_back(po);
        }
        sort(Po.begin(), Po.end(), cmp_theta);

        polar cur = Po[0];
        for (int i = 1; i < N; i++) {
            if (Po[i].theta == cur.theta) {
                if (Po[i].height <= cur.height) {
                    Inv.push_back(Po[i]);
                } else {
                    cur = Po[i];
                }
            } else {
                cur = Po[i];
            }
        }
        printf("Data set %d:\n", ++T);
        if (Inv.size() == 0) {
            printf("All the lights are visible.\n");
        } else {
            sort(Inv.begin(), Inv.end(), cmp_p);
            printf("Some lights are not visible:\n");
            for (int i = 0; i < Inv.size(); i++) {
                printf("x = %.0lf, y = %.0lf", Inv[i].p.x, Inv[i].p.y);
                if (i + 1 < Inv.size() ) {
                    printf(";\n");
                } else {
                    printf(".\n");
                }
            }
        }
    }
    return 0;
}
