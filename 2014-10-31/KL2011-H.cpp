//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */

struct da {
    int x,y;
} c[1023];
vector<int> ed[1023];
queue<int> q;
int dist[1023];

int t,T,N,st,en;
double l1,l2, cdis;

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d %d %lf %lf", &N, &st, &en, &l1, &l2);
        //printf("%d %d %d %lf %lf\n", N, st, en, l1, l2);
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &c[i].x, &c[i].y);
            //printf("%d %d %d\n", i, c[i].x, c[i].y);
        }
        for (int i = 0; i < N; i++) {
            //printf("[%d]: ", i);
            for (int j = 0; j < N; j++) {
                // if can walk, then build the graph
                //if (abs(l*l - ((c[i].x - c[j].x)*(c[i].x - c[j].x) + (c[i].y - c[j].y)*(c[i].y - c[j].y))) <= 0.001) {
                cdis = hypot(c[i].x - c[j].x, c[i].y - c[j].y);
                if ((l1 + l2 >= cdis) && (cdis >= max(0, max(l1, l2) - min(l1, l2)))) {
                //if ((l1 + l2 >= cdis) && (cdis + l1 >= l2) && (cdis + l2 >= l1)) {
                    ed[i].push_back(j);
                    //printf("%d ", j);
                }
                //printf("(%lf )", cdis);
            }
            //printf("\n");
            dist[i] = 100000007;
        }
        
        dist[st-1] = 0;
        q.push(st-1);
        while(!q.empty()) {
            int head = q.front(); q.pop();
            if (head == en-1) break;
            int sz = ed[head].size();
            for (int i = 0; i < sz; i++) {
                if (dist[ed[head][i]] > dist[head] + 1) {
                    dist[ed[head][i]] = dist[head] + 1;
                    q.push(ed[head][i]);
                }
            }
        }
        while (!q.empty()) q.pop();
        if (dist[en-1] >= 100000007) {
            printf("Impossible\n");
        } else {
            printf("%d\n", dist[en-1]);
        }
}
	return 0;
}
