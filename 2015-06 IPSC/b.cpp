#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem 
 * @url     
 * @status  
 */
struct strx {
    char s[16];
    strx() { s[0] = '\0'; }
    bool operator < (const strx B) const {
        return strcmp(s, B.s);
    }
};
struct da {
    int v;
    strx w;
    da() { v = 0; };
    da(int _v, strx _w) : v(_v), w(_w) { };
    da(strx _w, int _v) : v(_v), w(_w) { };
} D[3][10010];
map<strx, int> MA[3];

bool comp_da(da A, da B) {
    return A.v < B.v;
}

int M[3], N;
strx Q[3];

int strength(strx q[3]) {
    printf("---------\n");
    printf("%s = %d\n", q[0].s, MA[0][q[0]]);
    printf("%s = %d\n", q[1].s, MA[1][q[1]]);
    printf("%s = %d\n", q[2].s, MA[2][q[2]]);
    printf("---------\n");
    return MA[0][q[0]] + MA[1][q[1]] + MA[2][q[2]];
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    for (int i = 0; i < 3; i++) {
        scanf("%d", &M[i]);
        for (int j = 0; j < M[i]; ++j)
        {
            strx TX; int TV;
            scanf("%s %d", TX.s, &TV);
            printf("%s = %d\n", TX.s, TV);
            D[i][j] = da(TX, TV);
            MA[i][TX] = D[i][j].v;
            printf("%s = %d\n", D[i][j].w.s, MA[i][TX]);
        }
        sort(D[i], D[i] + M[i], comp_da);
    }
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s %s %s", Q[0].s, Q[1].s, Q[2].s);
        int st = strength(Q);
        printf("%d\n", st);
    }
    

    return 0;
}
