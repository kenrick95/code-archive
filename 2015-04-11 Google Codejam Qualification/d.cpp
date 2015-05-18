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
 * @problem Problem D. Ominous Omino
 * @url     https://code.google.com/codejam/contest/6224486/dashboard#s=p3
 * @status  
 */


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T, R, C, X;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d %d %d", &X, &R, &C);
        bool richard = false;
        if ((R * C) % X != 0 || (X > R && X > C))
            richard = true;
        if ((X == 4 && ((R == 1 && C == 4) || (R == 4 && C == 1)))
            || (X == 4 && ((R == 2 && C == 4) || (R == 4 && C == 2)))
            || (X == 3 && ((R == 1 && C == 3) || (R == 3 && C == 1)))
            )
            richard = true;

        printf("Case #%d: ", t);
        if (richard)
            printf("RICHARD\n");
        else
            printf("GABRIEL\n");
    }
    return 0;
}
