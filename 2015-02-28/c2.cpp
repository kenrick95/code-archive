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

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        int k;
        int x,y;
    

        //1 let dist be a |V| × |V| array of minimum distances initialized to ∞ (infinity)
        int dist[128][128];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = 1000000007;
        //2 for each vertex v
        for (int i = 1; i <= n; i++)
        //3    dist[v][v] ← 0
            dist[i][i] = 0;

        //4 for each edge (u,v)
        for (int i = 1; i <= n; i++) {
            scanf("%d", &k);
            for (j = 0; j < k; j++) {
                scanf("%d %d", &x, &y);
                //5    dist[u][v] ← w(u,v)  // the weight of the edge (u,v)
                dist[i][x] = y;
            }
        }
        /*for (i = 1; i <= n; i++) {
            int size = person[i].size();
            for (int j = 0; j < size; j++) {
                printf("%d %d", person[i][j].first, person[i][j].second);
            }
            printf("\n");
        }*/

        //6 for k from 1 to |V|
        for (int x = 1; x <= n; x++)
        //7    for i from 1 to |V|
            for (int i = 1; i <= n; i++)
        //8       for j from 1 to |V|
                for (int j = 1; j <= n; j++)
        //9          if dist[i][j] > dist[i][k] + dist[k][j] 
                    if (i != j && dist[i][j] > dist[i][x] + dist[x][j])
        //10             dist[i][j] ← dist[i][k] + dist[k][j]
                        dist[i][j] = dist[i][x] + dist[x][j];
        //11         end if

        int mint = -1, tim = 1000000007, tmin;
        for (int i = 1; i <= n; i++) {
            tmin = 0;
            for (int j = 1; j <= n; j++) {
                //printf("%d ", dist[i][j]);
                if (i != j && tmin < dist[i][j])
                    tmin = dist[i][j];
            }
            if (tim > tmin) {
                tim = tmin;
                mint = i;
            }
            //printf("\n");
        }
        if (tim == 1000000007) 
            printf("disjoint\n");
        else 
            printf("%d %d\n", mint, tim);
    }
    return 0;
}

