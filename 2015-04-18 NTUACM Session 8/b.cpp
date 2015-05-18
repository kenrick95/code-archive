#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
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

int64 N;
int64 ans = 0;
vector<int> prime;
// map<int, bool> np;
bool p[10000000];

bool isprime(int64 n) {
    if (n <= 10000000)
        return p[n];
    else {
        if (n % 2 == 0)
            return false;
        int x = 3, y = sqrt(n) + 1;
        while (x < y) {
            if (n % x == 0)
                return false;
            x += 2;
        }
        return true;
    }
}
int isqrt(int n) {
    return (int) sqrt(n);
}
bool PerfectSquare(int n)
{
    int h = n & 0xF; // last hexadecimal "digit"
    if (h > 9)
        return 0; // return immediately in 6 cases out of 16.

    // Take advantage of Boolean short-circuit evaluation
    if ( h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8 )
    {
        // take square root if you must
        int t = (int) floor( sqrt((double) n) + 0.5 );
            return t*t == n;
    }
    return 0;
}
int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    memset(p, true, sizeof p);
    for (int i = 3; i < 10000000; i += 2) {
        if (p[i]) {
            prime.push_back(i);

            for (int j = 2; i * j < 10000000; j++) {
                p[i*j] = false;
            }
        }
    }
    scanf("%lld", &N);
    // printf("%d\n", prime.size());
    if (isprime(N)) {
        ans = 1;
    } else {
        // int i = 0 ;
        // int64 sq = sqrt(N) + 1;
        // while ((ans == 0) && (prime[i] < sq) && i < prime.size()) {
        //    if ((N % prime[i]) == 0)
        //      ans = N / prime[i] ;
        //    i += 1 ;
        // }

        // too large :'(
        int x = 3, y = sqrt(N) + 1;
        while (x < y) {
            if (N % x == 0 && (PerfectSquare(N / x) || isprime(N / x))) {
                ans = N / x;
                break;
            }
            x += 2;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
