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
    char st[64];
    scanf("%s", st);
    int ls = strlen(st);
    int sh;
    scanf("%d", &sh);
    char newst[64];
    for (int i = 0; i < ls; i++) {
        newst[i] = st[i] - sh;
        if (newst[i] < 'A') {
            newst[i] += 26;
        }
    }
    newst[ls] = '\0';
    printf("%s\n", newst);
    return 0;
}
