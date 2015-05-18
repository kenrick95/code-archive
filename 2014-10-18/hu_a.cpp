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

const double PI = acos(-1.);

/* Problem: 
 * URL: 
 */

double cross(double x1, double y1, double x2, double y2)
{
     return x1 * y2 - y1 * x2;
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int x1,x2,x3,xp,y1,y2,y3,yp;
    int t = 0;
    int a,c,d,e,f;
    double xo, yo, r;
    double ans1, ans2, ans3, final_ans, ans;
    
	while (scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &xp, &yp) != EOF) {
        
    
        a = c = x1*y2 + x3 * y1 + x2 * y3 - (x3 * y2 +x1*y3 + x2*y1);
        d = - ((x1*x1 + y1*y1)*y2 + y1*(x3*x3+y3*y3)+(x2*x2+y2*y2)*y3
            - ((x3*x3 + y3*y3)*y2 + y3*(x1*x1+y1*y1)+(x2*x2+y2*y2)*y1));
        e = - ((x1*x1 + y1*y1)*x2 + x1*(x3*x3+y3*y3)+(x2*x2+y2*y2)*x3
            - ((x3*x3 + y3*y3)*x2 + x3*(x1*x1+y1*y1)+(x2*x2+y2*y2)*x1));
        f = - ((x1*x1 + y1*y1)*x2*y3 + x1*y2*(x3*x3+y3*y3)+y1*(x2*x2+y2*y2)*x3
            - ((x3*x3 + y3*y3)*x2*y1 + x3*y2*(x1*x1+y1*y1)+y3*(x2*x2+y2*y2)*x1));
        
        xo = - d / 2.0 / a;
        yo = - e / 2.0 / a;
        r = sqrt((d*d + e*e)/(4.0 * a*a) - f / a);
        // if point in or inside circle,
        if ( (xp - xo)*(xp - xo) + (yp - yo)*(yp-yo) < r*r) {
            ans1 = r - sqrt ( (xp - xo)*(xp - xo) + (yp - yo)*(yp-yo)); // case 1
        } else {
            ans1 = sqrt ( (xp - xo)*(xp - xo) + (yp - yo)*(yp-yo)) - r; // case 1
        }
        
        double dist = hypot(xp - xo, yp - yo);
        double OP_y = yp - yo;
        double OP_x = xp - xo;
        double xi = r / dist * OP_x;
        double yi = r / dist * OP_y;
        
        ans2 = sqrt ( (xp - x1)*(xp - x1) + (yp - y1)*(yp-y1)); // case 2
        ans3 = sqrt ( (xp - x3)*(xp - x3) + (yp - y3)*(yp-y3)); // case 3
        
        double c1 = cross(x1, y1, xi, yi);
        double c2 = cross(xi, yi, x3, y3);
        double c3 = cross(x1, y1, x2, y2);
        double c4 = cross(x2, y2, x3, y3);
        
        if(c1 >= 0. && c2 >= 0. && c3 >= 0. && c4 >= 0.)
        {
               ans = min(ans1, min(ans2, ans3));
          }
          else if(c1 <= 0. && c2 <= 0. && c3 <= 0. && c4 <= 0.)
          {
               ans = min(ans1, min(ans2, ans3));
          }
          else ans = min(ans2, ans3);
        
        //printf("%lf %lf %lf %lf\n", xo, yo, r, ans);
        
        printf("Case %d: %.3lf\n", ++t, ans);
    };
    
    
	return 0;
}
