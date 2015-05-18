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

/* Problem: GCJ 2014 QR - B
 * URL: https://code.google.com/codejam/contest/2974486/dashboard#s=p1
 */

double X, C, F;

double r(int i) {
    return 2.0 + F*i;
}

double f(int i) {
    double ret = 0.0;
    //printf("%d\n", i);
    if ((X / r(i)) < (X / r(i + 1) + C / r(i) )) {
        ret = X / r(i);
    } else {
        ret = C / r(i) + f(i + 1);
    }
    //printf("%d %lf\n", i, ret);
    return ret;
    
}

int main(){
    int T;
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        scanf("%lf", &C);
        scanf("%lf", &F);
        scanf("%lf", &X);
        printf("Case #%d: %.7lf\n", t, f(0));
    }
	return 0;
}
