#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int T, n, k;
int a[2048];
int sav[2048][2048];
int f(int i, int v) {
    //printf("%d %d\n", i, v);
    if (v > k)
        return -1000000007;
    if (i >= n)
        return v;
    if (sav[i][v] > -1)
        return sav[i][v];
    int ret = 0;
    for (int x = 0; x < k / a[i] + 1; x++) {
        ret = max(ret, f(i + 1, v + a[i] * x));
    }
    return sav[i][v] = ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        memset(sav, -1, sizeof sav);
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", f(0, 0));
    }
    return 0;
}
