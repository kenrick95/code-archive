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
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int n, h[128], p, T, haz = 0; bool canhaz = false;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d", &n);
        scanf("%d", &p);
        for (int i = 0; i < p; i++) {
            scanf("%d", &h[i]);
        }
        haz = 0;
        
        for (int i = 0; i < n; i++) {
            if (i % 7 == 5 || i % 7 == 6) continue;
            canhaz = false;
            for (int j = 0; j < p; j++) {
                if (i % h[j] == h[j] - 1) {
                    canhaz = true;
                    break;
                }
            }
            if (canhaz) haz++;
        };
        printf("%d\n", haz);
    }
    
    return 0;
}
