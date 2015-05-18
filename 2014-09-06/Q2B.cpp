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
    int n, ar[255], cnt = 0;
	scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
        if (ar[i] == 9) cnt++;
    }
    printf("%d\n", cnt);
    
    
	return 0;
}
