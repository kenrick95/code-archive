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
    int n;
    int t[1024], s[1024], f[1024], ans[1024], dir[1024], tf[1024];
    memset(ans, 0, sizeof ans);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &t[i], &s[i], &f[i]);
        dir[i] = 1;
        if (f[i] < s[i])
            dir[i] = -1;

        tf[i] = t[i] + abs(f[i] - s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            // both started moving at t = max(t[i], t[j])
            int tm = max(t[i], t[j]);
            int si_tm = s[i] + dir[i] * max(0, tm - t[i]);
            int sj_tm = s[j] + dir[j] * max(0, tm - t[j]);

            // one stop moving first at t = min(tf[i], tf[j])
            int tfx = min(tf[i], tf[j]);

            // position when one of them finishes
            int pi_tf = s[i] + dir[i] * (tfx - t[i]);
            int pj_tf = s[j] + dir[j] * (tfx - t[j]);

            //printf("i: %d; j: %d; tm: %d, si_tm: %d, sj_tm: %d, tfx: %d, pi_tf: %d, pj_tf: %d\n", i, j, tm, si_tm, sj_tm, tfx, pi_tf, pj_tf);
            if (dir[i] > 0 && dir[j] < 0) {
                if (si_tm <= sj_tm) {
                    double intersection=(max(si_tm,sj_tm)-min(si_tm,sj_tm))/2.0;
                    //int hmp = (si_tm + sj_tm); // half of meeting point (avoid double)
                    if (si_tm +intersection <= f[i] && sj_tm - intersection >= f[j] && si_tm +intersection == sj_tm - intersection ) {
                    //if (2 * pi_tf >= hmp && 2 * pj_tf <= hmp) {
                        ans[i]++;
                        ans[j]++;
                    }
                }
            } else if (dir[i] < 0 && dir[j] > 0) {
                if (si_tm >= sj_tm) {
                    double intersection=(max(si_tm,sj_tm)-min(si_tm,sj_tm))/2.0;
                    //int hmp = (si_tm + sj_tm); // half of meeting point (avoid double)
                    if (si_tm +intersection >= f[i] && sj_tm - intersection <= f[j] && si_tm +intersection == sj_tm - intersection ) {
                    //if (2 * pi_tf <= hmp && 2 * pj_tf >= hmp) {
                        ans[i]++;
                        ans[j]++;
                    }
                }
            } else if (dir[i] > 0 && dir[j] > 0) {
                if (si_tm == sj_tm) {
                    ans[i]++;
                    ans[j]++;
                }
            } else if (dir[i] < 0 && dir[j] < 0) {
                if (si_tm == sj_tm) {
                    ans[i]++;
                    ans[j]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
