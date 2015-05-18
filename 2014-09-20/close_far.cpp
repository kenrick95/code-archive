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
	//close_far
    int a[10];
    bool close = false, far = false;
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    
    sort(a, a + 2);
    
    if ((a[2] - a[1] <= 1) || (a[1] - a[0] <= 1)) {
        close = true;
    }
    if ((a[2] - a[0] >= 2)) {
        far = true;
    }
    if (close && far) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    
	return 0;
}
