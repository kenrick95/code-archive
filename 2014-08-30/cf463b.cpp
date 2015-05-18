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
    int n, a[100010], i;
	scanf("%d", &n);
    a[0] = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    // INDEX START FROM 1
    
    int64 erg = 0, pay = 0, diff;
    for (i = 0; i < n; i++) {
        diff = a[i] - a[i+1];
        if (erg + diff < 0) {
            pay -= diff + erg;
            //a[i] += diff - erg;
            erg = 0;
        } else {
            erg += diff;
        }
        
    }
    printf("%lld\n", pay);
    
	return 0;
}
