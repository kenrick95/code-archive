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
 * @problem Problem B. Infinite House of Pancakes
 * @url    
 * @status  
 */

int T, D, P[1010], sav[1010];

int f(int P[], int n) {
    // for (int i = 0; i < n; ++i) {
    //     printf("%d ", P[i]);
    // }
    // printf("\n");
    // if all P = 0, return
    bool allzero = true;
    int max_P = P[0], max_P_idx = 0;
    for (int i = 0; i < n; ++i)
    {
        if (P[i] != 0) {
            allzero = false;
            break;
        }
        if (P[i] > max_P) {
            max_P = P[i];
            max_P_idx = i;
        }
    }
    if (allzero)
        return 0;

    // normal hours
    int cP[n];
    for (int i = 0; i < n; ++i) {
        cP[i] = P[i];
        if (P[i]) P[i]--;
    }
    int ret = f(P, n) + 1;
    for (int i = 0; i < n; ++i) {
        P[i] = cP[i];
    }

    // special hours
    
    for (int i = 0; i < n; ++i) {
        P[i] = cP[i];
    }
    int bef = P[max_P_idx];
    if (bef > 1) {

        P[max_P_idx] = bef / 2;
        P[n] = bef - P[max_P_idx];

        // printf("##############\n");
        // for (int i = 0; i < n; ++i) {
        //     printf("%d ", cP[i]);
        // }
        // printf("\n");
        // for (int i = 0; i < n + 1; ++i) {
        //     printf("%d ", P[i]);
        // }
        // printf("\n");
        // printf("##############\n");
        ret = min(ret, f(P, n + 1) + 1);

        for (int i = 0; i < n; ++i) {
            P[i] = cP[i];
        }

    }
    return ret;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d", &T);
    int ans;
    memset(sav, -1, sizeof sav);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d", &D);
        for (int i = 0; i < D; i++) {
            scanf("%d", &P[i]);
        }
        ans = f(P, D);
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
