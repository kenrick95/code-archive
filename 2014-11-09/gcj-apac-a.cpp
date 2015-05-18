#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
//#include <bits/stdc++.h>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */

int T, S, a[1024][1024], ans, maxidx;
int sav[1024][1024];

int f(int i, int j) {
    if (i < 0 || i >=S || j < 0 || j >= S) return 0;
    if (sav[i][j] > -1) return sav[i][j];
    
    if (a[i+1][j] == a[i][j] + 1) {
        return sav[i][j] = f(i+1, j) + 1;
    }
    if (a[i-1][j] == a[i][j] + 1) {
        return sav[i][j] = f(i-1, j) + 1;
    }
    if (a[i][j+1] == a[i][j] + 1) {
        return sav[i][j] = f(i, j+1) + 1;
    }
    if (a[i][j-1] == a[i][j] + 1) {
        return sav[i][j] = f(i, j-1) + 1;
    }
    return sav[i][j] = 1;
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &S);
        memset(sav, -1, sizeof sav);
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        ans = -1; maxidx = 0;
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                int temp = f(i,j);
                if (temp > ans) {
                    ans = temp;
                    maxidx = a[i][j];
                } else if (temp == ans && a[i][j] < maxidx) {
                    maxidx = a[i][j];
                }
                
            }
        }
        printf("Case #%d: %d %d\n", t, maxidx, ans);
    }
    return 0;
}
