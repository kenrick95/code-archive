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
    char newst[64];
    for (int i = 0; i < ls / 2 + 1; i++) {
        if (st[i] != st[ls - i - 1]) {
            newst[i] = newst[ls - i - 1] = min(st[i], st[ls - i - 1]);
        } else {
            newst[i] = newst[ls - i - 1] = st[i];
        }
    }
    newst[ls] = '\0';
    printf("%s\n", newst);
    return 0;
}
