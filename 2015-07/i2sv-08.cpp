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
    int maxHeight, minWidth, totalHeight, totalWidth;
    scanf("%d %d %d %d", &maxHeight, &minWidth, &totalHeight, &totalWidth);
    int cw = 0, ch = 0, cnt = 0;
    for (int i = 1; i <= maxHeight; i++) {
        if (totalHeight % i == 0) {
            cw = totalHeight / i;
            for (int j = minWidth; j <= totalWidth; j++) {
                if (totalWidth % j == 0) {
                    ch = totalWidth / j;
                    if (cw == ch + 1) {
                        cnt++;
                    }
                }
            }    
        }
    }
    printf("%d\n", cnt);

    return 0;
}
