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
    int64 w, m;
    scanf("%lld %lld", &w, &m);

    int x[128], cnt = 0;
    memset(x, 0, sizeof x);
    while (m > 0) {
        x[cnt++] = m % w;
        m /= w;
    }
    int car = 0, z = 0; bool possible = true;
    for (int i = 0; i < cnt; i++) {
        z = (x[i] + car) % w;
        car = (x[i] + car) / w;

        if (z == 1 || z == 0) {
            x[i] = z;
        } else if (z == w - 1) {
            car = 1;
            x[i] = -1;
        } else {
            possible = false;
            break;
        }
    }
    // for (int i = 0; i < cnt; i++) {
    //     printf("%d ", x[i]);
    // }
    possible ? puts("YES") : puts("NO");

    return 0;
}
