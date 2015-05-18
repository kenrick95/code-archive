#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
//#include <bits/stdc++.h>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */

    int n, i, j;
    int k[128];
    int x,y;
    // <node, time>
    vector<pair<int, int> > person[128];
    bool infl[128];
struct da{
   int x,dist;
   bool operator < (da A) const{ return dist>A.dist; }
   da (int a,int c) {
      x=a;
      dist=c;
   }
};
priority_queue<da> pq;

int f(int p) {
    //bool infl[128];
    //memset(infl, 0, sizeof infl);
    int ret = 0;
    
    int dist[128];
    for (int i = 1; i <= n; i++) {
        dist[i] = 100000007;
    }
    // <cost so far, node>
    priority_queue<da> q;
    q.push(da(p, 0));
    //infl[p] = true;
    dist[p] = 0;

    
    while (!q.empty()) {
        da head = q.top();
        //printf("[%d %d]", head.first, head.second);
        q.pop();
        int size = k[head.x];
        for (int i = 0; i < size; i++) {
        
            if (head.dist
                + person[head.x][i].second
                < dist[person[head.x][i].first]) {
                    
                q.push(da(person[head.x][i].first, head.dist + person[head.x][i].second));
                dist[person[head.x][i].first] = head.dist + person[head.x][i].second;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ret = max(ret, dist[i]);
    }
    //printf("{{%d: %d}}\n", p, ret);
    
    
    return ret;
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        for (i = 1; i <= n; i++) {
            person[i].clear();
            scanf("%d", &k[i]);
            for (j = 0; j < k[i]; j++) {
                scanf("%d %d", &x, &y);
                person[i].push_back(make_pair(x,y));
            }
        }
        /*for (i = 1; i <= n; i++) {
            int size = person[i].size();
            for (int j = 0; j < size; j++) {
                printf("%d %d", person[i][j].first, person[i][j].second);
            }
            printf("\n");
        }*/
        
    
        int mint = -1, ttim, tim = 100000007;
        for (i = 1; i <= n; i++) {
            //memset(infl, 0, sizeof infl);
            //infl[i] = true;
            ttim = f(i);
            if (ttim < tim) {
                tim = ttim;
                mint = i;
            }
            
        }
        if (mint == -1) 
            printf("disjoint\n");
        else 
            printf("%d %d\n", mint, tim);
    }
    return 0;
}

