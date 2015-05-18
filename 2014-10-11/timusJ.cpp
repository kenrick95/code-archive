#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */


struct da{
   int value, origin;
   bool operator < (da A) const{ return value < A.value; }
} oA[1010], oB[1010];
vector <pair<int, int> > vA[1023], vB[1023];

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int n, x;
	scanf("%d", &n);
    // 1. counting sort
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        //oA[i].value = x;
        //oA[i].origin = i+1;
        
        vA[x].push_back(make_pair(x, i+1));
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        //oB[i].value = x;
        //oB[i].origin = i+1;
        
        vB[x].push_back(make_pair(x, i+1));
    }
    //sort(oA, oA+n);
    //sort(oB, oB+n);
    
    /*for (int i = 0; i < n; i++) {
        printf("%d %d\n", oA[i].value, oB[i].value);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", oA[i].origin, oB[i].origin);
    }*/
    // 2. print those with same value, i.e. balanced
    int v = 0, cnt = 0;
    while (v <= 6) {
        if (vA[v].size() > 0 && vB[v].size() > 0) {
            cnt++;
            printf("%d %d\n", vA[v].back().second, vB[v].back().second);
            vA[v].pop_back();
            vB[v].pop_back();
        } else {
            v++;
        }
    }
    
    // 3. print the rest; (not sure)
    int v1 = 0, v2 = 0;
    while (v1 <= 6 && v2 <= 6) {
        if (vA[v1].size() > 0 && vB[v2].size() > 0) {
            cnt++;
            printf("%d %d\n", vA[v1].back().second, vB[v2].back().second);
            vA[v1].pop_back();
            vB[v2].pop_back();
        } else if (vA[v1].size() == 0) {
            v1++;
        } else if (vB[v2].size() == 0) {
            v2++;
        }
    }
    
	return 0;
}
