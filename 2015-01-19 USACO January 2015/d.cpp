#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
//#include <bits/stdc++.h>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */
struct da {
    int id;
    int cost1, cost2;
    da(int _id, int _cost1, int _cost2) { id = _id; cost1 = _cost1; cost2 = _cost2; };
};
struct node {
    vector <da> to;
} A[32];
int N, M, from, to, cost1, cost2;

vector<int> val1, val2;

void f(int cur, int cost1, int cost2) {
    if (cur == N) {
        val1.push_back(cost1);
        val2.push_back(cost2);
    }
    for (int i = 0; i < A[cur].to.size(); i++) {
        da to = A[cur].to[i];
        if (to.id > cur) {
            f(to.id, cost1 + to.cost1, cost2 + to.cost2);
        }
    }
}

int main(){
    freopen("meeting.in","r",stdin);
    freopen("meeting.out","w",stdout);
    scanf("%d %d", &N, &M);
    // N vertices, M edges
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &from, &to, &cost1, &cost2);
        A[from].to.push_back(da(to, cost1, cost2));
    }
    f(1, 0, 0);
    /*for (int i = 0; i < val1.size(); i++) {
        printf("%d %d\n", val1[i], val2[i]);
    }*/
    sort(val1.begin(), val1.end());
    sort(val2.begin(), val2.end());
    int i = 0, j = 0;
    while (i < val1.size() && j < val2.size()) {
        if (val1[i] == val2[j]) {
            printf("%d\n", val1[i]);
            return 0;
        } else if (val1[i] < val2[j]) {
            i++;
        } else {
            j++;
        }
    }
    printf("IMPOSSIBLE\n");
    
    
    return 0;
}
