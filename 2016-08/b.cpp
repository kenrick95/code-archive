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
int pwr_mod(int a, int b, int m) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0) {
        int ret = pwr_mod(a, b / 2, m);
        return (ret * ret) % m;
    }
    return (a * pwr_mod(a, b - 1, m)) % m;
}
int f(int a, int b, int n, int k) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && (pwr_mod(i, a, k) + pwr_mod(j, b, k)) % k == 0) {
                    ans++;
                }
            }
    }
    return ans;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int a, b, n, k;
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d %d", &a, &b, &n, &k);
        printf("Case #%d: %d\n", i + 1, f(a, b, n, k));
    }
    return 0;
}
