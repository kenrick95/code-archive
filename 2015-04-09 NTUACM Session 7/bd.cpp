#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem Color a Tree
 * @url     
 * @status  
 */


vector<int> node[1010][1010];

int V, E;

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    while (scanf("%d %d", &V, &E) != EOF) {
        if (V == 0 && E == 0) break;

        for (int i = 0; i < E; i++)
            scanf("%lld", &e[i].cost);
        for (int i = 0; i < E; i++) {
            scanf("%lld %lld", &e[i].from, &e[i].to);

            // 1-based -_-
            e[i].from--;
            e[i].to--;
        }
        printf("%lld\n", mst());
    }
    return 0;
}
