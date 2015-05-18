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


int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int n, x[1024], y[1024], gra[1024][1024];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            gra[i][j] = (y[j] - y[i])/(x[j] - x[i]);
        }
    }
    int same = 0;
    int ans = n * (n - 1) / 2;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            gra[i][j] = (y[j] - y[i])/(x[j] - x[i]);
        }
    }
    return 0;
}
