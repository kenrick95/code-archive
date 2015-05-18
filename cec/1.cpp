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
    int n, k;
    int sum;
    int x[10005];
    
	while (scanf("%d %d", &n, &k) != EOF) {
        sum = 0;
        for (int i =0; i<n; i++){ 
            scanf("%d", &x[i]);
        }
        sort(x, x+n);
        for (int i = 0; i<n; i++) {
            if (k > x[i]) {
                k -= x[i];
                sum++;
            }
        }
        printf("%d\n", sum);
        
    };
    
	return 0;
}
