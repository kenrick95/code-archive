
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
 * @problem uva10090
 * @url    
 * @status  AC
 */

/*
function extended_gcd(a, b)
    s := 0;    old_s := 1
    t := 1;    old_t := 0
    r := b;    old_r := a
    while r ≠ 0
        quotient := old_r div r
        (old_r, r) := (r, old_r - quotient * r)
        (old_s, s) := (s, old_s - quotient * s)
        (old_t, t) := (t, old_t - quotient * t)       
    output "Bézout coefficients:", (old_s, old_t)
    output "greatest common divisor:", old_r
    output "quotients by the gcd:", (t, s)
*/
void extended_gcd(int64 a, int64 b, int64 & s, int64 & t, int64 & g) {
    s = 0;      int64 old_s = 1;
    t = 1;      int64 old_t = 0; 
    int64 r = b;  int64 old_r = a;
    int64 prov;
    // printf("old_r: %d; r: %d; old_s: %d; old_t: %d; s: %d; t: %d\n", old_r, r, old_s, old_t, s, t);
    
    while (r != 0) {
        int quotient = old_r / r;
        prov = r;
        r = old_r - quotient * prov;
        old_r = prov;
        
        prov = s;
        s = old_s - quotient * prov;
        old_s = prov;
        
        prov = t;
        t = old_t - quotient * prov;
        old_t = prov;
        // printf("old_r: %d; r: %d; old_s: %d; old_t: %d; s: %d; t: %d\n", old_r, r, old_s, old_t, s, t);
    }
    g = old_r;
    s = old_s;
    t = old_t;
    //printf("s: %d; t: %d\n", s, t);
    //printf("gcd(%d, %d): %d\n", a, b, old_r);
    //printf("Bezout coefficients: %d %d\n", old_s, old_r);
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int64 s, t;
    int64 n, c1, n1, c2, n2;
    int64 k1, k2, mk1, mk2;
    int64 g, dummy;
    int64 mini, ctr1, ctr2;
    int64 sk1, sk2;

    //extended_gcd(1398, 324, s, t);
    //printf("%d %d\n", s, t);
    while (scanf("%lld", &n) != EOF) {
        if (n <= 0) break;
        scanf("%lld %lld", &c1, &n1);
        scanf("%lld %lld", &c2, &n2);
        
        // solving k1 * n1 + k2 * n2 = n
        // objective: min (k1 * c1 + k2 * c2)
        extended_gcd(n1, n2, s, t, g);
        // printf("%d %d %d \n", s, t, g);
        mk1 = s * (n / g);
        mk2 = t * (n / g);
        //printf("%d %d\n", mk1, mk2);
        
        // one
        ctr1 = ceil(-((mk1 * g * 1.) / (n2)));
        k1 = mk1 + ctr1 * (n2 / g);
        k2 = mk2 - ctr1 * (n1 / g);
        //printf("%lld: %lld %lld\n", ctr, k1, k2);
        mini = k1 * c1 + k2 * c2;
        sk1 = k1;
        sk2 = k2;
        // two
        ctr2 = floor ((mk2 * g * 1.) / (n1));
        k1 = mk1 + ctr2 * (n2 / g);
        k2 = mk2 - ctr2 * (n1 / g);
        //printf("%lld: %lld %lld\n", ctr, k1, k2);
        dummy  = k1 * c1 + k2 * c2;
        if (dummy < mini && k1 >=0 && k2 >= 0) {
            mini = dummy;
            sk1 = k1;
            sk2 = k2;
        }
        
        if (n % g != 0 || ctr1 > ctr2) {
            // no solution
            printf("failed\n");
            continue;
        }
        //ctr = 0;
        //k1 = mk1;
        //k2 = mk2;
        //// make k1 & k2 positive
        //while (k1 < 0 || k2 < 0) {
            //k1 = mk1 + ctr * (n2 / g);
            //k2 = mk2 - ctr * (n1 / g);
            //ctr++;
            ////printf("%d %d\n", k1, k2);
        //}
        //sk1 = k1;
        //sk2 = k2;
        //mini = k1 * c1 + k2 * c2;
        //while (k1 >=0 && k2 >= 0) {
            //k1 = mk1 + ctr * (n2 / g);
            //k2 = mk2 - ctr * (n1 / g);
            //ctr++;
            //dummy  = k1 * c1 + k2 * c2;
            ////printf("%d %d: %d %d\n", k1, k2, dummy, mini);
            //if (dummy < mini && k1 >=0 && k2 >= 0) {
                //mini = dummy;
                //sk1 = k1;
                //sk2 = k2;
            //}
        //}
        printf("%lld %lld\n", sk1, sk2);
    }
    
    return 0;
}
