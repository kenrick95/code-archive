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
    int n, a[3][100], start = -1, ans = 0;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a[0][i]);
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a[1][i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[2][i]);
    }
    int x[100], y[100];
    x[0] = 0;
    y[0] = 0;
    for (int i = 1; i < n; i++) {
        x[i] = x[i-1] + a[0][i-1];
        y[i] = y[i-1] + a[1][i-1];
    }
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", x[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", y[i]);
    // }
    // printf("\n");


    int mini = INF, minidx = -1;
    for (int i = 0; i < n; i++) {
        int temp = x[i] + (y[n-1] - y[i]) + a[2][i];
        //printf("%d ", temp);
        if (temp < mini) {
            minidx = i;
            mini = temp;
        }
    }
    ans += mini;
    int mini2 = INF, mini2dx = -1;
    for (int i = 0; i < n; i++) {
        int temp = x[i] + (y[n-1] - y[i]) + a[2][i];
        if (temp < mini2 && i != minidx) {
            mini2dx = i;
            mini2 = temp;
        }
    }
    ans += mini2;

    printf("%d\n", ans);



    return 0;
}
