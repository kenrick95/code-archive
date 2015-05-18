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
    int T, a, b;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &a, &b);
        int n = b - a;
        if (n == 0) printf("0\n");
        else {
            // odd
            int ans1 = ceil(2.0 * sqrt(n)) - 1;
            
            // even
            int ans2 = -1 + 2 * sqrt(n + .25);
            int ans = min(ans1, ans2) - 1;
            while (1) {
                //printf(">> %d\n", ans);
                if (ans % 2 == 1) {
                    //printf(">>>> %f\n", ((ans - 1) / 2. + 1)*((ans - 1) / 2. + 1));
                    if (((ans - 1) / 2. + 1)*((ans - 1) / 2. + 1) >= n)
                        break;
                    else
                        ans++;
                } else {
                    //printf(">>>> %f\n", ans * (ans / 2. + 1) / 2.);
                    if (ans * (ans / 2. + 1) / 2. >= n)
                        break;
                    else
                        ans++;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
