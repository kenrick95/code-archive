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
    int x = 0, y = 1, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        x = i;
        y += (i - 1);
        printf("%d %d\n", x, y);
    }
    return 0;
}
