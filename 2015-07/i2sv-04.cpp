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
    scanf("%d\n", &n);
    char x[64];
    scanf("%s", x);
    int ans = 0;
    // number of "RL"
    for (int i = 0; i < n - 1; i++) {
        if (x[i] == 'R' && x[i + 1] == 'L')
            ans++;
    }
    printf("%d\n", ans);

    return 0;
}
