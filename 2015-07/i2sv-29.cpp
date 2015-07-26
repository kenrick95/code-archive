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
    int n;
    scanf("%d", &n);
    int idx = 0;
    char str[32];
    while (n > 0) {
        str[idx++] = ((n -1) % 26) + 'A';
        n = (n - 1) / 26;
        // printf("%d\n", n);
    }
    for (int i = idx - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
