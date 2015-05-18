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

int sav[110][4][300030];
    int n, m, a[128];
int f(int i, int cnt, int val) {
    if (sav[i][cnt][val] > -1) return sav[i][cnt][val];
    if (cnt == 3) return 0;
    if (i >= n) return -99999999;
    return sav[i][cnt][val] = max(f(i+1, cnt, val),
        (m >= val + a[i]) ?
            f(i+1, cnt + 1, val + a[i]) + a[i] : 0);
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(sav, -1, sizeof sav);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        printf("%d\n", f(0, 0, 0));
        /*for (int i = n-1; i >= 2; i--) {
            if (a[i] + a[i-1] + a[i-2] <= m) {
                printf("%d\n", a[i] + a[i-1] + a[i-2]);
                break;
            }
        }*/
    }
    return 0;
}
