#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#include <set>
#define DEBUG printf("TEST\n")
#define HOLD scanf("%*c%*c")

using namespace std;

double A[8], B[8];
int sa, sb;

double f(int i, int a, int b) {
    
     if(a > sa || b > sb) return 0.;
     
     int left = 5 - (i / 2);
     if(left == 0) {
          if(a == sa && b == sb) return 1.;
          else return 0.;
     } else if(i % 2 == 1) {
          if(b + left < a)  {
               if(a == sa && b == sb) return 1.;
               else return 0.;
          }
     } else {
          if(a + left < b) {
               if(a == sa && b == sb) return 1.;
               else return 0.;
          }
     }
     double ans = 0.;
     int idx = (i / 2);
    printf("%d %d %d\n", i, a, b);
     
     if(i % 2 == 1) {
          ans += f(i + 1, a, b + 1) * B[idx];
          ans += f(i + 1, a, b) * (1. - B[idx]);
     } else {
          ans += f(i + 1, a + 1, b) * A[idx];
          ans += f(i + 1, a, b) * (1. - A[idx]);
     }
     //printf("%d %d %d: %lf\n", i, a, b, ans);
     return ans;
}

int main()
{
     
     int tc = 0;
     while(scanf("%lf", &A[0]) != EOF)
     {
          for(int i = 1; i < 5; ++i) scanf("%lf", &A[i]);
          for(int i = 0; i < 5; ++i) scanf("%lf", &B[i]);
          scanf("%d%*c%d", &sa, &sb);
          
          printf("Case %d: %.2lf%c\n", ++tc, f(0, 0, 0) * 100, '%');
     }
     
     return 0;
}
