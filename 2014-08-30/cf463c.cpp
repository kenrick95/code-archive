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
	//freopen("test.in","r",stdin);a
	//freopen("test.out","w",stdout);
	int n;
    int sopd[2002][2002], sosd[2002][2002], a[2002][2002];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sopd[i][j] = sopd[i-1][j-1] + a[i][j];
            sosd[i][j] = sosd[i-1][j+1] + a[i][j];
        }
    }
    
	return 0;
}
