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
    int n, a, b, c;
    char str[255];
    scanf("%d %d %d", &n, &a, &b);
    c = n - a - b;
    if (c < 0) {
        printf("-1\n");
        return 0;
    }
    scanf("%s", str);
    int len = strlen(str), xa = 0, xb = 0, xc = 0;
    for (int i =0; i < len; i++) {
        xa += (str[i] == '0');
        xb += (str[i] == '1');
        xc += (str[i] == '2');
    }
    int ans = 0;//, limit = abs(xa - a) + abs(xb - b) + abs(xc - c);
    int op[6]; // 6 type of (-1 & +1)
    for (int i = 0; i < 6; i++) op[i] = 0;
    //printf("%d %d %d\n", xa, xb, xc);
    while (ans <= n) {
        //printf("%d %d %d\n", xa, xb, xc);
        /* '1' -> '0' */ if (xa < a && xb > b) { op[0]++; ans++; xa++; xb--; }
        /* '2' -> '0' */ if (xa < a && xc > c) { op[1]++; ans++; xa++; xc--; }
        /* '0' -> '1' */ if (xb < b && xa > a) { op[2]++; ans++; xb++; xa--; }
        /* '2' -> '1' */ if (xb < b && xc > c) { op[3]++; ans++; xb++; xc--; }
        /* '0' -> '2' */ if (xc < c && xa > a) { op[4]++; ans++; xc++; xa--; }
        /* '1' -> '2' */ if (xc < c && xb > b) { op[5]++; ans++; xc++; xb--; }
        if (xa == a && xb == b && xc == c) break;
    }
    //for (int i = 0; i < 6; i++) printf("%d ", op[i]);
    //printf("\n%d %d %d\n", xa, xb, xc);
    for (int i = 0; i < len; i++) {
        if (str[i] == '0') { //a
            if (op[2] > 0) { str[i] = '1'; op[2]--; }
            else if (op[4] > 0) { str[i] = '2'; op[4]--; }
        } else if (str[i] == '1') { //b
            if (op[0] > 0) { str[i] = '0'; op[0]--; }
            else if (op[5] > 0) { str[i] = '2'; op[5]--; }
        } else { //'2' c
            if (op[1] > 0) { str[i] = '0'; op[1]--; }
            else if (op[3] > 0) { str[i] = '1'; op[3]--; }
        }
    }
    printf("%d\n", ans);
    printf("%s\n", str);
    return 0;
}
