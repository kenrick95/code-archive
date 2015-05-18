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
    int n, k;
    scanf("%d %d", &n, &k);
    int pile[128][128], height[128];
    int maxi = -1, mini = 129;
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
        mini = min(mini, height[i]);
        maxi = max(maxi, height[i]);
    }
    int diff = maxi - mini;
    if (diff > k) {
        printf("NO\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pile[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < mini; j++) {
            pile[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = mini; j < height[i]; j++) {
            pile[i][j] = j - mini + 1;
        }
    }
    
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < height[i]; j++) {
            printf("%d", pile[i][j]);
            if (j != height[i] - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
