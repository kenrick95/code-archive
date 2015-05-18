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
 
/* Problem: Raja Bebek
 * URL: http://tokilearning.org/training/7/chapter/72/problem/414
 */
 
int n,x,y,z, i,j,k;
int a[100010];
int sav[1010];
 
int main() {
    scanf("%d", &n);
    scanf("%d", &y);
    for (i = 1; i <= y; i++) {
        sav[i] = 1000000007;
    }
    for (i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        for (j = y; j >= a[i]; j--) {
            sav[j] = min(sav[j], sav[j-a[i]]+1);
        }
    }
    printf("%d\n", (sav[y] > n) ? -1 : sav[y]);
    return 0;
}
