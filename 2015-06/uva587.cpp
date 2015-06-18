#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem  There's treasure everywhere! 
 * @url     https://uva.onlinejudge.org/external/5/587.html
 * @status  AC
 */
struct point {
    double x, y;
    point() { x = y = 0.; };
    point(double _x, double _y) : x(_x), y(_y) {};
};

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    char str[255]; int T = 0;
    while(scanf("%s", &str) != 0) {
        if (strcmp("END", str) == 0)
            break;

        point P = point(0, 0);
        int ls = strlen(str);
        int cur_step = 0;
        int cur_dir = -1;
        // direction
        // 0 N
        // 1 NE
        // 2 E
        // 3 SE
        // 4 S
        // 5 SW
        // 6 W
        // 7 NW
        for (int i = 0; i < ls; i++) {
            if ('0' <= str[i] && str[i] <= '9') {
                cur_step = (cur_step * 10) + (str[i] - '0');
            } else if (str[i] == 'N') {
                cur_dir = 0;
            } else if (str[i] == 'S') {
                cur_dir = 4;
            } else if (str[i] == 'E') {
                if (cur_dir == 0) { // NE
                    cur_dir = 1;
                } else if (cur_dir == 4) { // SE
                    cur_dir = 3;
                } else {
                    cur_dir = 2;
                }
            } else if (str[i] == 'W') {
                if (cur_dir == 0) { // NW
                    cur_dir = 7;
                } else if (cur_dir == 4) { // SW
                    cur_dir = 5;
                } else {
                    cur_dir = 6;
                }
            } else if (str[i] == '.' || str[i] == ',') {
                //printf("dir = %d; step = %d\n", cur_dir, cur_step);
                switch (cur_dir) {
                    case 0: // N
                        P.x += 0.;                  P.y += cur_step;
                    break;
                    case 1: // NE
                        P.x += cur_step / sqrt(2.);  P.y += cur_step / sqrt(2.);
                    break;
                    case 2: // E
                        P.x += cur_step;            P.y -= 0.;
                    break;
                    case 3: // SE
                        P.x += cur_step / sqrt(2.);  P.y -= cur_step / sqrt(2.);
                    break;
                    case 4: // S
                        P.x -= 0.;                  P.y -= cur_step;
                    break;
                    case 5: // SW
                        P.x -= cur_step / sqrt(2.);  P.y -= cur_step / sqrt(2.);
                    break;
                    case 6: // W
                        P.x -= cur_step;            P.y += 0.;
                    break;
                    case 7: // NW
                        P.x -= cur_step / sqrt(2.);  P.y += cur_step / sqrt(2.);
                    break;
                }
                cur_dir = -1;
                cur_step = 0;
                if (str[i] == '.') {
                    printf("Map #%d\n", ++T);
                    printf("The treasure is located at (%.3lf,%.3lf).\n", P.x, P.y);
                    printf("The distance to the treasure is %.3lf.\n\n", hypot(P.x, P.y));
                }
            }
        }
    }
    return 0;
}
