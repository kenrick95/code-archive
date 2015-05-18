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

/* Problem: 
 * URL: http://uva.onlinejudge.org/external/108/10819.html
 * 
 * WA
 */

int m,n;
int p[110], f[110];
int sav[110][10010][2];

int fa(int i, int mon, bool use) {
    if (sav[i][mon][use] > -1) {
        return sav[i][mon][use];
    }
    if (mon > 2000 && !use) {
        mon -= 200;
        if (mon > m) {
            return -99999999;
        }
        if (i > n) {
            return 0;
        }
        
        sav[i][mon][use] = max(fa(i + 1, mon + p[i], 1) + f[i], fa(i + 1, mon, 1));
        return sav[i][mon][use];
    } else {
        if (mon > m) {
            return -99999999;
        }
        if (i > n) {
            return 0;
        }

        sav[i][mon][use] = max(fa(i + 1, mon + p[i], 0) + f[i], fa(i + 1, mon, 0));
        return sav[i][mon][use];
    }
    
}
    
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    
    
    while (scanf("%d %d", &m, &n) != EOF) {
        memset(sav, -1, sizeof sav);
        
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p[i], &f[i]);
        }
        printf("%d\n", fa(0, 0, 0));
    }
    
	return 0;
}
