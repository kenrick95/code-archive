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
    char str[255];
	scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c", str[j]);
        }
    }
    printf("\n");
    
	return 0;
}
