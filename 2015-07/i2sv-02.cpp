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


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    // 
    int i, j, a = 0; char x;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            scanf("%c", &x);
            //printf("%d %d\n", x, i + j) % 2);
            if (x == 'F' && (i + j) % 2 == 0)
                a++;
        }
        scanf("\n");
    }
    printf("%d\n", a);

    return 0;
}
