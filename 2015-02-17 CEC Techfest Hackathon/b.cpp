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
    char str[100100];
    while (scanf("%s", str) != EOF) {
        int len = strlen(str);
        int sum = 0;
        bool three = false;
        int posthree = -1;
        for (int i = 0; i < len; i++) {
            sum += str[i] - '0';
            if (str[i] == '0') {
                three = true;
                posthree = i;
            }
        }
        //printf("%d\n", sum);
        if (three && sum % 3 == 0) {
            sort(str, str + len);
            // find the zero put at back
            for (int i = len-1; i >= 0; i--) {
                //if (i != posthree)
                    printf("%c", str[i]);
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
