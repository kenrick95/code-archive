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

/* Problem: TOKI Open 2014 - Day 2 (Run 1): Fowl Sculptures
 * URL: http://167.205.32.28/contest/5/problem/6/view
 */

typedef struct _p {
    double x,y;
} point;

bool comp(point A, point B) {
    return A.x < B.x;
};
int N, i, j, k = 0;
double angle = 0.0, l = 0.0, r = 180.0, lt, rt;
point temp;
point p[2020];
    
int test(double angle, double precision) {
    int k  = 0, i, j;
    for (i = 0; i < N; i++) {
        // reflect p[i] using the line y = x tan(lt)
        temp.x = p[i].x * cos(2.0 * angle) + p[i].y * sin(2.0 * angle);
        temp.y = p[i].x * sin(2.0 * angle) - p[i].y * cos(2.0 * angle);
        //printf("%.6lf %.6lf %.6lf %.6lf\n", temp.x, temp.y, p[i].x, p[i].y);
        //search if temp exists;
        for (j = 0; j < N; j++) {
            if (
                fabs(temp.x - p[j].x) < precision
            &&  fabs(temp.y - p[j].y) < precision
            &&  i!=j) {
                break;
            }
        }
        if (j == N) k++;
    }
    return k;
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    sort(p, p+N, comp);
    angle = 0.0;
    
    // binary search the angle! (or ternary search?)
    // check if the angle can produce the least k
    while (1) {
        if (fabs(r - l) < 0.0000001) {
            angle = (l + r) / 2.0;
            break;
        }
        lt = ((double) (2.0*l + r)) / 3.0;
        rt = ((double) (l + 2.0*r)) / 3.0;
        printf("l:%.3lf: %d;   r:%.3lf: %d;\n", lt, test(lt, 0.000001), rt, test(rt, 0.000001));
        if (test(lt, 0.000001) < test(rt, 0.000001)) {
            l = lt;
        } else {
            r = rt;
        }
    }
    //printf("%d\n",  test(0.000, 0.000001));
    printf("%.3lf\n",  angle);
    printf("%d\n",  test(angle, 0.00001));
	return 0;
}
