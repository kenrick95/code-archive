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

int d[16], m[16], o[16];
int n, k;
char p[32][4];

bool f(int d, int m, int o, int i) {
    if (i >= k) return false;
    if (d == 0 && m == 0 && o == 0) {
        return true;
    }
    bool ans = false;
    ans |= f(d, m, o, i+1);
    for (int l = 0; l < strlen(p[i]); l++) {
        if (p[i][l] == 'D' && d > 0) { ans |= f(d-1, m, o, i+1); }
        if (p[i][l] == 'M' && m > 0) { ans |= f(d, m-1, o, i+1); }
        if (p[i][l] == 'O' && o > 0) { ans |= f(d, m, o-1, i+1); }
    }
    return ans;
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d-%d-%d", &d[i], &m[i], &o[i]);
        }
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%s", p[i]);
        }
        bool ans = false;
        for (int i = 0; i < n; i++) {
            ans = f(d[i], m[i], o[i], 0);
            if (ans) {
                printf("YAY\n");
            } else {
                printf("NAY\n");
            }
            //printf("%d", ans);
        }
    }
    return 0;
}
