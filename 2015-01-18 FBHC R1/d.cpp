#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
//#include <bits/stdc++.h>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */

int n, mag[200200], T, depth[200200], val[200200];
bool leaf[200200], leafOnlyParent[200200], nonLeafOnlyParent[200200];

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d", &T);
    for (int t = 1; t<= T; t++) {
        scanf("%d", &n);
        memset(leaf, true, sizeof leaf);
        memset(leafOnlyParent, true, sizeof leafOnlyParent);
        memset(nonLeafOnlyParent, true, sizeof nonLeafOnlyParent);
        memset(val, 0, sizeof val);
        depth[0] = 0;
        // NOTE: 1-based!
        for(int i = 1; i <= n; i++) {
            scanf("%d", &mag[i]);
            leaf[mag[i]] = false;
            depth[i] = depth[mag[i]] + 1;
        }
        for (int i = 1; i <= n; i++) {
            if (leaf[i]) {
                val[i] = 1;
                nonLeafOnlyParent[mag[i]] = false;
            } else {
                leafOnlyParent[mag[i]] = false;
            } 
        }
        bool j = true;
        while (j) {
            for (int i = n; i >= 0; i--) {
                // if (val[mag[i]] == 0)
                    if (leafOnlyParent[mag[i]]) {
                        val[mag[i]] = 2;
                    } else if (nonLeafOnlyParent[mag[i]]) {
                        val[mag[i]] = (val[i] == 1) ? 2 : 1; //alternating
                    } else {
                        val[mag[i]] = max(val[mag[i]], val[i] + 1); 
                    }
            }
            j = false;
            for (int i = 1; i <= n; i++) {
                if (val[i] == 0) {
                    j = true;
                    break;
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            // printf("%d ", val[i]);
            ans += val[i];
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
