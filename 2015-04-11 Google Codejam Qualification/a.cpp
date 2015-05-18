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
    int s;
    char a[1010];


    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d %s", &s, a);
        int ans = 0, sum = 0;
        for (int i = 0; i <= s; ++i)
        {
            if (a[i] == '0') continue;

            ans += max(i - sum, 0);
            // printf("[%d] %d\n", i, max(i - sum, 0));
            sum += a[i] - '0' + max(i - sum, 0);
        }
        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}
