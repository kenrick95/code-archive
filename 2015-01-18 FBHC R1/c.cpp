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

int savf[2020][2020];
int savg[2020][2020];

int f(int m, int t) {
    if (t < 0 || m < 0) return 0;
    if (m-1 == 0 && t == 0) return 1;
    if (savf[m][t] > -1) return savf[m][t];
    int &ret = savf[m][t] = 0;
    if (m-1 > t) ret = (ret + f(m-1, t)) % 1000000007;
    ret = (ret + f(m, t-1)) % 1000000007;
    return ret;
}
int g(int m, int t) {
    if (t < 0 || m < 0) return 0;
    if (m == 0 && t == 1) return 1;
    if (savg[m][t] > -1) return savg[m][t];
    int &ret = savg[m][t] = 0;
    ret = (ret + g(m-1, t)) % 1000000007;
    if (m <= t-1) ret = (ret + g(m, t-1)) % 1000000007;
    return ret;
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    memset(savf, -1, sizeof savf);
    memset(savg, -1, sizeof savg);
    
    int T;
    scanf("%d", &T);
    int a,b;
    for (int t = 1; t <= T; t++) {
        scanf("%d-%d", &a, &b);
        printf("Case #%d: %d %d\n", t, f(a, b), g(b, b));
    }
    return 0;
}
