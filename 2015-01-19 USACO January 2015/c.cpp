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

struct dat {
  int value, base;  
} valA[15000], valB[15000];
bool comp(dat A, dat B) {
    return A.value < B.value;
}

int main(){
    freopen("whatbase.in","r",stdin);
    freopen("whatbase.out","w",stdout);
    int T, a[4], b[4], minbaseA = -1, minbaseB = -1, minbase = -1;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        // take note for 000...111; -> satisfy for binary, else no!
        scanf("%d %d", &a[3], &b[3]);
        a[0] = a[3] / 100;
        a[1] = (a[3] / 10) % 10;
        a[2] = a[3] % 10;
        b[0] = b[3] / 100;
        b[1] = (b[3] / 10) % 10;
        b[2] = b[3] % 10;
        /*minbaseA = max(minbaseA, a[0]);
        minbaseA = max(minbaseA, a[1]);
        minbaseA = max(minbaseA, a[2])  + 1;
        minbaseB = max(minbaseB, b[0]);
        minbaseB = max(minbaseB, b[1]);
        minbaseB = max(minbaseB, b[2])  + 1;
        minbase = min(minbaseA, minbaseB);
        printf("%d %d", minbaseA, minbaseB);*/
        minbase = minbaseA = minbaseB = 10;
        // printf("%d,%d,%d %d,%d,%d\n", a[0],a[1],a[2],b[0],b[1],b[2]);

        for (int base = minbase; base <= 15000; base++) {
            valA[base].value = a[2]
                        + a[0] * base * base
                        + a[1] * base;
            valA[base].base = base;

            valB[base].value = b[2]
                        + b[0] * base * base
                        + b[1] * base;
            valB[base].base = base;
            
            //printf("%d: %d %d\n", base, valA[base].value, valB[base].value);
        }
        // sort(valA + minbaseA, valA + 15001, comp);
        sort(valB + minbaseB, valB + 15001, comp);
        
        for (int base = minbaseA; base <= 15000; base++) {
            int l, r, mid;
            l = minbaseB; r = 15000;
            while (l <= r) {
                mid = (l + r) / 2;
                if (valA[base].value == valB[mid].value) {
                    // this is it!
                    break;
                } else if (valA[base].value < valB[mid].value) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (valA[base].value == valB[mid].value) {
                printf("%d %d\n", base, valB[mid].base);
                break;
            }
        }
    }
    return 0;
}
