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
 * @problem A + B^2
 * @url     https://courses.edx.org/courses/course-v1:ITMOx+I2CPx+3T2016/courseware/5f7ded3dde75420f8da894830d69e7e4/05c1037ba1e2450e931dfbd1c2d1856d/
 * @status  
 */


int main(){
    freopen("aplusbb.in","r", stdin);
    freopen("aplusbb.out","w", stdout);
    int64 a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", a + b * b);
    
    return 0;
}
