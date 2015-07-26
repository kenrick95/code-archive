#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
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

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int hp, num, att;
    int n;
    scanf("%d %d %d %d", &n, &hp, &att, &num);
    int rnd = 0;
    int enemy = hp * num;
    while (enemy > 0) {
        rnd++;

        // attack enemy
        enemy -= n;

        // enemy attacks
        n -= ceil((double) enemy / (double) hp) * att;
        if (enemy > 0 && n <= 0) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", rnd);


    return 0;
}
