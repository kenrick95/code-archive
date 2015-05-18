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
int f(int a, int b) {
    static int x = 0;
    x++;
    return x + a + b;
}


int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    printf("%d\n", f(0, 0));
    printf("%d\n", f(0, 0));
    printf("%d\n", f(1, 2));
    printf("%d\n", f(1, 2));
    printf("%d\n", f(0, 0));
    printf("%d\n", f(3, 1));
    
    return 0;
}
