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


int ls, lt, N;
struct dat {
    int s, t, n;
    dat() {}
    dat(int _s, int _t) : s(_s), t(_t) { n = 0; }
} d, ev[100007];
int count (int s, int t) {
    int a = lt * ls, b = lt * t + lt  * d.s + d.t * ls, c = d.t * d.s + d.t * s - s * t;
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    char _dum[255];
    scanf("%s", _dum);
    int sd, td;
    scanf("%d %d %d %d %d", &sd, &td, &ls, &lt, &N);
    d = dat(sd, td);

    for (int i = 0; i < N; i++) {
        int si, ti;
        scanf("%d %d", &si, &ti);
        ev[i] = dat(si, ti);
        ev[i].n = count(si, ti);
        printf("%d %d %d %d\n", i, ev[i].s, ev[i].t, ev[i].n);
    }
    return 0;
}
