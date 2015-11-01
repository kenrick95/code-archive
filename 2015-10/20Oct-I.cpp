#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
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

int r, c, ans;
char ma[1024][1024];
int dy[][2] = {{-1, 0}, {0, 1}, {1, 0},  {0, -1}};
int dx[][2] = {{0, 1},  {1, 0}, {0, -1}, {-1, 0}};
// map<pair<pair<int, int>, pair<int, bool> >, int> sav;
int sav[1024][1024][4][2];

int cnt = 0, cnt2 = 0;

int g(int i, int j, int cd, bool seq) {
    if (ma[i][j] != '1' || i < 0 || i >= r || j < 0 || j > c)
        return 0;
    // if (sav.count(make_pair(make_pair(i,j), make_pair(cd, seq))) > 0) {
    //     return sav[make_pair(make_pair(i,j), make_pair(cd, seq))];
    // }
    if (sav[i][j][cd][seq] > -1) {
        return sav[i][j][cd][seq];
    }
    //printf("%d %d %d %d\n", i, j, cd, seq);
    int ret = g(i + dy[cd][seq], j + dx[cd][seq], cd, !seq) + 1;
    // sav[make_pair(make_pair(i,j), make_pair(cd, seq))] = ret;
    sav[i][j][cd][seq] = ret;
    return ret;

}

int f(int i, int j) {
    int ret = 1;
    for (int cd = 0; cd < 4; cd++) {
        ret += g(i, j, cd, 0) - 1;
    }
    return ret;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T, temp = 0;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        memset(sav, -1, sizeof sav);
        //sav.clear();
        scanf("%d %d", &r, &c);
        for (int i = 0; i < r; i++) {
            scanf("%s", &ma[i]);
        }
        ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                temp = f(i, j);
                ans = max(ans, temp);
                //printf("%d %d: %d\n------------\n", i, j, temp);
            }
        }
        //printf("%d %d\n", cnt, cnt2);
        printf("%d\n", ans);


    }
    return 0;
}
