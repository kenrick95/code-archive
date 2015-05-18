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

/* Problem: Untaian Terlarang
 * URL: http://tokilearning.org/training/7/chapter/72/problem/397
 */
 
int64 sav[82][4];

int64 f(int n, char c1, char c2, char c3) {
    if (c1 * c2 * c3 == 6) {
        return 0;
    }
    
    //printf("%d", n);
    //printf("%d", c3);
    if (n == 1) {
        //printf("\n");
        return 1;
    }
    if (sav[n][c3] != -1) {
        return sav[n][c3];
    }
    int64 ret = f(n-1, c2, c3, 1) + f(n-1, c2, c3, 2) + f(n-1, c2, c3, 3);
    sav[n][c3] = ret;
    //printf("\n");
    return ret;
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int n;
	scanf("%d", &n);
    memset(sav, -1, sizeof(sav));
    printf("%lld\n", f(n, 0, 0, 1) +f(n, 0, 0, 2) +f(n, 0, 0, 3) );
	return 0;
}
