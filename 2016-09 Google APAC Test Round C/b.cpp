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
int T;
int R, C, K;

int ma[3001][3001];

int f(int r, int c, int s) {
    if (s == 1)
        return (int)(ma[r][c] == 0);

    bool can = true;
    for (int i = r; i < r + s; i++) {
        for (int j = c; j < c + s; j++) {
            if (ma[i][j] == 1) {
                can = false;
                break;
            }
        }
        if (!can)
            break;
    }
    return (int)can;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int r, c;
        scanf("%d %d %d", &R, &C, &K);
        memset(ma, 0, sizeof ma);
        for (int i = 0; i < K; i++) {
            scanf("%d %d", &r, &c);
            ma[r][c] = 1;
        }
        // for (int i = 0; i < R; i++) {
        //     for (int j = 0; j < C; j++) {
        //         printf("%d", ma[i][j]);
        //     }
        //     printf("\n");
        // }
        int ans = 0; int tmp = 0;
        for (int s = 1; s <= min(R, C); s++) {
            // printf("----- %d\n", s);
            for (int i = 0; i <= R - s; i++) {
                for (int j = 0; j <= C - s; j++) {
                    tmp = f(i, j, s);
                    // if (tmp == 1)
                    //     printf("%d %d %d: %d\n", i, j, s, tmp);
                    ans += tmp;
                }
            }
        }
        printf("Case #%d: %d\n", t + 1, ans);
    }
    return 0;
}
