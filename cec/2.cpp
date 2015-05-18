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
    int l,r,mid;
    
	while (scanf("%d %d", &n, &k) != EOF) {
        sum = 0;
        for (int i =0; i<n; i++){ 
            scanf("%d", &x[i]);
        }
        sort(x, x+n);
        
        for (int i = 0; i<n; i++) {
            //printf(" %d \n",x[i]);
            l = i+1;
            r = n;
            while (l < r) {
                mid = (l+r) / 2;
                if (x[mid] < (x[i] + k)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if (x[r] - x[i] == k) {
                sum++;
            }
            //printf(" %d %d %d\n", l, r, mid);
           
            
        }
        printf("%d\n", sum);
    };
    
	return 0;
}
