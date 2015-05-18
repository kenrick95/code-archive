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
    char s[128];
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'H') {
            printf("Hello, World!\n");
        } else if (s[i] == 'Q') {
            printf("%s\n", s);
        } else if (s[i] == '9') {
            for (int j = 99; j > 2; j--) {
                printf("%d bottles of beer on the wall,\n", j);
                printf("%d bottles of beer.\n", j);
                printf("Take one down, pass it around,\n");
                printf("%d bottles of beer on the wall.\n\n", j - 1);

            }
            printf("2 bottles of beer on the wall,\n");
            printf("2 bottles of beer.\n");
            printf("Take one down, pass it around,\n");
            printf("1 bottle of beer on the wall.\n\n");

            printf("1 bottle of beer on the wall,\n");
            printf("1 bottle of beer.\n");
            printf("Take one down, pass it around,\n");
            printf("No bottles of beer on the wall.\n");

        }
    }
    return 0;
}
