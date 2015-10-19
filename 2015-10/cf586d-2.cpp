#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
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
struct train {
    int head;
    int len;
    int y;
    train() {head = 0; len = 0; y = 0;};
    train(int _head, int _len, int _y) : head(_head), len(_len), y(_y) {};
};
train trains[32];
int n, k;
bool sav[3][128][128];
bool saok[3][128][128];
bool vi_sav[3][128][128];
bool vi_saok[3][128][128];

bool okay(int y, int x, int t) {
    if (y < 0 || y > 2)
        return false;
    if (vi_saok[y][x][t])
        return saok[y][x][t];
    vi_saok[y][x][t] = true;

    for (int i = 0; i < k; i++) {
        // printf("train %d > col: %d, row: %d, len: %d\n", i, trains[i].head - 2 * t, trains[i].y, trains[i].len);
        if (trains[i].head - 2 * t <= x && x < trains[i].head + trains[i].len - 2 * t
            && trains[i].y == y) {
            //printf("FAIL: %d %d %d:\n", y, x, t);
            //printf("     train %d > start: %d, end: %d\n", i, trains[i].head - 2 * t, trains[i].head + trains[i].len - 2 * t);
            return saok[y][x][t] = false;
        }
    }
    //printf("OKAY: %d %d %d\n", y, x, t);
    return saok[y][x][t] = true;
}

bool f(int y, int x, int t) {
    //printf("%d %d %d\n", y, x, t);
    if (y < 0 || y > 2 || !okay(y, x, t - 1) || !okay(y, x, t))
        return false;
    if (vi_sav[y][x][t])
        return sav[y][x][t];
    vi_sav[y][x][t] = true;

    if (x == n)
        return sav[y][x][t] = true;
    if (okay(y, x + 1, t)) {
        bool ret = false;
        if (okay(y - 1, x + 1, t + 1))
            ret |= f(y - 1, x + 1, t + 1);
        if (okay(y, x + 1, t + 1))
            ret |= f(y, x + 1, t + 1);
        if (okay(y + 1, x + 1, t + 1))
            ret |= f(y + 1, x + 1, t + 1);
        return sav[y][x][t] = ret;
    }

}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T;
    char ma[4][128];
    int d[][2] = {{-1, 1},{0, 1},{1, 1}};
    int start;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &n, &k);
        scanf("%s", ma[0]);
        scanf("%s", ma[1]);
        scanf("%s", ma[2]);

        if (ma[0][0] == 's')
            start = 0;
        else if (ma[1][0] == 's')
            start = 1;
        else if (ma[2][0] == 's')
            start = 2;

        memset(vi_saok, false, sizeof vi_saok);
        memset(vi_sav, false, sizeof vi_sav);

        int tc = 0;
        for (int j = 0; j < 3; j++) {
            char c = 0; int th = 0;
            for (int i = 0; i < n; i++) {
                if ('A' <= ma[j][i] && ma[j][i] <= 'Z' && c == 0) {
                    c = ma[j][i];
                    th = i;
                } else if (ma[j][i] != c && c > 0) {
                    //printf("%d %d %d\n", th, i, j);
                    c = 0;
                    trains[tc++] = train(th, i - th, j);
                }
            }
            if (c > 0) {
                c = 0;
                trains[tc++] = train(th, n - th, j);
            }
        }
        // bug: if train len = 1, it may "pass thru" player

        // for (int i = 0; i < k; i++) {
        //     printf("train %d > col: %d, row: %d, len: %d\n", i, trains[i].head, trains[i].y, trains[i].len);
        // }
        bool possible = f(start, 0, 0);
        (possible) ? puts("YES") : puts("NO");

    }

    return 0;
}
