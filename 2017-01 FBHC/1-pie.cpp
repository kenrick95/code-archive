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
#define PI 3.14192653589793F

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem 
 * @url     
 * @status  
 */


int main(){
    freopen("progress_pie.txt","r",stdin);
    freopen("progress_pie.out","w",stdout);
    int T;
    int P, X, Y;
    scanf("%d\n", &T);
    for (int t = 0; t < T; ++t)
    {
        scanf("%d %d %d\n", &P, &X, &Y);
        bool white = true;

        double in_cicle = (X - 50.) * (X - 50.) + (Y - 50.) * (Y - 50.);
        // printf("\nin_circle: %lf\n", in_cicle);
        // printf("%d %d %d\n", P, X, Y);
        if (in_cicle <= 2500.) {
            if (P == 0) {
                // nothing
            } else if (P == 50) {
                if (X >= 50.) {
                    white = false;
                }
            } else if (P == 100) {
                white = false;

            } else if (P < 50) {
                double grad = tan(PI / 2. - P / 50. * PI);
                double line = grad * (X - 50.);
                // printf("grad: %lf\nline: %lf\n\n", grad, line);
                if (X >= 50. && (Y - 50.) >= line) {
                    white = false;
                }
            } else {
                // another case
                double grad = tan(PI / 2. - (P - 50) / 50. * PI);
                double line = grad * (X - 50.);
                // printf("grad: %lf\nline: %lf\n\n", grad, line);
                if (X <= 50. && (Y - 50.) <= line) {
                    white = false;
                } else if (X >= 50.) {
                    white = false;
                }
            }
        }

        printf("Case #%d: %s\n", (t + 1), white ? "white" : "black");
    }
    


    // (x - 50)^2 + (y - 50)^2 > 0 --> white
    // else
       // P < 50
          // x >= 50 && y - 50 >= tan(pi / 2 - P / 50 * pi) (x - 50) --> black
       // P > 50
    return 0;
}
