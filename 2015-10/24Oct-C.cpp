#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem
 * @url
 * @status
 */

struct da {
    int v;
    int f;
    da(int _v, int _f) : v(_v), f(_f) {};
    da() {v = f = 0;};
    bool operator < (da A) const {
        return f < A.f || (f == A.f && v < A.v);
    }
};
struct sav {
    int v[3];
    sav(int v1, int v2, int v3) {
        v[0] = v1;
        v[1] = v2;
        v[2] = v3;
        sort(v, v + 3);
    }
    sav() {
        v[0] = v[1] = v[2] = 0;
    }
};
int n;
map<int, int> r;
priority_queue<da> pq;
vector<sav> v;

int main(){
    int x;
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (r.count(x) > 0) {
            r[x] += 1;
        } else {
            r[x] = 1;
        }
    }
    for (map<int,int>::iterator it=r.begin(); it!=r.end(); ++it) {
        pq.push(da(it->first, it->second));
        //printf("%d %d\n", it->first, it->second);

    }
    while (!pq.empty()) {
        da h1 = pq.top();
        pq.pop();

        if (pq.empty())
            break;
        da h2 = pq.top();
        pq.pop();

        if (pq.empty())
            break;
        da h3 = pq.top();
        pq.pop();

        v.push_back(sav(h1.v, h2.v, h3.v));

        h1.f--;
        h2.f--;
        h3.f--;

        if (h1.f > 0)
            pq.push(h1);
        if (h2.f > 0)
            pq.push(h2);
        if (h3.f > 0)
            pq.push(h3);
    }
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++) {
        printf("%d %d %d\n", v[i].v[2], v[i].v[1], v[i].v[0]);
    }

    return 0;
}
