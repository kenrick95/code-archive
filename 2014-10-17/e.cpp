#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
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
    queue <int> q;
    priority_queue<int, vector<int>, less<int> > pq;
    stack <int> st;
    int n, type, x;
    bool iq, ipq, ist;
    
	while (scanf("%d", &n) != EOF) {
        while (!q.empty()) q.pop();
        while (!pq.empty()) pq.pop();
        while (!st.empty()) st.pop();
        
        iq = true;
        ipq = true;
        ist = true;
        
        for (int i = 0; i < n; i++) {
            //printf("[%d]\n", i);
            scanf("%d %d", &type, &x);
            
            if (type == 1) {
                q.push(x);
                pq.push(x);
                st.push(x);
            } else if (type == 2) {
                if (!q.empty()) {
                    if (iq && x != q.front()) {
                        iq = false;
                    }
                    q.pop();
                } else {
                    iq = false;
                }
                if (!pq.empty()) {
                    if (ipq && x != pq.top()) {
                        ipq = false;
                    }
                    pq.pop();
                } else {
                    ipq = false;
                }
                if (!st.empty()) {
                    if (ist && x != st.top()) {
                        ist = false;
                    }
                    st.pop();
                 } else {
                    ist = false;
                 }
                //printf("[%d : %d]\n", x, pq.top());
                
                
               
            }
               // printf("[%d]\n", ipq);
        }
       // printf("lol");
        if (!iq && !ipq && !ist) {
            printf("impossible\n");
        } else {
            if (ipq && !iq && !ist) {
                printf("priority queue\n");
            } else if (!ipq && iq && !ist) {
                printf("queue\n");
            } else if (!ipq && !iq && ist) {
                printf("stack\n");
            } else {
                printf("not sure\n");
            }
        }
//printf("lol2");
    }
	return 0;
}
