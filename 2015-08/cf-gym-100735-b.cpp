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
int64 n, m, MOD = 1000000009, c;
int64 F[32];
int64 k[32];
struct mat
{
    int64 v[32][32];
    int r, c;
    mat() {
        r = 32;
        c = 32;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                v[i][j] = 0;
    }
    void print() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                printf("%I64d ", v[i][j]);
            printf("\n");
        }
    }
    mat operator * (mat A) {
        mat ret;
        ret.r = r;
        ret.c = A.c;
        int64 tem = 0;
        for (int i = 0; i < ret.r; i++) {
            for (int j = 0; j < ret.c; j++) {
                tem = 0;
                for (int k = 0; k < c; k++) {
                    tem = (tem + (v[i][k] * A.v[k][j]) % MOD) % MOD;
                }
                ret.v[i][j] = tem;
                // printf("[%d][%d]: %d\n", i, j, tem);
            }
        }
        return ret;
    }
    mat power(int64 n) {
        mat ret;
        ret.r = r; ret.c = c;
        if (n <= 1) {
            for (int i = 0; i < ret.r; i++) {
                for (int j = 0; j < ret.c; j++) {
                    ret.v[i][j] = v[i][j];
                }
            }
            return ret;
        }
        if (n % 2 == 0) {
            mat ret = power(n / 2);
            return ret * ret;
        } else {
            for (int i = 0; i < ret.r; i++) {
                for (int j = 0; j < ret.c; j++) {
                    ret.v[i][j] = v[i][j];
                }
            }
            return ret * power(n - 1);
        }
    }
};

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%I64d %I64d %I64d", &n, &m, &c);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &F[i]);
    }
    for (int i = 0; i < c; i++) {
        scanf("%I64d", &k[i]);
    }
    if (m <= n) {
        printf("%I64d\n", F[m - 1]);
        return 0;
    }

    mat ma;
    ma.r = n;
    ma.c = n;
    for (int i = 0; i < c; i++) {
        ma.v[0][k[i] - 1]++;
    }
    for (int i = 1; i < n; i++) {
        ma.v[i][i - 1] = 1;
    }
    // ma.print();
    // printf("\n");
    
    mat val;
    val.r = n;
    val.c = 1;
    for (int i = n - 1; i >= 0; i--) {
        val.v[i][0] = F[n - i - 1];
    }
    // val.print();
    // printf("\n");

    mat powered = ma.power(m - n);
    // powered.print();
    // printf("\n");
    mat res = powered * val;
    // res.print();
    // printf("\n");

    printf("%I64d\n", res.v[0][0]);

    return 0;
}
