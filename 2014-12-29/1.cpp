#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
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
    int xa,ya,ra,xb,yb,rb;
    scanf("%d %d %d", &xa, &ya, &ra);
    scanf("%d %d %d", &xb, &yb, &rb);
    if (((max(ra,rb) - min(ra,rb))*(max(ra,rb) - min(ra,rb)) <= (xa - xb)*(xa - xb) + (ya - yb)*(ya - yb))
    && ((xa - xb)*(xa - xb) + (ya - yb)*(ya - yb) <= (ra + rb)*(ra + rb))) {
        printf("bersentuhan\n");
    } else {
        printf("tidak bersentuhan\n");
    }
    
    
    return 0;
}
