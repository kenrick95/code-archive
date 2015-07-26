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
    int st[1024];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &st[i]);
    }
    sort(st, st + n);

    int team[2] = {0, 0};
    int idx = 0;
    for (int i = n - 1; i >= 0; i--) {
        // printf("%d %d %d\n", idx, i, st[i]);
        team[idx++] += st[i];
        
        idx %= 2;

    }
    printf("%d\n", abs(team[0] - team[1]));

    return 0;
}
