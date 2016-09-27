#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
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

int n;
int a[100010];

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int64 max_xor = 0;
    int64 tmp1 = 0, tmp2 = 0, tmp3 = 0;
    for (int i = -1; i < n; i++) {
        if (i >= 0)
            tmp1 ^= a[i];
        tmp2 = 0;
        // printf("tmp1: %lld\n", tmp1);
        for (int j = n; j > i; j--) {
            if (j < n)
                tmp2 ^= a[j];
            // printf("tmp2: %lld\n", tmp2);
            tmp3 = tmp1 ^ tmp2;
            // printf("tmp3: %lld\n", tmp3);
            if (tmp3 > max_xor) {
                max_xor = tmp3;
            }
        }
        
    }
    printf("%lld\n", max_xor);

    return 0;
}