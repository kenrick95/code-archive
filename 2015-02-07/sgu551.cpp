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
    int n, ti, t1, t2, start1 = 0, start2 = 0, finish1 = 0, finish2 = 0;
    scanf("%d %d %d", &n, &t1, &t2);
    for (ti = 0;;ti++) {
        if (ti % t1 == 0) {
            if (start1 > finish1) finish1++;
        }
        if (ti % t2 == 0) {
            if (start2 > finish2) finish2++;
        }
        if (ti % t1 == 0) {
            if (finish1 + finish2 < n) start1++;
        }
        if (ti % t2 == 0) {
            if (finish1 + finish2 < n) start2++;
        }
            
            
        //printf("[%d]: %d %d; %d %d;\n", ti, start1, finish1, start2, finish2);
        if (finish1 + finish2 >= n && start1 == finish1 && start2 == finish2) break;
    }
    printf("%d %d\n", finish1 + finish2, ti);
    return 0;
}
