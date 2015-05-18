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

/* Problem:  Problem C: Vito's family 
 * URL: http://uva.onlinejudge.org/external/100/10041.html
 */


int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int T,n;
    int a[505], minDist, dist = 0, temp = 0;
	scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        // sort
        sort(a, a+n);
        
        
        dist = 0;
        for (int i = 0; i < n; i++) {
            dist += abs(a[0] - a[i]);
        }
        
        temp = dist;
        minDist = dist;
        // iterate from left to right, increase [left dist], decrease [right dist]; until minimum (i.e. in the middle, median)
        for (int i = 1; i < n; i++) {
            temp += (a[i] - a[i-1])*((i - 1) - (n - i -1));
            minDist = min(temp, minDist);
        }
        
        printf("%d\n", minDist);
    } 
	return 0;
}
