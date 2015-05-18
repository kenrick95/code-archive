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
    int T;
    scanf("%d", &T);
    int xa, ya, xb, yb, x1, x2, y1, y2;
    int ans = 0;
    for (int t = 0; t < T; t++) {
        scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
        x1 = min(xa, xb);
        x2 = max(xa, xb);
        y1 = min(ya, yb);
        y2 = max(ya, yb);

        if (x2 <= y1) {
            // printf("A\n");
            ans = max(x2 - x1 - 1, 0) * max(0, y2 - y1 - 1);
        } else if (x1 >= y2) {
            //printf("B\n"); 
            ans = max(x2 - x1 - 1, 0) * max(0, y2 - y1 - 1);
        } else {
            // printf("C\n"); 
            ans = 0;
            for (int i = 0; i < y2 - y1 - 1; i++)
                ans += max(y1 + i - x1, 0);
            
            // printf("%d\n", ans);
            for (int i = 0; i < x2 - x1 - 1; i++)
                ans += max(x1 + i - y1, 0);
            
        }
        printf("%d\n", ans);
    }
    return 0;
}
