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
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    int n = a + b + 1;
    int cnt = 0;
    for (int i = n - a; i <= n; i++) {
        printf("%d", i);
        cnt++;
        if (cnt < n) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    for (int i = b; i >= 1; i--) {
        printf("%d", i);
        cnt++;
        if (cnt < n) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    return 0;
}
