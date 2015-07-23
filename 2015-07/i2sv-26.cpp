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
    int a[64];
    bool ma[1024];
    memset(ma, false, sizeof ma);

    vector<int> eligible;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (!ma[a[i]]) {
            eligible.push_back(a[i]);
            ma[a[i]] = true;
        }
    }
    if (n < 3 || eligible.size() < 3)
        printf("-1\n");
    else {
        sort(eligible.begin(), eligible.end());
        printf("%d\n", eligible[2]);
    }
    return 0;
}
