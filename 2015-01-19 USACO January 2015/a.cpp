#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */


int main(){
    freopen("cowroute.in","r",stdin);
    freopen("cowroute.out","w",stdout);
    int st, en, n, cost, m, city, state, ans = -1;
    scanf("%d %d %d", &st, &en, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cost, &m);
        state = 0; // nope
        for (int j = 0; j < m; j++) {
            scanf("%d", &city);
            //printf("[%d - %d] ", city, state);
            if (city == st && state == 0) {
                state = 1; //still nope
            } else if (city == en && state == 1) {
                state = 2; // yea can!
            }
        }
        if (state == 2) {
            if (ans == -1) {
                ans = cost;
            } else {
                ans = min(ans, cost);
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
