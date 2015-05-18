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

/* Problem: Facebook Hacker Cup 2015 Qualification Round: New Year's Resolution
 * URL: https://www.facebook.com/hackercup/problems.php?pid=1036037553088752&round=742632349177460
 */

int t, T;
int n, i, p[32], c[32], f[32];
int gp, gc, gf;

bool fn(int gp, int gc, int gf) {
    int tgp, tgc, tgf;
    for (int i = 0; i < 2 << n; i++) {
        tgp = gp; tgc = gc; tgf = gf;
        for (int j = 0; j < n; j++) {
            if (!!(i & (1 << j))) {
                tgp -= p[j];
                tgc -= c[j];
                tgf -= f[j];
            }
        }
        if (tgp == 0 && tgc == 0 && tgf == 0) return true;
    }
    return false;
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d", &T);
    for (t = 0; t < T; t++) {
        scanf("%d %d %d", &gp, &gc, &gf);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &p[i], &c[i], &f[i]);
        }
        printf("Case #%d: %s\n", t + 1, fn(gp, gc, gf) ? "yes" : "no");
    }
    return 0;
}
