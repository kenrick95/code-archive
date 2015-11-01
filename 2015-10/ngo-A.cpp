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
    int T, n, h, a[100005];
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &n, &h);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            maxi = max(maxi, a[i]);
        }
        int minih = h * 2;
        for (int i = 0; i < n; i++) {
            if (maxi + a[i] >= h && maxi + a[i] < minih) {
                minih = maxi + a[i];
            }
        }
        printf("%d\n", minih);
    }
    return 0;
}
