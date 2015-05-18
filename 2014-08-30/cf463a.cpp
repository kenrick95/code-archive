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
    int n, s, d[101], c[101];
	scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &d[i], &c[i]);
    }
    int maxCandy = -1, candy = 0;
    for (int i = 0; i < n; i++) {
        if (s >= d[i]) {
            candy = (s*100 - (d[i]*100 + c[i])) % 100;
            maxCandy = max(candy, maxCandy);
            /*for (int j = 0; j <= (s*100 / (d[i]*100 + c[i])); j++) {
                candy = (s*100 - j*(d[i]*100 + c[i])) % 100;
                maxCandy = max(candy, maxCandy);
            }*/
        }
    }
    printf("%d\n", maxCandy);
	return 0;
}
