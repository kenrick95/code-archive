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
 * @problem Mistwald
 * @url     
 * @status  
 */
struct node {
    int m, n;
};
struct ma {
    node dir[4];
} ma[6][6];

int M, N;

int f(int i, int j, int p) {
    if (p == 0) {
        printf("YAY");
        return 0;
    } else if (p < 0) {
        printf("NAY");
        return -1;
    }

    for (int k = 1; k < 4; k++)
        f(ma[i][j].dir[k].m, ma[i][j].dir[k].n, p - 1);
    return 0;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T = 0, P, Q;
    scanf("%d\n", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d\n", &M, &N);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("((%d,%d),(%d,%d),(%d,%d),(%d,%d))",  &ma[i][j].dir[0].m, &ma[i][j].dir[0].n, 
                                                            &ma[i][j].dir[1].m, &ma[i][j].dir[1].n,
                                                            &ma[i][j].dir[2].m, &ma[i][j].dir[2].n, 
                                                            &ma[i][j].dir[3].m, &ma[i][j].dir[3].n);

                if (j < N-1) scanf(" ");
                printf("((%d,%d),(%d,%d),(%d,%d),(%d,%d))",  ma[i][j].dir[0].m, ma[i][j].dir[0].n, 
                                                            ma[i][j].dir[1].m, ma[i][j].dir[1].n,
                                                            ma[i][j].dir[2].m, ma[i][j].dir[2].n, 
                                                            ma[i][j].dir[3].m, ma[i][j].dir[3].n);
            }
            scanf("\n");
        }
        scanf("%d", &Q);
        for (int q = 0; q < Q; q++) {
            scanf("%d", &P);
            f(1, 1, P);
        }
    }
    return 0;
}
