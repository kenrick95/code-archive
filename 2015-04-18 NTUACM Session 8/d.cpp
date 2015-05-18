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
 * @problem 
 * @url    
 * @status  
 */

double max(double a, double b) {
    return (a < b) ? b : a;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int r, c, h[50][50], v, t = 0;
    double temp, l, ri, mid;
    while (scanf("%d %d", &r, &c) != EOF) {
        if (r == 0 && c == 0)
            break;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &h[i][j]);
            }
        }
        scanf("%d", &v);
        l = -INF * 2.;
        ri = INF * 2.;
        temp = INF * 2;
        while (fabs(temp - v) > 0.0000001) {
            mid = (l + ri) / 2.;
            temp = 0.0;
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++) {
                    temp += max(0, mid - h[i][j]) * 100.0;
                }
            // printf("%lf %lf %lf %lf\n", l, ri, mid, temp);
            if (fabs(temp - v) < 0.0000001)
                break;

            if (temp < v) {
                l = mid;
            } else {
                ri = mid;
            }
        }

        int cnt = 0;
        double per = 0.0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (mid > h[i][j])
                    cnt++;
        per = 100. * (double) cnt / (double) (r * c);
        printf("Region %d\n", ++t);
        printf("Water level is %.2lf meters.\n", mid);
        printf("%.2lf percent of the region is under water.\n", per);
        printf("\n");
    }
    return 0;
}
