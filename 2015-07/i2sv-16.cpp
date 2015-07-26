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

int numCrates, loadSize;
int f(int n) {
    if (n <= loadSize)
        return 1;
    else if (n % 2 == 0)
        return f(n / 2) + f(n / 2);
    else
        return f(n / 2) + f(n / 2 + 1);
}
int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d %d", &numCrates, &loadSize);
    printf("%d\n", f(numCrates));
    return 0;
}
