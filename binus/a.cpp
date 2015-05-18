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

/* Problem: 
 * URL: 
 */

int t,T,n,k;
typedef struct _point {
    int x,y;
} Point;
Point p[10010];

bool comp(Point A, Point B) {
    return A.x < B.x;
}
int min_h, temp_h;

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    scanf("%d", &T);
    for (t = 0; t < T; t++) {
        scanf("%d %d", &n, &k);
        min_h = 0, temp_h = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p[i].x, &p[i].y);
        }
        //sort(p, p+n, comp);
        Point pre;
        pre.x = 0;
        pre.y = k;
        for (int i = 0; i < n; i++) {
            //printf("%d %d\n", p[i].x, p[i].y);
            Point cur = p[i];
            if (cur.y <= pre.y) {
                min_h += (int) abs((pre.x - cur.x)*(pre.x - cur.x) + (pre.y - cur.y)*(pre.y - cur.y));
            } else {
                min_h += (int) abs((pre.x - cur.x)*(pre.x - cur.x) + (pre.y + cur.y)*(pre.y + cur.y));
            }
            //printf("%d: %d %d; %d %d\n", min_h, cur.x, cur.y, pre.x, pre.y);
            pre = cur;
        }
        printf("Kasus #%d: %d\n", t+1, min_h);
    }
	return 0;
}
