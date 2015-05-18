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
 * @url    http://acm.hust.edu.cn/vjudge/contest/view.action?cid=72242#problem/A
 * @status  WA
 */

bool isPalin(char str[]) {
    bool ret = true;
    int len = strlen(str);
    for (int i = 0; i < (len / 2) + 1; i++) {
        if (str[i] != str[len - i -1]) {
            ret = false;
            break;
        }
    }
    return ret;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int L,R;
    int l;
    char str[5500];
    while (scanf("%d", &l) != EOF) {
        scanf("%s", str);
        //fgets (str , l , stdin);
        if (isPalin(str)) {
            printf("0\n");
            continue;
        }
        
        int lc, rc, ans = INF;
        // center = odd
        for (int c = 0; c < l; c++) {
            lc = rc = c;
            L = 0;
            R = l - 1;
            for (int i = 1; i < l; i++) {
                if (str[c - i] == str[c + i] && (c - i) >= 0 && (c + i) < l) {
                    lc--; rc++;
                } else {
                    break;
                }
            }
            for (int i = 0; i < l; i++) {
                if (str[i] == str[l-i-1] && L < lc && R > rc) {
                    L++;
                    R--;
                } else {
                    break;
                }
            }
            
            // LEFT = L .. lc-1
            // RIGHT  = rc+1 .. R
            // CENTER  = lc .. rc
            // [OUTLEFT] [LEFT] [CENTER] [RIGHT] [OUTRIGHT] ---> [OUTLEFT] inv(RIGHT) [LEFT] [CENTER] [RIGHT] inv(LEFT) [OUTRIGHT]
            ans = min(ans, lc - L + R - rc);
           // printf("[%d] %d %d %d %d| %d\n", c, lc, rc, L, R, lc - L + R - rc);
        }
        // center = even
        
        for (int c = 0; c < l - 1; c++) {
            if (str[c] != str[c + 1]) continue;
            lc = c; rc = c + 1;
            L = 0;
            R = l - 1;
            for (int i = 1; i < l; i++) {
                if (str[c - i] == str[c + i + 1] && (c - i) >= 0 && (c + i + 1) < l) {
                    lc--; rc++;
                } else {
                    break;
                }
            }
            for (int i = 0; i < l; i++) {
                if (str[i] == str[l-i-1] && L < lc && R > rc) {
                    L++;
                    R--;
                } else {
                    break;
                }
            }
            ans = min(ans, lc - L + R - rc);
            //printf("[%d] %d %d %d %d| %d\n", c, lc, rc, L, R, lc - L + R - rc);
        }
        printf("%d\n", ans);
    }
    return 0;
}
