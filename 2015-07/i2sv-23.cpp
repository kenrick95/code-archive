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
    int n, i = 0;
    scanf("%d", &n);
    int ans = 0;
    int arr[8] = {64, 32, 16, 8, 4, 2, 1};
    while (n > 0) {
        if (n >= arr[i]) {
            n -= arr[i];
            ans++;
        } else {
            i++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
