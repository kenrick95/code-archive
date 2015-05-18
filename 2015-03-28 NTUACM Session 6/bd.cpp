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
 * @problem uva 10870
 * @url    
 * @status  AC
 */
 
struct matx{
   int64 i[32][32];
};
 
int64 i, d, n, md;
int64 f[32], a[32];
/*
 * [f1 f2 f3 f4 .... fd] [0 0 ... a< d >]^n = [f<n-d+1> ... f<n-1> f<n>]
 *                       [1 0 ... a<d-1>]
 *                       [0 1 ... a<d-2>]
 *                       [. .     . ]
 *                       [.   .   . ]
 *                       [.     . . ]
 *                       [.      .a1]
 * */
matx Mult(matx ma, matx mb) {
    matx mt;
    for (int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            mt.i[i][j] = 0;
            for (int k = 0; k < d; k++) {
                mt.i[i][j] += (ma.i[i][k] * mb.i[k][j]) % md;
            }
            mt.i[i][j] %= md;
        }
    }
    return mt;
}
matx Pow(matx ma, int64 p) {
    matx mt;
    if (p == 1) {
        mt = ma;
        return mt;
    } else if (p == 0){ // zero matrix; nonexist?
        for (int i = 0; i < d; i++)
            for (int j = 0; j < d; j++)
                mt.i[i][j] = 0;
        return mt;
    }
    if (p % 2 == 0) {
        mt = Pow(ma, p / 2);
        mt = Mult(mt, mt);
    } else {
        mt = Mult(Pow(ma, p - 1), ma);
    }
   return mt;
}
void debug(matx ma) {
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++)
            cout << ma.i[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    while (scanf("%lld %lld %lld", &d, &n, &md) != EOF) {
        if (d == 0 && n == 0 & md == 0) break;
        for (int i = 0; i < d; i++) scanf("%lld", &a[i]);
        for (int i = 0; i < d; i++) scanf("%lld", &f[i]);
        
        if (n <= d) {
            printf("%lld\n", f[n - 1]);
            continue;
        }
        n -= d;
        
        matx init;
        for (int j = 0; j < d; j++)
            init.i[0][j] = f[j];
        
        for (int i = 1; i < d; i++)
            for (int j = 0; j < d; j++)
                init.i[i][j] = 0;
        
        // debug(init);
        
        matx multiplier;
        for (int i = 0; i < d; i++)
            for (int j = 0; j < d; j++)
                multiplier.i[i][j] = (i - 1 == j) ? 1 : 0;
        for (int i = 0; i < d; i++)
            multiplier.i[i][d - 1] = a[d - i - 1];
        
        // debug(multiplier);
        matx powered = Pow(multiplier, n);
        // debug(powered);
        matx res = Mult(init, powered);
        // debug(res);
        printf("%lld\n", res.i[0][d - 1]);
    }
}
