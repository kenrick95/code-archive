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
    scanf("%d", &n);
    double mini = 1.111; int idx = -1;
    char x[64];
    int cnt, ls, j;
    for (int i = 0; i < n; i++) {
        scanf("%s", x);
        j = 0; ls = 0; cnt = 0;
        while (*(x + j) != '\0') {
            ls++;
            if (*(x + j) == '1')
                cnt++;
            // printf("%c %d %d ----\n", *(x + j), ls, cnt);
            j++;
        }
        // // printf("%d\n", ls);
        // printf("%d %d %d %lf %d !!!!!\n", cnt, idx, ls, mini, ls);
        if (cnt < mini * ls) {
            mini = (double) cnt / (double) ls;
            idx = i;
        }
        // printf("%d %d %lf %d #####\n", cnt, idx, mini, ls);
        // printf("--------\n", cnt, idx, mini, ls);
    }
    printf("%d\n", idx);
    return 0;
}
