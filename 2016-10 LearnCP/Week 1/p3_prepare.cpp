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
 * @problem Prepare Yourself to Competitions!
 * @url     https://courses.edx.org/courses/course-v1:ITMOx+I2CPx+3T2016/courseware/5f7ded3dde75420f8da894830d69e7e4/05c1037ba1e2450e931dfbd1c2d1856d/
 * @status  
 */


int main(){
    freopen("prepare.in","r", stdin);
    freopen("prepare.out","w", stdout);
    int n, a[128], b[128];
    vector<pair<int, int> > ab, ba;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);

        ab.push_back(make_pair(a, b));
        ba.push_back(make_pair(b, a));
    }
    sort(ab.begin(), ab.end());
    sort(ba.begin(), ba.end());

    // it's not that simple ._.

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ab[i].first == i) {
            ans += a[i];
        } else if (max_b_i == i) {
            ans += b[i];
        } else {
            ans += max(a[i], b[i]);
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
