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
    int T;
    int n, w, p[1024], diff, amt, max_profit;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &n, &w);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }
        max_profit = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // buy at i, sell at j
                diff = p[j] - p[i];
                amt = w / p[i];
                if (diff * amt > max_profit) {
                    max_profit = diff * amt;
                }
            }
        }
        printf("%d\n", max_profit);

    }
    return 0;
}
