#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: USACO US Open 2014 C
 * URL: 
 */
 
 // NOTE!!!! V starts from 1!!!
int V,E;
bool bipartite[50050], checked[50050], checkedn[50050];
int vertex[50050], num_vertex[50050];
map <pair<int, int>, bool> walk;



bool color(int i, int col, int f) {
    // to check bipartiteness
    
    if (vertex[i] != 0) {
        // visited;
        if (checked[i] && f) {
            return bipartite[i];
        }
        
        if (vertex[i] != col) {
            //printf(">>> %d %d\n", i, col);
            bipartite[i] = false;
            return false;
        } else {
            bipartite[i] = true;
            return true;
        }
    } else {
        bool ret = true;
        checked[i] = true;
        // 1. color
        vertex[i] = col;
        //printf("%d %d\n", i, col);
        // 2. visit the neighbours
        for (int j = 1; j <= V; j++) {
            if (walk.count(make_pair(i,j)) > 0) {
                ret = ret && color(j, -col, 0);
            }
        }
        bipartite[i] = ret;
        return ret;
    }
        
}

int nodes(int i, int f) {
    // number of nodes in a graph (of a forest)
    if (checkedn[i]) {
        if (f)
            return num_vertex[i];
        else
            return 0;
    } else {
        int ret = 1;
        // 1. tandai
        checkedn[i] = true;
        
        // 2. visit the neighbours
        for (int j = 1; j <= V; j++) {
            if (walk.count(make_pair(i,j)) > 0) {
                ret += nodes(j, 0);
            }
        }
        //printf("%d %d\n", i, ret);
        return ret;
    }
}
int update(int i, int col, int f) {
    if (num_vertex[i] == 0) {
        num_vertex[i] = col;
        for (int j = 1; j <= V; j++) {
            if (walk.count(make_pair(i,j)) > 0) {
                update(j, col, 0);
            }
        }
        return num_vertex[i];
    } else {
        return num_vertex[i];
    }
}

int main(){
	//freopen("decorate.in","r",stdin);
	//freopen("decorate.out","w",stdout);
	int i,j,k;
    
    scanf("%d", &V);
    scanf("%d", &E);
    memset(vertex, 0, sizeof(vertex));
    memset(bipartite, true, sizeof(bipartite));
    memset(checked, false, sizeof(checked));
    memset(checkedn, false, sizeof(checkedn));
    memset(num_vertex, 0, sizeof(num_vertex));
    int l = 0;
    for (i = 0; i < E; i++) {
        scanf("%d", &j);
        scanf("%d", &k);
        if (walk.count(make_pair(j,k)) > 0) l++; //in case of double path of two vertices
        walk[make_pair(j,k)] = true;
        walk[make_pair(k,j)] = true;
    }
    E = E - l;
    
    // BIPARTITE CHECK
    bool ret = true;
    for (i = 1; i <= V; i++) {
        ret = ret && color(i, 1, 1);
    }
    //printf("%d", ret);
    if (!ret) {
        printf("-1\n");
        return 0;
    }
    // CHECK NUMBER OF NODES
    int n = 0;
    for (i = 1; i <= V; i++) {
        n = nodes(i, 1);
        num_vertex[i] = n;
        //printf("%d %d ;", i, n);
        //update(i, n, 1);
    }
    //printf("\n\n");
    
    int J = 0;
    for (i = 1; i <= V; i++) {
        //printf("ook %d %d", i, J);
        J += (int) ceil(nodes(i, 1) / 2.0);
    }
    printf("%d\n", J);
    
	return 0;
}
