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

struct da {
    int x,y;
} p[100100];

bool comp(da A, da B) { //sort, increasing x
    return A.x < B.x || (A.x == B.x && A.y < B.y);
};
bool comp2(da A, da B) { //sort, increasing y
    return A.y < B.y || (A.y == B.y && A.x < B.x);
};
int n;
int cnt[1000010]; // count[i] brp titik dgn y >= i
int vc[1000010]; // vc[i] brp titik dgn y = i

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
        vc[p[i].y]++;
    }
    //sort (p, p+n, comp2);
    cnt[0] = n;
    for (int i = 1; i < 1000010; i++) {
        cnt[i] = cnt[i - 1] - vc[i];
    }
    sort (p, p+n, comp);
    
    for (int i = 0; i < n; i++) {
        
    }
    
    return 0;
}
