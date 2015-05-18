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

/* Problem: USACO US OPEN 2014 - A (2)
 * URL: 
 */

int64 power(int base, int exp) {
    int64 ret = 1;
    for (int k = 1; k <= exp; k++) {
        ret *= base;
    }
    return ret;
}

int64 interest(int i) {
    int64 ret = 0;
    for (int j = 3; j <= i; j++) {
        ret += power(9, j-1) * 9 * (j-1);
    }
    return ret;
}
int64 interest(int i, int k) {
    int64 ret = power(k, i-1) * 9 * (i-1);
    return ret;
}

int64 interesting(int64 k) {
    int i = 0, ar[20];
    while (k > 0) {
        ar[++i] = k % 10;
        k = k / 10;
    }
    printf("%d\n", i);
    
    int64 ret = interest(i - 1);
    // this calculate from 100 to 10^(i-1),
    //      where i is number of digits of k
    
    int j = ar[i] - 1;
    ret += interest(i, k);
    
    printf("%lld\n", ret);
    
    return ret;
    
}


int main(){
	//freopen("odometer.in","r",stdin);
	//freopen("odometer.out","w",stdout);
	
    int64 x,y,k;
    scanf("%lld", &x);
    scanf("%lld", &y);
    k = interesting(y) - interesting(x-1);
    printf("%lld\n", k);
    
	return 0;
}
