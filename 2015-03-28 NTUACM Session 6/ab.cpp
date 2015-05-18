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
 * @problem uva 847
 * @url    
 * @status  AC
 */


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int64 n, x, y, cnt;
    bool who = 0;
    while (scanf("%lld", &n) != EOF) {
        x = 1;
        who = 0; // 0: stan; 1: ollie
        while (x < n) {
            if (who) x *= 2;
            else x*= 9;
            
            who = !who;
        }
        if (who)
            printf("Stan wins.\n");
        else
            printf("Ollie wins.\n");
        
    }
    return 0;
}
