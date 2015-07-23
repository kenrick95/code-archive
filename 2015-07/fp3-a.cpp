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
 * @problem A - MODEX
 * @url     http://acm.hust.edu.cn/vjudge/contest/view.action?cid=82048#problem/A
 * @status  
 */

int f(int x, int y, int m) {
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    if (y % 2 == 0) {
        int temp = f(x, y / 2, m) % m;
        return (temp * temp) % m;
    } else {
        return (f(x, y - 1, m) * x) % m;
    }
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int x, y, m, T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d %d", &x, &y, &m);
        printf("%d\n", f(x, y, m));
    }
    scanf("%d", &T);
    return 0;
}
