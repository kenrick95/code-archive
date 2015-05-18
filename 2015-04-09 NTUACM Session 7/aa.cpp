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

bool car(int n) {
    if (n % 2 == 0)
        return false;

    bool prime = true;
    // square-free
    for (int i = 3; i < sqrt(n) + 1; i += 2) {
        if (n % (i*i) == 0) {
            // printf("%d\n", i);
            return false;
        }
        if (n % i == 0)
            prime = false;
    }
    if (prime)
        return false;

    int temp = n;
    // for all prime divisors p of n
    // (n - 1) % (p - 1) == 0
    for (int i = 3; i < n; i += 2) {
        int p = i;
        if (temp < i)
            break;
        if (temp % p == 0) {
            // printf("%d %d\n", temp, p);
            // p is prime divisor
            if ((n - 1) % (p - 1) != 0) {
                return false;
            }
            while (temp % p == 0)
                temp = temp / p;
        }
    }
    return true;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        if (car(n))
            printf("The number %d is a Carmichael number.\n", n);
        else
            printf("%d is normal.\n", n);
    }
    return 0;
}
