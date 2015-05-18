#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */

int n;
double x[50050], y[50050], l, r, m, lt, rt;

double f(double pos) {
    double maxi = 0.0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, hypot(x[i] - pos, y[i]));
    }
    return maxi;
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    while (scanf("%d", &n) != EOF) {
        if (n == 0) return 0;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &x[i], &y[i]);
        }
        l = -200005.0;
        r = 200005.0;
        
        m = 0.0;
        while (r - l > .00000001) {
            m = (l + r)/2.0;
            lt = l + (r - l)/3;
            rt = r - (r - l)/3;
     
            if (f(lt) > f(rt)) 
                l = lt;
            else
                r = rt;
        }
        printf("%lf %lf\n", m, f(m));
    }
    return 0;
}
