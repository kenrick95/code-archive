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


int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int t, T, i;
    char st[256][256];
    scanf("%d", &T);
    i = 0;
    fgets (st[i] , 100 , stdin);
    fgets (st[i] , 100 , stdin);
    for (int t = 0; t < T; t++) {
        i = 0;
        while (1) {
            fgets (st[i] , 100 , stdin);
            if (st[i][0] == '\n' || feof(stdin)) {
                break;
            }
            i++;
        }
    }
    return 0;
}
