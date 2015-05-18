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

/* Problem: Daerah Kekuasaan
 * URL: http://tokilearning.org/training/7/chapter/72/problem/379
 */
 
int t, T, B, K, N, L;
int k1, k2, b1, b2, i, j, k;
int maps[82][82], psum[82][82];

bool test(int b1, int k1, int b2, int k2, int left) {
    if (left <= 0) {
        //printf("to: %d %d\n", b2, k2);
        return true;
    }
    
    bool ret = false;
    // expand right
    // check if (b1, k2+1) until (b2, k2+1) is safe
    if (psum[b2][k2+1] - psum[b2][k2] - psum[b1-1][k2+1] + psum[b1-1][k2] == 0) {
        ret |= test(b1, k1, b2, k2+1, left - (b2-b1 +1));
        if (ret) return ret;
    }
    // expand down
    // check if (b2+1, k1) until (b2+1, k2) is safe
    if (psum[b2+1][k2] - psum[b2][k2] - psum[b2+1][k1-1] + psum[b2][k1-1] == 0) {
        ret |= test(b1, k1, b2+1, k2, left - (k2-k1 +1));
    }
    return ret;
    
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d", &T);
    for (t = 0; t < T; t++) {
        memset(maps, -1, sizeof(maps));
        scanf("%d %d %d %d", &B, &K, &N, &L);
        for (i = 1; i <= B; i++) {
            for (j = 1; j <= K; j++) {
                maps[i][j] = 0;
                psum[i][j] = 0;
            }
        }
        for (i = 1; i <= N; i++) {
            scanf("%d %d %d %d", &b1, &k1, &b2, &k2);
            for (j = b1; j <= b2; j++) {
                for (k = k1; k <= k2; k++) {
                    maps[j][k] = 1;
                }
            }
        }
        bool ret = false;
        /*
        for (i = 1; i <= B; i++) {
            for (j = 1; j <= K; j++) {
                printf("%d", maps[i][j]);
            }
            printf("\n");
        }*/
        for (i = 1; i <= B; i++) {
            for (j = 1; j <= K; j++) {
                // psum: sum of maps from (1,1) to (i,j); inclusive
                if (i == 1 && j == 1)
                    psum[1][1] = maps[1][1];
                else if (i == 1)
                    psum[i][j] = psum[i][j-1] + maps[i][j];
                else if (j == 1)
                    psum[i][j] = psum[i-1][j] + maps[i][j];
                else
                    psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] +maps[i][j];
            }
        }
        /*for (i = 1; i <= B; i++) {
            for (j = 1; j <= K; j++) {
                printf("%3d ", psum[i][j]);
            }
            printf("\n");
        }*/
        for (i = 1; i <= B; i++) {
            for (j = 1; j <= K; j++) {
                if (maps[i][j] == 0) {
                    ret |= test(i, j, i, j, L - 1);
                    // start from (i,j) and expand!
                }
                if (ret) {
                    //printf("from: %d %d\n", i, j);
                    break;
                }
            }
            if (ret) break;
        }
        if (ret) {
            printf("YA\n");
        } else {
            printf("TIDAK\n");
        }
    }
	return 0;
}
