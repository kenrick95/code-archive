#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#define INF 1000000000000LL
 
typedef long long int64;
typedef unsigned long long qword;
using namespace std;
 
int x,y,z,n,m,i,j,k,p,q,e,v;
int md=1000000000;
int par[100100],rank[100100],sz[100100];
 
struct da{
   int f,t, z;
} c[100100];
bool comp(da a,da b) {
   return a.z>b.z;
}
void make_set(int u) {
   par[u]=u;
   rank[u]=0;
}
int find_set(int u) {
   if (par[u]==u) {
      return u;
   } else {
      par[u]=find_set(par[u]);
      return par[u];
   }
}
void merge_set(int u,int v) {
   u=find_set(u);
   v=find_set(v);
   //cout<<sz[u]<<" "<<sz[v]<<endl;
   if (rank[u]<rank[v]) {
      par[v]=u;
      sz[u]+=sz[v];
   } else if (rank[u]>rank[v]) {
      par[u]=v;
      sz[v]+=sz[u];
   } else {
      par[u]=v;
      sz[v]+=sz[u];
      rank[v]++;
   }
   //cout<<sz[u]<<" "<<sz[v]<<endl<<endl;
}
int size_set(int u) {
   //cout<<u<<"-"<<par[u]<<" ";
   if (par[u]==u) {
      return sz[u];
   } else {
      sz[u]=size_set(par[u]);
      return sz[u];
   }
   //cout<<endl;
}
 
int main(){
    scanf ("%d", &n);
    v = n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &x);
            if (x != -1) {
                c[i].f = i;
                c[i].t = j;
                c[i].z = x;
                e++;
            }
        }
    }
        
    
   int64 total=0;
   for (i=1;i<=v;i++){
      sz[i]=1;
      par[i]=i;
   }
   for (i=1;i<=e;i++){
      scanf("%d %d %d",&x,&y,&z);
      c[i].f=x;
      c[i].t=y;
      c[i].z=z;
      total=(total + z);
   }
   sort(c+1,c+e+1,comp);
   int u,y;
   int64 ou=0;
   for (int n=1;n<=e;n++){
      //cout<<c[n].z<<" "<<c[n].f<<" "<<c[n].t<<" "<<used[n]<<endl;
      u=find_set(c[n].f);
      y=find_set(c[n].t);
      if (u!=y) {
         ou = (ou + (total * (size_set(c[n].f) * size_set(c[n].t) %md)) %md) %md;
         merge_set(c[n].f,c[n].t);
      }
      total -= c[n].z;
   }
   //Validity of MST
   for (int n=1;n<=v;n++){
      find_set(n);
      //printf("%d\n",size_set(n));
   }
   printf("%lld\n",ou);
   return 0;
}
