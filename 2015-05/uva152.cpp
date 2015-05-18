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
 * @problem  uva 152 - Tree's a Crowd 
 * @url    http://uva.onlinejudge.org/external/1/152.html
 * @status  Accepted
 */


struct point {
    int x, y, z;
    point() { x = y = z = 0; };
    point(int _x, int _y, int _z) { x = _x; y = _y; z = _z; };
};

int sqrsum(point a) {
    return a.x * a.x + a.y * a.y + a.z * a.z;
};

int sqrdist(point a, point b) {
    return sqrsum(point(a.x - b.x, a.y - b.y, a.z - b.z));
};

double dist(point a, point b) {
    return sqrt(sqrdist(a, b));
};

vector<point> P;

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    
    int ans[16], x, y, z;
    P.clear();
    while (scanf("%d %d %d", &x, &y, &z) != EOF ) {
        if (x == 0 && y == 0 && z == 0)
            break;
        P.push_back(point(x, y, z));
    }
    memset(ans, 0, sizeof ans);
    for (int j = 0; j < P.size(); j++) {
        int closest = -1, cdist = INF;
        for (int k = 0; k < P.size(); k++) {
            if (j != k) {
                if (sqrdist(P[j], P[k]) < cdist) {
                    closest = k;
                    cdist = sqrdist(P[j], P[k]);
                }
            }
        }
        // printf("%d: %d %d %d\n", j, closest, cdist, (int) floor(sqrt(cdist)));
        if (0 <= cdist && cdist < 10*10) {

            ans[(int) floor(sqrt(cdist))]++;
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%4d", ans[i]);
    }
    printf("\n");
    return 0;
}
