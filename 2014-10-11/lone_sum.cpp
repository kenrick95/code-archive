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
    int a[5], sum;
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
    sum = 0;
    sort(a, a + 3);
    
    //if (a[0] != a[1] || a[0] != a[2]) {
        if (a[0] != a[1]) {
            sum += a[0];
            if (a[1] != a[2]) {
                sum += a[1];
                sum += a[2];
            }
        } else if (a[1] != a[2]) {
            sum += a[2];
        }
    //}
    printf("%d\n", sum);
    
	return 0;
}
