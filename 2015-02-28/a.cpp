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
    int a, b;
    int ta, tb;
    int bef, len, x;
    scanf("%d %d", &a, &b);
    ta = a; tb = b;
    bool certain = false;
    if (ta > tb) ta = ta % tb;
    while (!certain) {
        if (ta % tb == 0) {
            certain = true;
        }
        // ta < tb
        ta *= 10;
        x = ta / tb;
        ta = ta % tb;
    }
    return 0;
}

