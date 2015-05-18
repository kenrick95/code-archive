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

double f(int a, int b) {
    printf("%d %d: \n", a, b);
    if (a == 0)
        return 0.0;
    else if (b == 0)
        return 1.0;
    else {
        int c = min(a, b);
        double ret = 0.5 * f(a - c, b + c) + 0.5 *f(a + c, b - c);
        printf("%d %d: %lf\n", a, b, ret);
        return ret;

    }
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int a, b, T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d %d", &a, &b);
        printf("Case %d: %lf\n", f(a,b));
    }
    return 0;
}
