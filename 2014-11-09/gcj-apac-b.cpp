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

int T, N, ar[5050], p, q, a,b;

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        memset(ar, 0, sizeof ar);
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &a, &b);
            for (int j = a; j <= b; j++) {
                ar[j]++;
            }
        }
        scanf("%d", &p);
        printf("Case #%d:", t);
        for (int i = 0; i < p; i++) {
            scanf("%d", &q);
            printf(" %d", ar[q]);
        }
        printf("\n");
    }
    return 0;
}
