#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
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
    int st, en, n, m, city, state, ans = -1;
    vector<int> route[512];
    map<int, bool> temp;
    int cost[512];
    scanf("%d %d %d", &st, &en, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cost[i], &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &city);
            route[i].push_back(city);
        }
    }
    // 1-city
    for (int i = 0; i < n; i++) {
        state = 0; // nope
        for (int j = 0; j < route[i].size(); j++) {
            city = route[i][j];
            if (city == st && state == 0) {
                state = 1; //still nope
            } else if (city == en && state == 1) {
                state = 2; // yea can!
                break;
            }
        }
        if (state == 2) {
            if (ans == -1) {
                ans = cost[i];
            } else {
                ans = min(ans, cost[i]);
            }
        }
    }
    // 2-city
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            // start from route[i] then switch to route[j]
            state = 0;
            // they must have a common city!
            temp.clear();
            
            for (int k = 0; k < route[i].size(); k++) {
                city = route[i][k];
                if (city == st && state == 0) {
                    state = 1; //still nope
                    // break;
                } else if (state == 1) {
                    temp[city] = true;
                }
            }
            for (int k = 0; k < route[j].size(); k++) {
                city = route[j][k];
                if (temp.count(city) >= 1) {
                    state = 3;
                }
                if (city == en && state == 3) {
                    state = 2; // yea can!
                    break;
                }
            }
            if (state == 2) {
                //printf("%d + %d\n", cost[i], cost[j]);
                if (ans == -1) {
                    ans = cost[i] + cost[j];
                } else {
                    ans = min(ans, cost[i] + cost[j]);
                }
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
