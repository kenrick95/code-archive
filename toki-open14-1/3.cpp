#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: TOKI Open 2014 - Day 1 (Run 2): Social Inequality
 * URL: http://167.205.32.28/contest/4/problem/view/3/
 */

typedef struct _x {
    int l,p;
} da;
bool comp(da A, da B) {
    return A.l < B.l;
};

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int N, i, j, l, r, mid;
    da x[100100];
    int64 ans = 0;
	scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x[i].l, &x[i].p);
    }
    sort(x, x+N, comp);
    //~ for (int i = 0; i < N; i++) {
        //~ printf("%d %d\n", x[i].l, x[i].p);
    //~ }
    for (int i = 0; i < N; i++) {
        l = i + 1;
        r = N;
        
        while (l < r) {
            mid = (l + r) / 2;
            if (x[mid].l <= x[i].l) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        for (int j = l; j < N; j++) {
            ans += abs(x[i].l - x[j].l) * abs (x[i].p - x[j].p);
        }
    }
    printf("%lld\n", ans);
	return 0;
}
