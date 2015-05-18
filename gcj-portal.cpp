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
 
/* Problem: Portal
 * URL: p43-56 (GCJ Round 3 2008)
 */
 
bool ma[20][20];
/*true: bisa dilewati
 *false:dinding
 * */
char t;
int r,c,x,y,xo,yo,xd,yd,i,j,ans;
int dist[20][20];
int ax[4]={1,0,-1,0};
int ay[4]={0,1,0,-1};
 
struct da{
   int x,y,dist;
   bool operator < (da A) const{ return dist>A.dist; }
   da (int a,int b,int c) {
      x=a;
      y=b;
      dist=c;
   }
};
 
priority_queue<da> pq;
 
 
int main(){
    int T, tc;
    scanf("%d", &T);
    for (tc = 1; tc <= T; tc++ ) {
    
   scanf("%d %d%*c",&r,&c);
   memset(ma,false,sizeof ma);
   for (y=1;y<=r;y++){
      for (x=1;x<=c;x++){
         scanf("%c",&t);
         if (t=='O') {
            xo=x;
            yo=y;
            ma[y][x]=true;
         } else if (t=='X') {
            xd=x;
            yd=y;
            ma[y][x]=true;
         } else if (t=='#'){
            ma[y][x]=false;
         } else if (t=='.'){
            ma[y][x]=true;
         }
         //printf("%c",t);
      }
      scanf("%*c");
      //printf("\n");
   }
   for (y=0; y<=r+1;y++){
      for (x=0; x<=c+1; x++) {
         dist[y][x]=1000000007;
      }
   }
   dist[yo][xo]=0;
   pq.push(da(xo,yo,dist[yo][xo]));
   /*if (dist[j[now.node][i]] > dist[now.node] + jc[now.node][i]) {
            pq.push(da(j[now.node][i], now.dist + jc[now.node][i]));
            dist[j[now.node][i]] = dist[now.node] + jc[now.node][i];
         }*/
   while (!pq.empty() ) {
      da now=pq.top();
      pq.pop();
      for (i=0;i<=3;i++) {
         if ((dist[now.y+ay[i]][now.x+ax[i]] > dist[now.y][now.x] + 1) && (ma[now.y+ay[i]][now.x+ax[i]])) {
            pq.push(da(now.x+ax[i], now.y+ay[i], now.dist+1));
            dist[now.y+ay[i]][now.x+ax[i]] = dist[now.y][now.x] + 1;
         } else if (!(ma[now.y+ay[i]][now.x+ax[i]])) {
            for (j=0;j<=3;j++){
               y=now.y;
               x=now.x;
               while(ma[y][x]) {
                  x+=ax[j];
                  y+=ay[j];
               }
               x-=ax[j];
               y-=ay[j];
               if (dist[y][x]> dist[now.y][now.x] +1) {
                  pq.push(da(x,y,now.dist+1));
                  dist[y][x]= dist[now.y][now.x] +1;
               }
            }
             
             
         }
      }
   }
  /* for (y=0;y<=r+1;y++) {
      for (x=0;x<=c+1;x++){
         printf("%d ",dist[y][x]);
      }
      printf("\n");
   }*/
   ans = dist[yd][xd];
   
   printf("Case #%d: ", tc);
   if (ans == 1000000007) {
      printf("THE CAKE IS A LIE\n");
   } else {
      printf("%d\n",ans);
   }
   
    }
   
   return 0;
}
