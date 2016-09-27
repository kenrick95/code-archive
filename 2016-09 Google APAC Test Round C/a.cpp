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
int R, C;
int Rs, Cs, S;
double P, Q;
char ma[32][32];
double get_prob(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) {
        return 0;
    }
    if (ma[r][c] == 'A') {
        return P;
    } else {
        return Q;
    }
}
double f(int r, int c, int s) {
    if (r < 0 || r >= R || c < 0 || c >= C || s > S) {
        return 0;
    }

    double max_ret = 0;
    double prob = 0;
    prob = get_prob(r + 1, c); max_ret = max(max_ret, prob * f(r + 1, c, s + 1) + (1. - prob) * f(r + 1, c, s + 1));
    prob = get_prob(r - 1, c); max_ret = max(max_ret, prob * f(r - 1, c, s + 1) + (1. - prob) * f(r - 1, c, s + 1));
    prob = get_prob(r, c + 1); max_ret = max(max_ret, prob * f(r, c + 1, s + 1) + (1. - prob) * f(r, c + 1, s + 1));
    prob = get_prob(r, c - 1); max_ret = max(max_ret, prob * f(r, c - 1, s + 1) + (1. - prob) * f(r, c - 1, s + 1));
    
    return max_ret;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d %d %d %d", &R, &C, &Rs, &Cs, &S);
        scanf("%lf %lf", &P, &Q);
        memset(ma, 0, sizeof ma);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%c", ma[i][j]);
                if (j != C - 1)
                    scanf(" ");
                else
                    scanf("\n");
            }
        }

        f(0, 0, 0);

    }
    return 0;
}
