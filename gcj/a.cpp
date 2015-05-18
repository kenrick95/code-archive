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

/* Problem: GCJ 2014 QR - A
 * URL: https://code.google.com/codejam/contest/2974486/dashboard#s=p1
 */


int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t, T;
    int r1, r2;
    int map[5][5][5];
    int ans[100];
    int i, j, x, y;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        memset(ans, 0, sizeof(ans));
        scanf("%d", &r1);
        for (i = 1; i <= 4; i++) {
            for (j = 1; j <= 4; j++) {
                scanf("%d", &map[1][i][j]);
                if (r1 == i) {
                    ans[map[1][i][j]]++;
                }
            }
        }
        scanf("%d", &r2);
        for (i = 1; i <= 4; i++) {
            for (j = 1; j <= 4; j++) {
                scanf("%d", &map[2][i][j]);
                if (r2 == i) {
                    ans[map[2][i][j]]++;
                }
            }
        }
        x = 0; // status: 0 havent had 1 answer, 1 alr have one
        y = 0; //answer; 0: vol cheat; -1: bad magician
        for (i = 1; i <= 16; i++) {
            if (ans[i] == 2) {
                if (x == 0) {
                    x = 1;
                    y = i;
                } else {
                    y = -1;
                }
            }
        }
        printf("Case #%d: ", t);
        if (y == -1) {
            printf("Bad magician!\n");
        } else if (y == 0) {
            printf("Volunteer cheated!\n");
        } else {
            printf("%d\n", y);
        }
    }
	return 0;
}
