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
 
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int V, E;
    int f,t,d,a;
    int tc = 0;
    int did[511], dia[511];
    
    vector<pair<pair<int , int>, pair<int, int> > > ed[511];
    pair<pair<int , int>, pair<int, int> >  next;
    //((used?, to), (d_i, a_i)
    
    vector<int> fed[511];
    
    pair<pair<int, int>, int > head;
    priority_queue<pair<pair<int, int>, int >, vector< pair<pair<int, int>, int > >, greater<pair<pair<int, int>, int > > > pq;
    // (dist using d_i, dist using a_i), node
    
	while(scanf("%d %d", &V, &E) != EOF) {
        tc++;
        for (int i = 0; i <= V; i++) {
            dia[i] = did[i] =  1000000007;
            ed[i].clear();
        }
        for (int i = 0; i < E; i++) {
            scanf("%d %d %d %d", &f, &t, &d, &a);
            ed[f].push_back(make_pair(make_pair(0, t), make_pair(d, a)));
            fed[t].push_back(f);
        }
        
        did[1] = 0;
        pq.push(make_pair(make_pair(0, 0), 1));
        
        while (!pq.empty()) {
            head = pq.top();
            //printf("%d %d %d\n", head.second, did[head.second], head.first.first);
            
            // visit neighbours
            int len = ed[head.second].size();
            for (int i = 0; i < len; i++) {
                next = ed[head.second][i];
                //printf("  %d %d %d %d\n", head.first.first, next.second.first, next.first, did[next.first]);
                if (head.first.first + next.second.first < did[next.first.second]) {
                    did[next.first.second] = head.first.first + next.second.first;
                    //printf("      ay\n");
                    pq.push(make_pair(make_pair(did[next.first.second], 0), next.first.second));
                }
            }
            pq.pop();
        }
        
        int cur = V, br = 0;
        while (cur != 1) {
            int len = fed[cur].size();
            for (int i = 0; i < len; i++) {
                int len2 = ed[fed[cur][i]].size();
                for (int j = 0; j < len2; j++) {
                    if (did[fed[cur][i]] + ed[fed[cur][i]][j].second.first == did[cur]) {
                        // correct
                        ed[fed[cur][i]][j].first.first = 1;
                        cur = fed[cur][i];
                        br = 1;
                        break;
                    }
                }
                if (br) break;
            }
        }
        
        
        dia[1] = 0;
        pq.push(make_pair(make_pair(0, 0), 1));
        
        while (!pq.empty()) {
            head = pq.top();
            //printf("%d %d %d\n", head.second, did[head.second], head.first.first);
            
            // visit neighbours
            int len = ed[head.second].size();
            for (int i = 0; i < len; i++) {
                next = ed[head.second][i];
                //printf("  %d %d %d %d\n", head.first.first, next.second.first, next.first, did[next.first]);
                if (next.first.first == 1) {
                    if (head.first.first + next.second.first + next.second.second < dia[next.first.second]) {
                        dia[next.first.second] = head.first.first + next.second.first + next.second.second;
                        //printf("      ay\n");
                        pq.push(make_pair(make_pair(dia[next.first.second], 0), next.first.second));
                    }
                } else {
                    if (head.first.first + next.second.first < dia[next.first.second]) {
                        dia[next.first.second] = head.first.first + next.second.first;
                        //printf("      ay\n");
                        pq.push(make_pair(make_pair(dia[next.first.second], 0), next.first.second));
                    }
                }
                
                
            }
            pq.pop();
        }
        /*for (int i = 1; i <= V; i++) {
            printf("%d %d\n", dia[i], did[i]);
        }*/
        
        printf("Case %d: %d\n", tc, did[V]+dia[V]);
    }
	return 0;
}
