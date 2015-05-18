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

int p;
int prime[10000010];
bool isPrime[10000010];
int primacity[10000010];

void primegen() {
    memset(isPrime, true, sizeof isPrime);
    p = 0;
    for (int i = 2; i < 10000010; i++) {
        if (isPrime[i]) {
            prime[p++] = i;
            for (int j = 2; j < (10000010 / i); j++) {
                isPrime[i*j] = false;
            }
            primacity[i] = 1;
        }
    }
}

int pr(int i) {
    //        printf("%d %d\n", i, primacity[i]);
    if (i <= 1) return 0;
    if (primacity[i] > -1) return primacity[i];
    int cnt = 0, j = i;
    for (int x = 0; x < p; x++) {
        if (prime[x] > i) break;
        if (i % prime[x] == 0) {
            // printf("--> %d",cnt);
            cnt++;
            // printf("--> %d",cnt);
            do { j = j / prime[x]; } while (j % prime[x] == 0);
            // printf("%d\n", prime[x]);
            // printf("--> %d",cnt);
            cnt += pr(j);
            // printf("--> %d\n\n",cnt);
            break;
        }
    }
    return primacity[i] = cnt;
}
void pr_rev(int n, int res, int pr) {
    if (n == 1) {
        primacity[res] = pr;
        return;
    }
    for (int x = 0; x < p; x++) {
        pr_rev(n-1, res*prime[x], pr + (res % prime[x] == 0));
    }
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    for (int x = 1; x < 10000010; x++) primacity[x] = -1;
    primegen();
    for (int x = 0; x < p; x++) {
        for (int y = 0; y < p; y++) {
            if (prime[x]*prime[y] > 10000010) break;
            if (x!= y) primacity[prime[x]*prime[y]] = 2;
            else primacity[prime[x]*prime[y]] = 1;
            for (int z = 0; y < p; y++) {
                if (prime[x]*prime[y]*prime[z] > 10000010) break;
                if (x!= y && y != z && x!=z) primacity[prime[x]*prime[y]*prime[z]] = 3;
            }
        }
    }
    primacity[1] = 0;
    
    //printf("%d", p);
    int T;
    scanf("%d", &T);
    int a,b,k,cnt;
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &a, &b, &k);
        cnt = 0;
        if (k <= 10) {
            for (int i = a; i <= b; i++) {
                if (pr(i) == k) cnt++;
                //printf("%d\n", pr(i));
            }
        }
        printf("Case #%d: %d\n", t, cnt);
    }
    return 0;
}
