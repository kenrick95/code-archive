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
    int used[64], total[64], totalUsed = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &used[i]);
        totalUsed += used[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &total[i]);
    }
    sort(total, total + n);
    int cnt = 0;
    for (int i = n - 1; i >= 0 ; i--) {
        totalUsed -= total[i];
        cnt++;
        if (totalUsed <= 0)
            break;
    }
    printf("%d\n", cnt);
    return 0;
}
