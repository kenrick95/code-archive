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
    int n, a[4096], b[4096];
    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i < n; i++) {
            b[i-1] = abs(a[i] - a[i-1]);
        }
        sort(b, b+n-1);
        bool jolly = true;
        for (int i = 0; i < n-1; i++) {
            if (b[i] != i+1) {
                jolly = false;
                break;
            }
        }
        if (jolly) {
            printf("Jolly\n");
        } else {
            printf("Not jolly\n");
        }
    }
    return 0;
}
