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

struct da {
    int x, b, i;
    da() { x = b = i = 0; }
    da(int _x, int _b, int _i) : x(_x), b (_b), i(_i) {}
};

int n, l, x, b;
vector<da> P;
double sav[1024];
int prev[1024];

double f(int i) {
    if (i == n - 1)
        return 0;
    if (sav[i] > -1.) {
        return sav[i];
    }
    double ret = INF * 1., temp = 0.;
    for (int j = i + 1; j < n; j++) {
        temp = f(j) + sqrt(abs(P[j].x - P[i].x - l)) - P[j].b;
        //printf("%d --> %d: %lf\n", i, j, temp);
        if (temp < ret) {
            ret = temp;
            prev[j] = i;
        }
    }
    sav[i] = ret;
    return ret;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &b);
        P.push_back(da(x, b, i + 1));
        sav[i] = -1;
        prev[i] = -1;
    }
    double temp = 0., ret = INF * 1.;
    for (int j = 0; j < n; j++) {
        temp = f(j) + sqrt(abs(P[j].x - l)) - P[j].b;
        //printf("%d: %lf\n", j, temp);
        if (temp < ret) {
            ret = temp;
            prev[j] = INF;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d: %d %lf\n", i, prev[i], sav[i]);
    }
    printf("\n");


    int cur = n - 1;
    while (prev[cur] != INF) {
        printf("%d --> %d %lf\n", cur, prev[cur], sav[cur]);
        cur = prev[cur];
    }
    return 0;
}
