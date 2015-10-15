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
struct da {
    int y, x;
    train t[32];
    int tc;
    da(int _y, int _x) : y(_y), x(_x) { tc = 0; };
};

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T;
    int n, k;
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

        da head = da(start, 0);
        for (int j = 0; j < 3; j++) {
            char c = 0; int th = 0;
            for (int i = 0; i < n; i++) {
                if ('A' <= ma[j][i] && ma[j][i] <= 'Z' && c == 0) {
                    c = ma[j][i];
                    th = i;
                    head.tc++;
                } else if (ma[j][i] == '.' && c > 0) {
                    head.t[head.tc] = train(th, i - th + 1, j);
                }
            }
        }

        queue<da> q;
        q.push(head);
        bool possible = false;
        int cnt = 0;

        while (!q.empty()) {
            head = q.front();
            // cnt++;
            if (head.x == n) {
                possible = true;
                break;
            }
            // printf("-----\npost: %d %d\n", head.y, head.x);
            // for (int j = 0; j < head.tc; j++) {
            //     printf("train %d > col: %d, row: %d, len: %d\n", j, head.t[j].head, head.t[j].y, head.t[j].len);
            // }

            q.pop();
            for (int i = 0; i < 3; i++) {
                da temp = da(head.y + d[i][0], head.x + d[i][1]);
                for (int j = 0; j < head.tc; j++) {
                    head.t[j].head -= 2;
                    if (head.t[j].head <= head.x && head.x <= head.t[j].head + head.t[j].len
                        && head.t[j].y == head.y) {
                        break;
                    }
                    temp.tc = head.tc;
                    temp.t[j] = head.t[j];
                }
                q.push(temp);
            }
        }
        (possible) ? puts("YES") : puts("NO");

    }

    return 0;
}
