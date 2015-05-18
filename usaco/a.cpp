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

/* Problem: USACO US OPEN 2014 - A
 * URL: 
 */

bool interesting(int64 k) {
    if (k < 10) return false;
    int ar[20];
    int i = 0;
    for (int j = 0; j < 20; j++) {
        ar[j] = 0;
    }
    
    while (k > 0) {
        ar[i++] = k % 10;
        k = k / 10;
        //cout<<k<<"-";
    }
    //cout<<endl;
    int diff[20], x = 0, y = 0;
    
    /*cout<<i;
    for (int j = 0; j < i; j++) {
        cout<<ar[j];
    }*/
    
    for (int j = 0; j < 10; j++) {
        diff[j] = 0;
    }
    for (int j = 0; j < i; j++) {
        diff[ar[j]]++;
    }
    
    for (int j = 0; j < 10; j++) {
        if (diff[j] > 0) {
            if (diff[j] == 1) {
                x = 1;
            } else {
                y = 1;
            }
        }
    }
    
    return (x && y);
}


int main(){
	//freopen("odometer.in","r",stdin);
	//freopen("odometer.out","w",stdout);
	
    int64 x,y,i,k;
    scanf("%lld", &x);
    scanf("%lld", &y);
    k = 0;
    for (i = x; i <= y; i++) {
        if (interesting(i)) {
            //printf(" %d ", i);
            k++;
        }
    }
    printf("%lld\n", k);
    
	return 0;
}
