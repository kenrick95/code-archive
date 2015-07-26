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
    int a[1024], b[1024]; bool mb[1024];
    memset(mb, false, sizeof mb);
    int cnt = n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        // find a[i]'s pair at b
        // mark b[j] at mb[j]
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j] && !mb[j]) {
                mb[j] = true;
                cnt--;
                break;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
