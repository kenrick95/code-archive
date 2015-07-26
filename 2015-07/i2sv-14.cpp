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
    int n;
    scanf("%d", &n);
    int x, y, totalEarned = 0, totalPossible = 0;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        totalEarned += x;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        totalPossible += x;
    }
    scanf("%d", &y); // max possible at final
    totalPossible += y;

    // get minimum (int) ans such that (totalEarned + ans) / totalPossible >= 65% AND ans <= y
    ans = ceil(totalPossible * .65) - totalEarned;

    // // recheck
    // if ((totalEarned + ans) * 100 >= 65 * totalPossible && ans <= y) {
    //     printf("%d\n", ans);
    // } else if (ans )

    if (ans > y)
        printf("-1\n");
    else if (ans <= 0)
        printf("0\n");
    else
        printf("%d\n", ans);
    return 0;
}
