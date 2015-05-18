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
    
    int n, a[50050], tr[50050];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            tr[i] = a[i] - i;
        }
        sort(tr, tr + n);
        int mode = tr[0], mode_cnt = 1, cnt = 1, tmp = tr[0];
        for (int i = 1; i < n; i++) {
            if (tr[i] == tmp) {
                cnt++;
            } else {
                if (mode_cnt < cnt) {
                    mode_cnt = cnt;
                    mode = tmp;
                }
                tmp = tr[i];
                cnt = 1;
            }
        }
        if (tr[0] == tr[n-1]) {
            mode_cnt = n;
            mode = tmp;
        }
        printf("%d\n", n - mode_cnt);
        for (int i = 0; i < n; i++) {
            printf("%d", mode++);
            if (i < n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
