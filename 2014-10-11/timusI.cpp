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
    char arS[1010], arN[1010];
	scanf("%s", arS); // from S
    scanf("%s", arN); // from N
    int lS = strlen(arS);
    int lN = strlen(arN);
    int time = 0;
    int ptrN = 0;
    int ptrS = 0;
    while (ptrS < lS && ptrN < lN) {
        time++;
        //printf("%d: %c %c\n", time, arS[ptrS], arN[ptrN]);
        
        if (arS[ptrS] == 'L' && arN[ptrN] == 'L') {
            ptrS++;
            ptrN++;
        } else if (arS[ptrS] == 'L') {
            ptrN++;
        } else if (arN[ptrN] == 'L') {
            ptrS++;
        } else {
            ptrS++;
            ptrN++;
        }
        
    }
    if (ptrS == lS) {
        time += lN - ptrN;
    } else if (ptrN == lN) {
        time += lS - ptrS;
    }
    
    printf("%d\n", time);
    
	return 0;
}
