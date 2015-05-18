#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */
int n, c;
int xa1,ya1,xa2,ya2;
int xb1,yb1,xb2,yb2;
int xp[256], yp[256], dem[256];
double dist1, dist2, dist3, p, min_dist[256][2], fact, dres1, dres2;
struct da {
    double m1, m2;
    int mark;
    int dem;
    int i;
} city[256];
bool comp1(da A, da B) {
    return (A.m1 * A.dem < B.m1 * B.dem) || ((A.m1 * A.dem - B.m1 * B.dem < 0.000001) && (A.m2 * A.dem < B.m2 * B.dem));
}
bool comp2(da A, da B) {
    return abs(A.m2 - A.m1) * (A.dem) < abs(B.m2 - B.m1) * (B.dem);
}
bool comp3(da A, da B) {
    return A.i < B.i;
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    while (scanf("%d %d", &n, &c) != EOF) {
        scanf("%d %d %d %d", &xa1, &ya1, &xa2, &ya2);
        scanf("%d %d %d %d", &xb1, &yb1, &xb2, &yb2);
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &xp[i], &yp[i], &dem[i]);
        }
        for (int i = 0; i < n; i++) {
            
            // Comparing to pipe 1
            dist1 = hypot(xp[i] - xa1, yp[i] - ya1); // A
            dist2 = hypot(xp[i] - xa2, yp[i] - ya2); // C
            dist3 = hypot(xa2 - xa1, ya2 - ya1); // B
            // dot product
            dres1 = ((xp[i] - xa1) * (xa2 - xa1)
                 + (yp[i] - ya1) * (ya2 - ya1)) / (dist1 * dist3);
            dres2 = ((xp[i] - xa2) * (xa1 - xa2)
                 + (yp[i] - ya2) * (ya1 - ya2)) / (dist2 * dist3);
            //printf("%lf %lf %lf %lf %lf\n", dist1, dist2, dist3, dres1, dres2);
            if (0 <= dres1 && dres1 <= 1
                && 0 <= dres2 && dres2 <= 1) {
                // city to pipe: straight line perpendiculbr to pipe
                fact = ((xp[i] - xa1) * (xa2 - xa1)
                 + (yp[i] - ya1) * (ya2 - ya1)) / (dist3 * dist3);
                p = hypot(fact * (xa2 - xa1), fact * (ya2 - ya1));
                min_dist[i][0] = sqrt(dist1 * dist1 - p * p);
                //printf("X\n");
            } else if (0 <= dres1 && dres1 <= 1
                && -1 <= dres2 && dres2 <= 0) {
                
                fact = ((xp[i] - xa2) * (xa2 - xa1)
                 + (yp[i] - ya2) * (ya2 - ya1)) / (dist3 * dist3);
                p = hypot(fact * (xa2 - xa1), fact * (ya2 - ya1));
                min_dist[i][0] = sqrt(dist2 * dist2 - p * p);
                //printf("Y\n");
            } else /*if (-1 <= dres1 && dres1 <= 0
                && 0 <= dres2 && dres2 <= 1)*/ {
                
                fact = ((xp[i] - xa1) * (xa2 - xa1)
                 + (yp[i] - ya1) * (ya2 - ya1)) / (dist3 * dist3);
                p = hypot(fact * (xa2 - xa1), fact * (ya2 - ya1));
                min_dist[i][0] = sqrt(dist1 * dist1 - p * p);
                //printf("Z\n");
            }
            /*printf("%lf %lf\n", fact, p);
            printf("%lf\n", min_dist[i][0]);
            printf("\n");*/
            
            
            // Comparing to pipe 2
            dist1 = hypot(xp[i] - xb1, yp[i] - yb1); // A
            dist2 = hypot(xp[i] - xb2, yp[i] - yb2); // C
            dist3 = hypot(xb2 - xb1, yb2 - yb1); // B
            // dot product
            dres1 = ((xp[i] - xb1) * (xb2 - xb1)
                 + (yp[i] - yb1) * (yb2 - yb1)) / (dist1 * dist3);
            dres2 = ((xp[i] - xb2) * (xb1 - xb2)
                 + (yp[i] - yb2) * (yb1 - yb2)) / (dist2 * dist3);
            //printf("%lf %lf %lf %lf %lf\n", dist1, dist2, dist3, dres1, dres2);
            if (0 <= dres1 && dres1 <= 1
                && 0 <= dres2 && dres2 <= 1) {
                // city to pipe: straight line perpendiculbr to pipe
                fact = ((xp[i] - xb1) * (xb2 - xb1)
                 + (yp[i] - yb1) * (yb2 - yb1)) / (dist3 * dist3);
                p = hypot(fact * (xb2 - xb1), fact * (yb2 - yb1));
                min_dist[i][1] = sqrt(dist1 * dist1 - p * p);
                //printf("X\n");
            } else if (0 <= dres1 && dres1 <= 1
                && -1 <= dres2 && dres2 <= 0) {
                
                fact = ((xp[i] - xb2) * (xb2 - xb1)
                 + (yp[i] - yb2) * (yb2 - yb1)) / (dist3 * dist3);
                p = hypot(fact * (xb2 - xb1), fact * (yb2 - yb1));
                min_dist[i][1] = sqrt(dist2 * dist2 - p * p);
                //printf("Y\n");
                
            } else /*if (-1 <= dres1 && dres1 <= 0
                && 0 <= dres2 && dres2 <= 1)*/ {
                
                fact = ((xp[i] - xb1) * (xb2 - xb1)
                 + (yp[i] - yb1) * (yb2 - yb1)) / (dist3 * dist3);
                p = hypot(fact * (xb2 - xb1), fact * (yb2 - yb1));
                min_dist[i][1] = sqrt(dist1 * dist1 - p * p);
                //printf("Z\n");
            }
            /*printf("%lf %lf\n", fact, p);
            printf("%lf\n", min_dist[i][1]);
            printf("\n");
            */
            city[i].mark = 0;
            city[i].m1 = min_dist[i][0];
            city[i].m2 = min_dist[i][1];
            city[i].dem = dem[i];
            city[i].i = i;
        }
        //sort(city, city + n, comp1);
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (city[i].m1 < city[i].m2) {
                city[i].mark = 1; c1++;
            } else {
                city[i].mark = 2; c2++;
            }
        }
        
        /*for (int i = 0; i < n; i++) {
            printf("%d: %d\n", city[i].i, city[i].mark);
        }*/
        if (abs(c2-c1) > c) {
            // flip!
            sort(city, city + n, comp2);
            /*for (int i = 0; i < n; i++) {
                printf("%d: %d %lf %lf %d %lf\n", city[i].i, city[i].mark, city[i].m2, city[i].m1, city[i].dem, (city[i].m2 - city[i].m1) * city[i].dem);
            }*/
            if (c2 > c1) {
                // pipe 2 -> pipe 1
                //for (int i = n-1; i >= 0; i--) {
                for (int i = 0; i < n; i++) {    
                    city[i].mark = 1;
                    c1++;
                    c2--;
                    if (abs(c2-c1) <= c) break;
                }
            } else {
                // pipe 1 -> pipe 2
                //for (int i = n-1; i >= 0; i--) {
                for (int i = 0; i < n; i++) {    
                    city[i].mark = 2;
                    c1--;
                    c2++;
                    if (abs(c2-c1) <= c) break;
                }
            }
        }
        sort(city, city + n, comp3);
        for (int i = 0; i < n; i++) {
            printf("%d ", city[i].mark);
            //if (i < n -1) printf(" ");
        }
        printf("\n");
        printf("\n");
    }
    return 0;
}
