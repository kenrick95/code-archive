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

/* Problem: Facebook Hacker Cup 2015 Qualification Round: Cooking the Books
 * URL: https://www.facebook.com/hackercup/problems.php?pid=582062045257424&round=742632349177460
 */


int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int t, T;
    int n, i, dig[32];
    int mini, pos_mini, pos_maxi, maxi,
        temp, len, last_dig;
    scanf("%d", &T);
    for (t = 0; t < T; t++) {
        scanf("%d", &n);
        if (n == 0) {
            printf("Case #%d: 0 0\n", t);
            continue;
        }
        mini = 10;
        pos_mini = -1;
        
        maxi = -1;
        pos_maxi = -1;

        temp = n;
        i = 0;
        do { // corner case: 3333313, and 11111131
            dig[i] = n % 10;
            if (dig[i] >= maxi && dig[i] != 0) {
                maxi = dig[i];
                pos_maxi = i;
            }
            if (dig[i] <= mini && dig[i] != 0) {
                mini = dig[i];
                pos_mini = i;
            }
            
            i++;
            n = n / 10;
        } while (n > 0);
        len = i;
        last_dig = dig[len - 1];
        printf("Case #%d: ", t);
        
        for (i = len - 1; i >= 0; i--) {
            if (i == pos_mini) {
                printf("%d", last_dig);
            } else if (i == len - 1) {
                printf("%d", mini);
            } else {
                printf("%d", dig[i]);
            }
        }
        printf(" ");
        for (i = len - 1; i >= 0; i--) {
            if (i == pos_maxi) {
                printf("%d", last_dig);
            } else if (i == len - 1) {
                printf("%d", maxi);
            } else {
                printf("%d", dig[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
