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
 * @problem uva 10261
 * @url    http://uva.onlinejudge.org/external/102/p10261.pdf
 * @status  
 */

int T, L, x, a[1024], n, nextL, dp[102400];

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d", &T);
    bool br = false, gonext = false;
    nextL = 0;
    while (1) {
        L = nextL;
        gonext = false;
        n = 0;
        if (br)
            break;
        while(1) {
            scanf("%d", &x);

            if (x >= 100) {
                a[n++] = x;
                gonext = true;
            } else if (x > 0 && !gonext) {
                L = x * 100;
            } else if (x > 0 && gonext) {
                nextL = x * 100;
                break;
            } else if (x == 0) {
                br = true;
                break;
            }
        }
        
        memset(dp, 0, sizeof dp);
        for (int x = 0; x <= 100000; x++) {
            for (int i = 0; i < n; i++) {
                if (x >= a[i]) {
                    if (dp[x] < dp[x - a[i]] + 1) {
                        dp[x] = dp[x - a[i]] + 1;
                        //se[x] = se[x - a[i]];
                    }
                }
            }
        }
        printf("aaa %d\n", dp[L]);
    }
    return 0;
}
