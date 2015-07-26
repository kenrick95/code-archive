#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
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
int sav[1000100];

int f(int n, int k) {
    // printf("%d\n", n);
    if (n == 1)
        return 1;
    if (sav[n] > -1)
        return sav[n];
    int temp = 0, left = 0, right = 0;
    for (int i = 1; i < n / 2 + 1; i++) {
        left = f(n - i, k);
        right = f(i, k);
        if (abs(left - right) <= k) {
            temp = max(temp, 1 + max(left, right));
        }
    }
    return sav[n] = temp;
}


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int k, n;
    scanf("%d %d", &k, &n);
    // for (int j = 1; j <= 100; j++) {
    //     memset(sav, -1, sizeof sav);
    //     for (int i = 1; i < 1000; i++) {
    //         printf("%d ", f(i, j));
    //     }
    //     printf("\n");
    // }
    // return 0;
    //printf("%d\n", f(n, k));

    if (n <= k)
        printf("%d\n", n);
    else {
        // n -= k;
        // int c = k + 1, d = 0, e = 1;
        // for (int i = 1; i <= n; i++) {
        //     sav[i] = c;
        //     d++;
        //     if (d >= e) {
        //         c++; e++;
        //         d = 0;
        //     }
        //     printf("%d; ", sav[i]);
        // }
        // printf("%d\n", sav[n]);
        
    }

    return 0;
}
