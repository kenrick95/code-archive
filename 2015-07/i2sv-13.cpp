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
    int n, a[128], mincur = 0, maxcur = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        mincur += max(0, (a[i] * 100 - 50));
        maxcur += min(10000, (a[i] * 100 + 49));
    }
    //printf("%d %d\n", mincur, maxcur);
    if (mincur > 10000 || maxcur < 10000)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
