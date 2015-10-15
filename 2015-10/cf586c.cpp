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


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int64 n, v[5000], d[5000], p[5000];
    bool on[5000]; int64 vol; int64 chain_cry = 0; int64 cnt = 0;
    scanf("%I64d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d %I64d", &v[i], &d[i], &p[i]);
        on[i] = true;
    }
    for (int i = 0; i < n; i++) {
        if (on[i]) {
            cnt++;
            vol = v[i];
            chain_cry = 0;
            for (int j = i + 1; j < n; j++) {
                if (on[j]) {
                    p[j] -= (vol + chain_cry);
                    if (vol - 1 >= 0)
                        vol -= 1;

                    if (p[j] < 0) {
                        on[j] = false;
                        chain_cry += d[j];
                    }
                }
            }
        }
    }
    printf("%I64d\n", cnt);
    for (int i = 0; i < n; i++) {
        if (on[i])
            printf("%I64d ", i + 1);
    }

    return 0;
}
