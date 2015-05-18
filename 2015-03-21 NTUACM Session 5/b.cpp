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
    int dest;
    int gear;
    bool mark;
    
    da(int A, int B, bool C) {
        dest = A;
        gear = B;
        mark = C;
    };
};
struct da2 {
    int node;
    int dist;
    int curgear;
    int gear;
    bool operator < (da2 A) const{ return gear > A.gear || (gear == A.gear && dist > A.dist); }
    da2(int A, int B, int C, int D) {
     
     node = A;
     dist = B;
     curgear = C;
     gear = D;
    };
};
    int V, E;
    int x, y;
    vector<da> ma[10010];
    priority_queue <da2> q;
    int S, G;
int PQ() {
    while(!q.empty()) {
        da2 head = q.top();
        
        //printf("[%d] %d <%d> %d\n", head.node, head.curgear, head.gear, head.dist);
        
        if (head.node == G) {
            //printf("%d\n", head.gear);
            return head.gear;
            break;
        }
        
        for (int i = 0; i < ma[head.node].size(); i++) {
            //printf("    [%d] %d %d\n", i, ma[head.node][i].dest, ma[head.node][i].gear);
            if (ma[head.node][i].mark == false) {
                ma[head.node][i].mark = true;
                
                if (ma[head.node][i].gear == head.curgear) { // same gear
                    q.push(da2(ma[head.node][i].dest, head.dist+1, head.curgear, head.gear));
                } else { // change gear
                    q.push(da2(ma[head.node][i].dest, head.dist+1, -head.curgear, head.gear + 1));
                }
            }
        }
        q.pop();
    }
    return INF;
}
int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &x, &y);
        ma[x].push_back(da(y, 1, false));
        ma[y].push_back(da(x, -1, false));
    }
    scanf("%d %d", &S, &G);
    
    int ans = 0;
    
    q.push(da2(S, 0, 1, 0));
    ans = PQ();
    
    for (int i = 0; i < E; i++) { 
        for (int j = 0; j < ma[i].size(); j++) {
            ma[i][j].mark = false;
        }
    }
    q.push(da2(S, 0, 0, 0));
    ans = min(ans, PQ());
    
    printf("%d\n", ans);
    
    return 0;
}
