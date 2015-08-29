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
    int64 n;
    int64 rowsum[128];
    int64 a[128][128];

    scanf("%I64d", &n);
    for (int i = 0; i < n; i++) {
        rowsum[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%I64d", &a[i][j]);
            rowsum[i] += a[i][j];
        }
    }
    // https://en.wikipedia.org/wiki/Magic_constant
    int64 target = n * (n * n + 1) / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                a[i][j] = target - rowsum[i];
            }
            printf("%I64d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
