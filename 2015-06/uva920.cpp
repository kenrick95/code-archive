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
 * @problem 
 * @url     
 * @status  
 */

struct point {
    double x, y;
    point() { x = y = 0.; };
    point(double _x, double _y) : x(_x), y(_y) {};
};

bool comp(point A, point B) {
    return A.x < B.x || (A.x == B.x && A.y > B.y);
};

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T, N;
    vector<point> P;
    scanf("%d", &T);
    double x, y;
    for (int t = 0; t < T; t++) {
        P.clear();
        scanf("%d", &N);
        if (N == 0)
            continue;
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", &x, &y);
            P.push_back(point(x, y));
        }
        double ans = 0.0;
        sort(P.begin(), P.end(), comp);
        point curP = point(P[N-1].x, 0.0);
        /*for (int i = 0; i < N; i++) {
            printf("(%lf, %lf)\n", P[i].x, P[i].y);
        }*/
        for (int i = N - 2; i >= 0; i--) {
            if (P[i].y > curP.y) {
                double px = (curP.y - P[i+1].y) / (P[i].y - P[i+1].y) * (P[i].x - P[i+1].x) + P[i+1].x;
                // printf("%lf\n", px);
                ans += hypot(P[i].x - px, P[i].y - curP.y);
                curP = point(P[i].x, P[i].y);
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
