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

/* Problem: uVa 10127
 * URL: 
 */


int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    
    int n;
    while (scanf("%d", &n)  != EOF) {
        int p = 1, cnt = 1;
        while (p % n != 0) {
            cnt++;
            p = (p % n) * 10 + 1;
        }
        printf("%d\n", cnt);
    }
    
    
	return 0;
}
