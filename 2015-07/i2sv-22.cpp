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
    int poles[64], total = 0, average;
    int n;
bool same_height() {
        for (int i = 0; i < n - 1; i++) {
            if (poles[i] != poles[i + 1])
                return false;
        }
        return true;
    }
int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &poles[i]);
        total += poles[i];
    }
    average = total / n;
    int cnt = 0;
    while (!same_height()) {
        sort(poles, poles + n);
        int cut = poles[n - 1] - average;
        poles[n - 1] = average;
        poles[0] += cut;
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
