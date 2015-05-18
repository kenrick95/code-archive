#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
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

bool p[10000];
int N, mod = 1000000009;

int f(int i, int k) {
    // printf("%d %d\n", i, k);
    if (100 <= k && k <= 1000) {

        // if (p[k]) printf("%d ", k);
        return p[k];
    }
    else if (k >= 100 || i >= N)
        return 0;
    int ret = f(i + 1, k) % mod;
    for (int d = 0; d <= 9; d++) {
        ret = (ret + f(i + 1, k * 10 + d)) % mod;
    }
    return ret;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    vector<int> prime;
    vector<int> tprime;
    memset(p, true, sizeof p);
    for (int i = 2; i <= 1000; i++) {
        if (p[i]) {
            prime.push_back(i);
            if (100 <= i && i <= 999)
                tprime.push_back(i);

            for (int j = 2; i * j <= 1000; j++) {
                p[i*j] = false;
            }
        }
    }

    scanf("%d", &N);
    int ans = 0;
    for (int i = 0; i <= 9; i++)
        ans = (ans + f(0, i)) % mod;
    printf("%d\n", ans);
    return 0;
}
