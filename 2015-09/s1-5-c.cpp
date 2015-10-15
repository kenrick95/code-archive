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

// cur = 0: n
// cur = 1: m
int g(int n, int m, bool cur);
int f(int n, int m, bool cur) {
    if (n <= 0 && m <= 0) return 0;
    if (cur)
        return max(g(n - 1, m , cur) + 1, g(n, m, !cur));
    else
        return max(g(n, m - 1, cur) + 1, g(n, m, !cur));
}
int g(int n, int m, bool cur) {
    if (n <= 0 && m <= 0) return 0;
    if (cur)
        return max(f(n, m - 1, cur) + 1, f(n, m, !cur));
    else
        return max(f(n - 1, m, cur) + 1, f(n, m, !cur));
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int n,m;
    scanf("%d %d", &n, &m);
    printf("%d\n", max(f(n, m, 0), f(n, m, 1)));
    return 0;
}
