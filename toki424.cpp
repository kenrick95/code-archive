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
 
/* Problem: Muka Bebek
 * URL: http://tokilearning.org/training/7/chapter/76/problem/424
 */
 
int v,e,n,m,x,y,z,ne;
//int cost[100][100];
int par[10001], rank[10001];
int used[10001];
 
struct da {
   int f,t,z;
} c[10001];
bool comp(da a, da b) {
    return a.z < b.z;
}

void make_set(int u) {
    par[u] = u;
    rank[u] = 0;
}
int find_set(int u) {
    if (par[u] == u) {
        return u;
    } else {
        par[u] = find_set(par[u]);
        return par[u];
    }
}
void merge_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    
    if (rank[u] < rank[v]) {
        par[v] = u;
    } else if (rank[u] > rank[v]) {
        par[u] = v;
    } else {
        par[u] = v;
        rank[v]++;
    }
}
int mst(int x){
    int u, y, ms=0;
    for (int n = 1; n <= e; n++){
      //cout<<c[n].z<<" "<<c[n].f<<" "<<c[n].t<<" "<<used[n]<<endl;
        u = find_set(c[n].f);
        y = find_set(c[n].t);
        if (u != y && used[n] > -1) {
            ms += c[n].z;
            if (x == 0) {
                used[n] = 1;
            }
            merge_set(c[n].f,c[n].t);
        }
    }
    //Validity of MST
    //cout<<endl;
    for (int n = 1; n <= v; n++){
        find_set(n);
    }
    for (int n = 2; n <= v; n++){
        // cout<<par[n]<<endl;
        if (par[n] != par[n-1]){
            ms = -1;
        }
    }
    //cout<<endl;
    return ms;
}
int main(){
    scanf("%d", &v);
    e = v * v;
    n = 1;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            scanf("%d", &z);
            if (z == 0) continue;
            c[n].f = i;
            c[n].t = j;
            c[n].z = z;
            used[n] = 0;
            n++;
        }
    }
   sort(c + 1, c + e + 1, comp);
   //MST
   for (n = 1; n <= v; n++) {
      make_set(n);
   }
   int ms = mst(0);
   //End MST
   printf("%d\n", ms);
   
   return 0;
}
