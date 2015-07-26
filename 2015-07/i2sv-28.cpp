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

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    char str[64];
    int number = 0;
    char chr;
    fgets(str, 64, stdin);
    int ls = strlen(str);
    char newstr[64];
    int idx = 0;

    for (int i = 0; i < ls; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            number = number * 10 + (str[i] - '0');
            if (number > 50) {
                printf("TOO LONG\n");
                return 0;
            }
        } else if ('A' <= str[i] && str[i] <= 'Z') {
            if (idx + number > 50) {
                printf("TOO LONG\n");
                return 0;
            }
            if (number == 0) {
                newstr[idx] = str[i];
                idx++;

                if (idx > 50) {
                    printf("TOO LONG\n");
                    return 0;
                }
            } else {

                for (int j = idx; j < (idx + number); j++) {
                    newstr[j] = str[i];
                }
                idx += number;
                number = 0;    
            }
        }
    }
    newstr[idx] = '\0';
    printf("%s\n", newstr);


    return 0;
}
