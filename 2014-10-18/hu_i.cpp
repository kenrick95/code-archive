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

/* Problem: 
 * URL: 
 */

int valid(int num) {
    return (1 <= num) && (num <= 8);
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int r1,c1,r2,c2,r3,c3;
    queue< pair<pair<int, int>, int > > q;
            // r,c; distance
    pair<pair<int, int>, int > head;
    pair<int, int> node;
    int dist[10][10];
    int ax[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int ay[8] = {-1,-1,-1,  0, 0,  1, 1, 1};
    int tc = 0;
	while(scanf("%d %d %d %d %d %d", &r1, &c1, &r2, &c2, &r3, &c3) != EOF) {
        tc++;
        for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
                dist[i][j] = 1000000007;
            }
        }
        
        // start [r1][c1]
        // end [r2][c2]
        // cannot go to [r3][c3]
        
        q.push(make_pair(make_pair(r1,c1), 0));
        dist[r1][c1] = 0;
        
        while (!q.empty()) {
            head = q.front();
            node = head.first;
            //printf("%d: %d %d\n", head.second, node.first, node.second);
            // visit neighbours
            for (int i = 0; i < 8; i++) {
                if (valid(node.first + ay[i]) && valid(node.second + ax[i])) {
                    if (dist[node.first][node.second] + 1 < dist[node.first + ay[i]][node.second + ax[i]]
                    && !((node.first + ay[i] == r3) && (node.second + ax[i] == c3))) {
                        dist[node.first + ay[i]][node.second + ax[i]] = dist[node.first][node.second] + 1;
                        q.push(make_pair(make_pair(node.first + ay[i], node.second + ax[i]), dist[node.first][node.second] + 1));
                    }
                }
            }
            q.pop();
        }
        printf("Case %d: %d\n", tc, dist[r2][c2]);
    }
	return 0;
}
