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
    int n, i, j, k, dig[32];
    int mini, pos_mini, pos_maxi, maxi,
        temp, len, first_dig;
    bool flag;
    scanf("%d", &T);
    for (t = 0; t < T; t++) {
        scanf("%d", &n);
        if (n == 0) {
            printf("Case #%d: 0 0\n", t + 1);
            continue;
        }
        mini = 2147483647;
        pos_mini = -1;
        
        maxi = -1;
        pos_maxi = -1;

        temp = n;
        i = 0;
        do { // corner case: 100010
            dig[i] = n % 10;
            i++;
            n = n / 10;
        } while (n > 0);
        len = i;
        first_dig = dig[len - 1];

        for (i = len - 1; i >= 0; i--)
        for (j = len - 1; j >= 0; j--) {
            // dig[i] swap with dig[j]
            temp = 0;
            flag = false;
            for (k = len - 1; k >= 0; k--) {
                temp *= 10;
                if (k == i) {
                    temp += dig[j];
                    if (k == len - 1 && dig[j] == 0) {
                        flag = true;
                        break;
                    }
                } else if (k == j) {
                    temp += dig[i];
                    if (k == len - 1 && dig[i] == 0) {
                        flag = true;
                        break;
                    }
                } else {
                    temp += dig[k];
                }
            }
            if (flag) {
                continue;
            }
            // printf("%d\n", temp);
            if (temp > maxi) {
                maxi = temp;
                pos_maxi = i;
            }
            if (temp < mini) {
                mini = temp;
                pos_mini = i;
            }
        }
        
        printf("Case #%d: %d %d\n", t + 1, mini, maxi);
    }
    return 0;
}
