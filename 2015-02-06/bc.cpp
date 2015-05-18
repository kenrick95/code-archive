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

int n, val[300000];
char type;
bool dragon[300000];
int max_kill[300000];
char line[255];

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d", &n);
    fgets(line, 255, stdin);
    for (int i = 1; i < n; i++) {
        fgets(line, 255, stdin);
        sscanf(line, "%c %d\n", &type, &val[i]);
        
        dragon[i] = (type == 'd');
        
        printf("[%d] %d [%c]\n", i, dragon[i], type);
    }
    dragon[0] = true;
    max_kill[n-1] = 300000; //last one: inf
    for (int i = n-2; i >= 0; i--) {
        max_kill[i] = (dragon[i]) ? max_kill[i + 1] : min(max_kill[i + 1], val[i]);
    }
    return 0;
}
