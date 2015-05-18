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

/* Problem: Palindrom
 * URL: http://tokilearning.org/training/7/chapter/72/problem/427
 */

int N, len;
char str[55];
int sav[55][55];

int f(int l, int r) {
    //printf("%d %d\n", l, r);
    if (l > r || l >= len || r >= len || l < 0 || r < 0) return 0;
    if (l == r) return 1;
    
    int &ret = sav[l][r];
    if (ret != -1) return ret;
    
    ret = 0;
    if (str[l] == str[r]) {
        ret = f(l+1, r-1) + 2;
    } else {
        ret = max(f(l+1, r), f(l, r-1));
    }
    return ret;
}

int main(){
	scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        len = strlen(str);
        memset(sav, -1, sizeof sav);
        printf("%d\n", f(0, len - 1));
    }
	return 0;
}
