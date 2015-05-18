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
    int t, l;
    char x[10];
	scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%s", x);
        l = strlen(x);
        for (int k = l-1; k >= 0; k--) {
            printf("%c", x[k]);
        }
        printf("\n");
    }
	return 0;
}
