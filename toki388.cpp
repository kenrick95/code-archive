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

/* Problem: Jabat Tangan
 * URL: http://tokilearning.org/training/7/chapter/72/problem/388
 */

int64 sav[100];
int N;
int64 f(int N) {
    //printf("%d\n", N);
    if (N == 0 || N == 2) return 1;
    if (sav[N] != -1) return sav[N];
    
    int64 ret = 0;
    for (int i = 0; i < (N / 2); i++) {
        ret += f(i * 2) * f(N - i * 2 - 2);
    }
    sav[N] = ret;
    
    return ret;
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d", &N);
    memset(sav, -1, sizeof(sav));
    printf("%lld\n", f(N));
	return 0;
}
