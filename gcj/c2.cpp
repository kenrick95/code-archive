#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: GCJ 2014 QR - C
 * URL: https://code.google.com/codejam/contest/2974486/dashboard#s=p1
 */
int M, R, C;

void test (char map[][6], int y, int x, int cnt[][6]) {
    if (y > R || x > C || y < 1 || x < 1 || cnt[y][x] > -1) return;
    int count = 0;
    if (map[y][x] == '*')
        count++;
    if ((y + 1 <= R) && map[y+1][x] == '*')
        count++;
    if ((y + 1 <= R) && (x + 1 <= C) && map[y+1][x+1] == '*')
        count++;
    if ((y + 1 <= R) && (x - 1 >= 1) && map[y+1][x-1] == '*')
        count++;
    if ((x + 1 <= C) && map[y][x+1] == '*')
        count++;
    if ((x - 1 >= 1) && map[y][x-1] == '*')
        count++;
    if ((y - 1 >= 1) && map[y-1][x] == '*')
        count++;
    if ((y - 1 >= 1) && (x + 1 <= C) && map[y-1][x+1] == '*')
        count++;
    if ((y - 1 >= 1) && (x - 1 >= 1) && map[y-1][x-1] == '*')
        count++;
    cnt[y][x] = count;
    if (count == 0) {
        test(map, y, x -1, cnt);
        test(map, y, x +1, cnt);
        
        test(map, y + 1, x - 1, cnt);
        test(map, y + 1, x , cnt);
        test(map, y + 1, x + 1, cnt);
        
        test(map, y -1, x - 1, cnt);
        test(map, y -1, x , cnt);
        test(map, y -1, x + 1, cnt);
    }
}
int pow2 (int e) {
    return 1 << e;
}
void gen_map (char map[][6], int mine, int cnt[][6]) {
    int i, x, y;
    int lim  = pow2( R*C);
    int count = 0;
    for (i = 0; i <= lim; i++) {
        count = 0;
        for (x = 0; x < R*C; x++) {
            if (!!(i & (1<<x) )) {
                //printf("%d %d %d\n", (x % R) + 1, (x % C) + 1, x);
                map[(x % R) + 1][(x % C) + 1] = '*';
                count++;
            }
        }
        if (mine == count) {
            printf("%d ", mine);
            printf("%d \n", count);
            for (y = 1; y <= R; y++) {
                for (x = 1; x <= C; x++) {
                    printf("%c", map[y][x]);
                }
                printf("\n");
            }
            for (int y = 1; y <= R; y++) {
                for (int x = 1; x <= C; x++) {
                    if (map[y][x] == '.') {
                        test(map, y, x, cnt);
                        bool poss = true;
                        for (int y1 = 1; y1 <= R; y1++) {
                            for (int x1 = 1; x1 <= C; x1++) {
                                if (map[y1][x1] != '*' && cnt[y1][x1] == -1) {
                                    poss = false;
                                    break;
                                }
                                //printf("%d", cnt[y][x]);
                            }
                            //printf("\n");
                        }
                        if (poss) {
                            map[y][x] = 'c';
                            for (int y1 = 1; y1 <= R; y1++) {
                                for (int x1 = 1; x1 <= C; x1++) {
                                    printf("%c", map[y1][x1]);
                                }
                                printf("\n");
                            }
                            return;
                        }
                    }
                }
            }
            
            
            
        }
        
        
        for (y = 1; y <= R; y++) {
            for (x = 1; x <= C; x++) {
                map[y][x] = '.';
                cnt[y][x] = -1;
            }
        }
    }
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t, T;
    char map[6][6];
    int cnt[6][6];
    
    int x, y, nonmine;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        scanf("%d %d %d", &R, &C, &M);
        for (y = 1; y <= R; y++) {
            for (x = 1; x <= C; x++) {
                map[y][x] = '.';
                cnt[y][x] = -1;
            }
        }
        nonmine = R*C - M;
        
        printf("Case #%d:\n", t);
        
        gen_map(map, M, cnt);
        /*bool poss = true;
        if (nonmine == 1) poss = true;
        
        if (!poss) {
            printf("Impossible\n");
        } else {
            for (y = 1; y <= R; y++) {
                for (x = 1; x <= C; x++) {
                    printf("%c", map[y][x]);
                }
                printf("\n");
            }
        }*/
        
    }
	return 0;
}
