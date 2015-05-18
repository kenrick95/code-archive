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
        //printf("%d %d\n", y, x);
    if (y > R || x > C || y < 1 || x < 1 || cnt[y][x] > -1) return;
        /*for (int y1 = 1; y1 <= R; y1++) {
            for (int x1 = 1; x1 <= C; x1++) {
                printf("%d", cnt[y1][x1]);
            }
            printf("\n");
        }*/
    int count = 0;
    if (map[y][x] == '*') {
        count++;
    }
    if ((y + 1 <= R) && map[y+1][x] == '*') {
        count++;
    }
    if ((y + 1 <= R) && (x + 1 <= C) && map[y+1][x+1] == '*') {
        count++;
    }
    if ((y + 1 <= R) && (x - 1 >= 1) && map[y+1][x-1] == '*') {
        count++;
    }
    if ((x + 1 <= C) && map[y][x+1] == '*') {
        count++;
    }
    if ((x - 1 >= 1) && map[y][x-1] == '*') {
        count++;
    }
    if ((y - 1 >= 1) && map[y-1][x] == '*') {
        count++;
    }
    if ((y - 1 >= 1) && (x + 1 <= C) && map[y-1][x+1] == '*') {
        count++;
    }
    if ((y - 1 >= 1) && (x - 1 >= 1) && map[y-1][x-1] == '*') {
        count++;
    }
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

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int t, T;
    char map[6][6];
    int cnt[6][6];
    pair<int,int> priority[36] = {
        // make_pair(y,x)
        make_pair(1,1),
        make_pair(1,2),
        make_pair(2,1),
        make_pair(2,2),
        make_pair(1,3),
        make_pair(2,3),
        make_pair(3,1),
        make_pair(3,2),
        make_pair(3,3),
        make_pair(1,4),
        make_pair(2,4),
        make_pair(3,4),
        make_pair(4,1),
        make_pair(4,2),
        make_pair(4,3),
        make_pair(4,4),
        make_pair(1,5),
        make_pair(2,5),
        make_pair(3,5),
        make_pair(4,5),
        make_pair(5,1),
        make_pair(5,2),
        make_pair(5,3),
        make_pair(5,4),
        make_pair(5,5)
        };
    int x, y, nonmine, i, yp, xp, nonmine_count;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        scanf("%d %d %d", &R, &C, &M);
        for (y = 1; y <= R; y++) {
            for (x = 1; x <= C; x++) {
                map[y][x] = '*';
                cnt[y][x] = -1;
            }
        }
        nonmine = R*C - M;
        nonmine_count = 0;
        for (i = 0; i < 25; i++) {
            yp = priority[i].first;
            xp = priority[i].second;
            if (xp >= 1 && xp<= C && yp >= 1 && yp <= R) {
                nonmine_count++;
                map[yp][xp] = '.';
            }
            if (nonmine_count == nonmine) break;
        }
        printf("Case #%d:\n", t);
        // test the map
        /*for (y = 1; y <= R; y++) {
            for (x = 1; x <= C; x++) {
                printf("%d", cnt[y][x]);
            }
            printf("\n");
        }
        printf("AAA");*/
        test(map, 1, 1, cnt);
        //printf("BBB");
        bool poss = true;
        for (y = 1; y <= R; y++) {
            for (x = 1; x <= C; x++) {
                if (map[y][x] != '*' && cnt[y][x] == -1) {
                    poss = false;
                    //break;
                }
                printf("%d", cnt[y][x]);
            }
            printf("\n");
        }
        map[1][1] = 'c';
        if (nonmine == 1) poss = true;
        
        if (!poss) //{
            printf("Impossible\n");
        //} else {
            for (y = 1; y <= R; y++) {
                for (x = 1; x <= C; x++) {
                    printf("%c", map[y][x]);
                }
                printf("\n");
            }
        //}
        
    }
	return 0;
}
