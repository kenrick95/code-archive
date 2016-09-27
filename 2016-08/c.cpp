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
int64 x[500001], y[500001];
pair<int64, int64> inv[500001];

int64 f(int64 n, int64 l1, int64 r1, int64 a, int64 b, int64 c1, int64 c2, int64 m) {
    int64 ans = 1000000007;
    
    inv[1] = make_pair(l1, r1);
    x[1] = l1; y[1] = r1;
    c1 = c1 % m; c2 = c2 % m;

    for (int i = 2; i <= n; i++) {
        x[i] = (((a * x[i - 1]) % m + (b * y[i - 1]) % m) % m + c1) % m;
        y[i] = (((a * y[i - 1]) % m + (b * x[i - 1]) % m) % m + c2) % m;
        inv[i] = make_pair(min(x[i], y[i]),  max(x[i], y[i]));
    }
    // printf("----------\n");
    sort(inv + 1, inv + n + 1);
    
    // for (int i = 1; i <= n; i++) {
    //     printf("%d: %lld %lld\n", i, inv[i].first, inv[i].second);
    // }
    for (int k = 1; k <= n; k++) {
        int64 max1 = -1, temp = 0;
           // printf("k = %d\n", k);

        for (int i = 1; i <= n; i++) {
            if (i == k)
                continue;

            if (inv[i].first > max1) { // separated
                temp += inv[i].second - inv[i].first + 1;
            } else {
                if (inv[i].second > max1) { // cut
                    temp += inv[i].second - max1;
                } else { // wholly inside
                    temp += 0;
                }
            }
            max1 = max(max1, inv[i].second);
            // printf("%lld %lld --> %lld\n", inv[i].first, inv[i].second, temp);
        }
            // printf("----------\n");
    
        ans = min(ans, temp);
    }

    return ans;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int64 n, l1, r1, a, b, c1, c2, m;
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &n, &l1, &r1, &a, &b, &c1, &c2, &m);
        printf("Case #%d: %lld\n", i + 1, f(n, l1, r1, a, b, c1, c2, m));
    }
    return 0;
}
