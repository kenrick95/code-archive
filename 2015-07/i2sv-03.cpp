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
    int n;
    scanf("%d\n", &n);
    int i, j;
    char x[64][64];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%c", &x[i][j]);
            //printf("<%c>", x[i][j]);
        }
        scanf("\n");
    }
    int s[64];
    for (i = 0; i < n; i++) {
        s[i] = 0;
        // go hor
        for (j = 0; j < n; j++) {
            if (x[i][j] == 'W')
                s[i] += 3;
            else if (x[i][j] == 'D')
                s[i] += 1;
        }
        // go vert
        for (j = 0; j < n; j++) {
            if (x[j][i] == 'L')
                s[i] += 3;
            else if (x[j][i] == 'D')
                s[i] += 1;
        }
        printf("%d", s[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}
