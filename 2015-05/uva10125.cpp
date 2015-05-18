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

int n, a[1024], hi, lo, mid;
struct da {
    int res;
    int a, b;
} mi[1024*1024], pl[1024*1024];

bool comp(da A, da B) {
    return (A.res < B.res)
        || (A.res == B.res && A.a < B.a)
        || (A.res == B.res && A.a == B.a && A.b < B.b);
};

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                pl[k].res = a[i] + a[j];
                pl[k].a = i;
                pl[k].b = j;
                k++;
            }
        }
        k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                mi[k].res = a[j] - a[i];
                mi[k].a = i;
                mi[k].b = j;
                k++;
            }
        }
        int N = k;
        sort(pl, pl + N, comp);
        sort(mi, mi + N, comp);
        int ans = -INF;
        for (int i = 0; i < N; i++) {
            lo = 0;
            hi = N;
            while (lo < hi) {
                mid = (lo + hi) / 2;
                if (pl[i].res == mi[mid].res) {
                    lo = hi = mid;
                    break;
                } else if (pl[i].res < mi[mid].res) {
                    hi = mid - 1;
                } else { // (pl[i].res > mi[mid].res)
                    lo = mid + 1;
                }
            }
            if (pl[i].res == mi[mid].res) {
                // found
                
                // check neighbour ._.
                int j = 0;
                while (pl[i].res == mi[mid + j].res) {
                    if (pl[i].a != mi[mid + j].a
                        && pl[i].a != mi[mid + j].b
                        && pl[i].b != mi[mid + j].a
                        && pl[i].b != mi[mid + j].b) {
                        ans = max(ans, a[mi[mid + j].b]);
                    }
                    j++;
                }
                j = 0;
                while (pl[i].res == mi[mid + j].res) {
                    if (pl[i].a != mi[mid + j].a
                        && pl[i].a != mi[mid + j].b
                        && pl[i].b != mi[mid + j].a
                        && pl[i].b != mi[mid + j].b) {
                        ans = max(ans, a[mi[mid + j].b]);
                    }
                    j--;
                }
            } else {
                // meh
            }
        }
        if (ans == -INF) {
            printf("no solution\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
