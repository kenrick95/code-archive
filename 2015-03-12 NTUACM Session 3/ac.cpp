#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
//#include <bits/stdc++.h>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */

int t,s,n,m,x,y,z,a[1024];
int ans;
vector<pair<int, int> > seq;
   
int main(){
    scanf("%d",&t);
    bool first = true;
    for (s=1;s<=t;s++){
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d ", &a[i]);
        sort(a, a + n);
      
        seq.clear();
        ans = 0;
        if (n == 1) {
            ans = a[0];
            seq.push_back(make_pair(a[0], -1));
        } else if (n == 2) {
            ans = max(a[0], a[1]);
            seq.push_back(make_pair(a[0], a[1]));
        } else {
            //etc.
            int ta, tb;
             while (n > 1) {
                if (n==3) {
                    ans += a[0] + a[1] + a[2];
                    seq.push_back(make_pair(a[0], a[2]));
                    seq.push_back(make_pair(a[0], -1));
                    seq.push_back(make_pair(a[0], a[1]));
                    break;
                } else if (n==2) {
                    ans += a[1];
                    seq.push_back(make_pair(a[0], a[1]));
                    break;
                }
                ta = a[n-1] + a[0] + a[n-2] + a[0];
                tb = a[1] + a[0] + a[n-1] + a[1];
                if (ta<tb) {
                    ans += ta;
                    seq.push_back(make_pair(a[n-1], a[0]));
                    seq.push_back(make_pair(a[0], -1));
                    seq.push_back(make_pair(a[n-2], a[0]));
                    seq.push_back(make_pair(a[0], -1));
                } else {
                    ans += tb;
                    seq.push_back(make_pair(a[0], a[1]));
                    seq.push_back(make_pair(a[1], -1));
                    seq.push_back(make_pair(a[n-1], a[n-2]));
                    seq.push_back(make_pair(a[0], -1));
                }
                n -= 2;
            }
        }
        if (!first) printf("\n");
        first = false;
        printf("%d\n",ans);
        int sz = seq.size();
        for (int i = 0; i < sz; i++) {
            if (seq[i].second > -1) printf("%d %d\n", seq[i].first, seq[i].second);
            else printf("%d\n", seq[i].first);
        }
    }
    return 0;
}
