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
	int i = 0;
    char s[1010];
    while(scanf("%s", s) != EOF) {
        i++;
    }
    if (i % 2 == 0) {
        printf("TIDAK\n");
    } else {
        printf("YA\n");
    }
	return 0;
}
