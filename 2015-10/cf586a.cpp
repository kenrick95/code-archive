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
    int n, a[500], start = -1, ans = 0;
    scanf("%d", &n);

    for (int i = 0; i < n + 10; i++) {
        a[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        //printf("%d ", ans);
        if (start < 0 && a[i]) {
            start = i;
        }
        if (start >= 0 && !a[i] && !a[i + 1]) {
            ans += (i - 1) - start + 1;
            start = -1;
        }
    }
    if (start >= 0) {
        ans += (n - 1) - start + 1;
        start = -1;
    }
    printf("%d\n", ans);

    return 0;
}
