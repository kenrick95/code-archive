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
    int n; int lambda;
    scanf("%d %d", &n, &lambda);
    int arrival[1024];
    memset(arrival, 0, sizeof arrival);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrival[i]);
    }
    int day = 0, backlog = 0, cnt = 0;
    while (day < n) {
        backlog += arrival[day];
        if (backlog > 0) {
            cnt++;
            //printf(" *", day, backlog);
        }
        backlog = max(0, backlog - lambda);
           // printf("[%d - %d] ", day, backlog);
        day++;
    }
    //printf("%d\n", (int) ceil((double) backlog / (double) lambda));
    cnt += (int) ceil((double) backlog / (double) lambda);
    printf("%d\n", cnt);
    return 0;
}
