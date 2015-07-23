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
    int a, b, f, cnt = 0;
    scanf("%d %d %d", &a, &b, &f);
    for (int i = a; i <= b; i++) {
        if (i % f == 0)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
