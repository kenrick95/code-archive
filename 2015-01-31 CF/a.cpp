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
    int n;
    scanf("%d", &n);
    int a[16][16];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }
    printf("%d\n", a[n-1][n-1]);
    return 0;
}
