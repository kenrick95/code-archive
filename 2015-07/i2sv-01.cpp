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
    int n, sa = 0, sb = 0;
    char x;
    scanf("%d", &n);
    scanf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &x);
            if (i == j) sa += x;
            if (n - i == j + 1) sb += x;
        }
        scanf("\n");
    }
    printf("%d\n", sa - sb);

    return 0;
}
