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
 * URL: 
 */


int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int n, a[127][127], ps[127][127];
    
	scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(ps, 0, sizeof ps);
    
    ps[1][1] = a[1][1];
    
    /*for (int i = 1; i < n; i++) {
        ps[1][i] = ps[1][i-1] + a[1][i];
    }
    for (int i = 1; i < n; i++) {
        ps[i][1] = ps[i-1][1] + a[i][1];
    }*/
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ps[i][j] = ps[i-1][j] + ps[i][j-1] + a[i][j] - ps[i-1][j-1];
            //printf("%d ", ps[i][j]);
        }
        //printf("\n");
    }
    
    int tmax = -1000000007;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= n; l++) {
                    // [i][j] to [k][l];
                    tmax = max(tmax, ps[k][l] - ps[i-1][l] - ps[k][j-1] + ps[i-1][j-1]);
                    
                }
            }
        }
    }
    printf("%d\n", tmax);
    
	return 0;
}
