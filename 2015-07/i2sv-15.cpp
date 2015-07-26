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
    int x[64], maxi = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        maxi = max(maxi, x[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d", (100 * x[i]) / maxi);
        if (i < n -1)
            printf(" ");
    }
    printf("\n");


    return 0;
}
