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
    int a, b, cnt = 0;
    scanf("%d %d", &a, &b);
    int xa = 1, xb = 1, xc = 2;
    while (xa < 1024) {
        if (a <= xa && xa <= b)
            cnt++;
        xc = xa + xb;
        xa = xb;
        xb = xc;
    }
    printf("%d\n", cnt);
    return 0;
}
