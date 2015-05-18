#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#define INF 1000000000000LL
 
typedef long long int64;
typedef unsigned long long qword;
using namespace std;
 
int x,y,z,n,m,i,j,k,p,q,e,v, source, dest, dist[10000];
 
struct da{
   int z;
} c[1000][1000];
int tx[1000];
bool comp(da a,da b) {
   return a.z>b.z;
}
int temp, temppath[1000], path[1000][1000], endpath[1000];

struct dat{
   int64 node,dist, tax;
   int lis[1000],endlis;
   bool operator < (dat A) const{ return dist>A.dist; }
   dat (int64 a,int64 b, int d) {
      node=a;
      dist=b;
      endlis=d;
   }
};
priority_queue<dat> pq;

int main(){
    scanf ("%d", &n);
    v = n;
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &x);
            c[i][j].z = x;
            /// from i to j, costs = x; if no road, -1
            e++;
            path[i][j] = 0;
        }
        endpath[i] = 0;
    }
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        tx[i] = x;
    }
    int begin = 0;
    while (scanf("%d", &source) != EOF) {
        if (source <= 0) break;
        if (begin == 0) {
            begin = 1;
        } else {
            printf("\n");
        }
        scanf("%d", &dest);
        
        for (y=0; y<=v+1; y++){
            dist[y]=1000000007;
        }
        dist[source]=0;
        path[source][1] = source;
        dat tem = dat(source, dist[source], 1);
        tem.lis[1] = source;
        pq.push(tem);
    
        while (!pq.empty() ) {
            dat now=pq.top();
            pq.pop();
            
            //cout<<"> "<<now.node<<" : "<<dist[now.node]<<" tx: "<<tx[now.node]<<"\n";
            for (i = 1; i<=n ;i++) {
                if (c[now.node][i].z != -1) {
                    if (dist[i] > (dist[now.node] + c[now.node][i].z + tx[i])) {
                        for (j = 1; j <= now.endlis; j++) {
                            temppath[j] = now.lis[j];
                        }
                        temppath[now.endlis + 1] = i;
                        
                        
                        dat tem = dat(i, (dist[now.node] + c[now.node][i].z + tx[i]), now.endlis + 1);
                        for (j = 1; j <= now.endlis + 1; j++) {
                            tem.lis[j] = temppath[j];
                        }
                        pq.push(tem);
                        
                        
                        dist[i] = (dist[now.node] + c[now.node][i].z + tx[i]);
                        
                        for (j = 1; j <= now.endlis + 1; j++)
                            path[i][j] = temppath[j];
                        endpath[i] = now.endlis + 1;
                        
                    }
                }
                
            }
            
        }
        printf("From %d to %d:\n", source, dest);
        
        printf("Path: ");
        for (int i = 1; i <= endpath[dest]; i++) {
            printf("%d", path[dest][i]);
            if (i != endpath[dest]) printf("-->");
        }
        printf("\n");
        printf("Total cost: %d\n", dist[dest] - tx[dest]);
        
    }
   return 0;
}
