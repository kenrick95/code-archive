#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */
int p, q;
int T;
vector <pair<int, int> > node[1000010];
bool vis[1000010];
int sav[1000010];

int64 f(int i, int k, bool first) {
    if (i == 1 && !first) {
        bool valid = vis[k];
        /*for (int j = 1; j <= p; j++) {
            
            if (!vis[j]) {
                valid = false;
            }
        }*/
        return (valid) ? 0 : 1000000010;
    } else {
        int64 temp = 100000000000010LL, temp2;
        int vlen = node[i].size();
        vis[i] = true;
        for (int j = 0; j < vlen; j++) {
            temp2 = f(node[i][j].first, k, false) + node[i][j].second;
            if (temp2 < temp) {
                temp = temp2;
            }
        }
        vis[i] = false;
        return temp;
    }
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d", &T);
    int x,y,z;
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &p, &q);
        for (int i = 1; i <= p; i++) {
            vis[i] = false;
        }
        for (int i = 0; i < q; i++) {
            scanf("%d %d %d", &x, &y, &z);
            node[x].push_back(make_pair(y, z));
        }
        int64 sum = 0;
        for (int i = 2; i <= p; i++) {
            sum += f(1, i, true);
        }
        printf("%I64d\n", sum);
        for (int i = 0; i < q; i++) {
            node[x].clear();
        }
    }
	return 0;
}
