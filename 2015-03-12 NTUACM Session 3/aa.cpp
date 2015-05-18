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


int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int T;
    int n;
    int a[512];
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d", &n);
        if (n == 0) {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int ans = 100000007;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            // try Vito's home at a[i]
            temp = 0;
            for (int j = 0; j < n; j++)
                temp += abs(a[j] - a[i]);
            ans = min(ans, temp);
        }
        
        printf("%d\n", ans);
    }
    return 0;
}
