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
 * @url    http://acm.hust.edu.cn/vjudge/contest/view.action?cid=72242#problem/A
 * @status  AC
 */


short int dp[5005][5005];

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int len;
    char str[5005];
    memset(dp, 0, sizeof dp);

    //while (scanf("%d", &len) != EOF) {
        scanf("%d", &len);
        scanf("%s", str+1);

        
        // 1-based!!!!
        for (int i = len; i >= 1; i--) {
            for (int j = i + 1; j <= len; j++) {
                if (str[i] == str[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
            }
        }
        printf("%d\n", dp[1][len]);
    //}
    return 0;
}
