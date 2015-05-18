#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define INF 92233720368547758LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */

int V, E;
int p[1023];
vector <pair<int, int> > ma[1023];
// first: dest; second: cost
int64 sav[1023][127];
bool vis[1023];

int64 f(int cur, int64 left, int final_dest, int64 cap) {
    
    if (left < 0 || left > cap) {
        return INF;
    } else if (cur == final_dest) {
        return 0;
    } else {
        if (vis[cur]) {
            return INF;
        }
        if (sav[cur][left] > -1) {
            return sav[cur][left];
        }
        int len = ma[cur].size();
        int E_cost = 0, E_next = 0;
        int64 tmin = INF;
        for (int i = 0; i < len; i++) {
            E_next = ma[cur][i].first;
            E_cost = ma[cur][i].second;
            if (cap < E_cost) continue;
            
            vis[E_next] = true;
            for (int64 j = 0; j <= (cap - left); j++) {
                tmin = min (tmin, f(E_next, left - E_cost + j, final_dest, cap) + j * p[cur]);
            }
            vis[E_next] = false;
            /*
            if (left >= E_cost) {
                for (int j = 0; j <= (cap - left); j++) {
                    tmin = min (tmin, f(E_next, left - E_cost + j, final_dest, cap) + j * p[cur]);
                }
            } else {
                for (int j = (E_cost - left); j <= (cap - left); j++) {
                    tmin = min (tmin, f(E_next, left - E_cost + j, final_dest, cap) + j * p[cur]);
                }
            }*/
        }
        sav[cur][left] = tmin;
                //printf(" \n", cur, left, tmin);
        return tmin;
    }
    
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) {
        scanf("%d", &p[i]);
    }
    int x,y,z;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &x, &y, &z);
        if (x != y) ma[x].push_back(make_pair(y, z));
    }
    int s, e, c, q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        for (int j = 0; j <= V; j++) {
            for (int k = 0; k <= 101; k++) {
                sav[j][k] = -1;
            }
        }
        memset(vis, 0, sizeof vis);
        
        //memset(sav, -1, sizeof sav);
        scanf("%d %d %d", &c, &s, &e);
        int64 ans = f(s, 0, e, c);
        if (ans == INF) {
            printf("impossible\n");
        } else {
            printf("%I64d\n", ans);
        }
       
    }
	return 0;
}
