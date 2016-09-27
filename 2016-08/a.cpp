#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
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

int64 f(int64 i) {
    return (i * (i + 1)) / 2;
}


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int64 l, r;
        scanf("%lld %lld" , &l, &r);
        printf("Case #%d: %lld\n", i + 1, f(min(l, r)));
    }
    return 0;
}
