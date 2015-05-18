#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */

int64 diff[1000010], diff2[1000010], sav[1000010]; 

void f() {
    for (int i = 4; i <= 1000005; i++) {
        diff2[i] = diff2[i-1] + (i % 2);
        diff[i] = diff[i-1] + diff2[i-1];
        sav[i] = sav[i-1] + diff[i-1];
        //printf("%d | %d  | %d\n", sav[i], diff[i], diff2[i]);
    }
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    memset(sav, -1, sizeof sav);
    int n;
    diff2[3] = 1;
    diff[3] = 0;
    sav[3] = 0;
    f();
    while (scanf("%d", &n) != EOF) {
        if (n < 3) break;
        printf("%lld\n", sav[n+1]);
    }
    return 0;
}
