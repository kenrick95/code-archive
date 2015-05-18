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


int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    char str[128];
    int n;
    //scanf("%s", &str);
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) ans += i;
        printf("%d ", ans % 10);
    }
    return 0;
}
