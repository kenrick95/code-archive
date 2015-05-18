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


int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int R, N;
    double r, I, E, PI = 3.14159265358979323846;
    
	while (scanf("%d %d", &R, &N) != EOF) {
        if (N == 1) {
            r = R;
            I = 0.0;
            E = 0.0;
        } else if (N == 2) {
            r = R / 2.0;
            I = 0.0;
            E = PI * R * R - PI * N * r * r;
        } else {
            r = R * sin (PI/ N) / ( 1+ sin (PI / N));
            I = N * (sqrt((R-r)*(R-r) - r*r) * r - ((1.0/2.0 - 1.0/N) * PI * r *r));
            E = PI * R * R - I - PI * N * r * r;
        }
        printf("%.10lf %.10lf %.10lf\n", r, I, E);
    }
	return 0;
}
