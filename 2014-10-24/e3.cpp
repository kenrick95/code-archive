#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#include <set>
#define DEBUG printf("TEST\n")
#define HOLD scanf("%*c%*c")

using namespace std;

int N, K;

int dp[100001];

int f(int idx)
{
    if (dp[idx] > -1) return dp[idx];
    if (idx == N) {
         return dp[idx] = 1;
    } 
    dp[idx] = 0;
    for (int cur = N-1; cur >= idx + 2 ; cur--) {
        dp[idx] += f(cur) * min(cur -idx -1 , K );
    }
    dp[idx] += min(N -idx, K );
    return dp[idx];
    
}

int main()
{
    
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &N, &K);
    int ret = 1;
    for (int i = 0; i < N; i++) {
        ret += f(i);
    }
    printf("%d\n", ret);
    
     return 0;
}
