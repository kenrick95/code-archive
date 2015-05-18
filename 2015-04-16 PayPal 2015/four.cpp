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

int N, a[1024], sav[4096][8];
int ways(int val, int k) {
    // printf("%d %d %d\n", type, val, k);
    if (val == 0 && k == 0)
        return 1;
    else if (val <= 0 || k <= 0)
        return 0;
    else {
        if (sav[val][k] > -1)
            return sav[val][k];
        int ret = 0;
        for (int i = 0; i < N; i++) {
            ret += ways(val - a[i], k - 1);
        }
        return sav[val][k] = ret;
    }
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &a[i]);
    }
    // sort(a, a + N);
    int j = 0;
    memset(sav, -1, sizeof sav);
    for (int i = 1; i <= 4 * N; i++) {
        int ans = ways(i, 4);
        printf("%d", ans);
        if (i <= 4 * N)
            printf(" ");
        else
            printf("\n");
        j++;
    }
    return 0;
}
