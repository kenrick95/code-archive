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

int sav[128][128], T;

int f(int a, int b) {
    //printf("%d %d %d\n", a, b, t);
    if (sav[a][b] > -1) return sav[a][b];
    if (a == 1) {
        sav[a][b] = 2 * b;
    } else if (a > 1 && b == 1) {
        sav[a][b] = 2;
    } else if (a > 1 && b > 1) {
        sav[a][b] = f(a-1, f(a, b-1));
    }
    //printf("%d %d %d: %d\n", a, b, t, sav[a][b]);
    return sav[a][b];
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int n, a,b;
    scanf("%d", &T);
    
    for (int  t = 1; t <= T; t++) {
        memset(sav, -1, sizeof sav);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &a, &b);
            printf("Case %d: %d\n", i, f(a,b) % n);
        }
        scanf("%d %d", &a, &b);
        //printf("[%d]\n", t);
        if (t < T) printf("\n");
    }
    return 0;
}
