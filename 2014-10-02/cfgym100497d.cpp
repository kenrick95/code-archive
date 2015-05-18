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

/* Problem: 
 * URL: 
 */


int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int n,m;
    int stateRotate = 0;
    /* 0: normal
     * 1: CW 90deg
     * 2: CW 180deg
     * 3: CW 270 deg
     * 
     * 
     * */
    int stateMirror = 0;
    /* 0: normal
     * 1: VER
     * 2: HOR
     * 3: VER + HOR
     * 
     * */
    char query[255];
	scanf("%d %d", &n, &m);
    for (int t = 0; t < m; t++) {
        scanf("%s", query);
        if (strcmp(query, "REPLACE") == 0) {
            scanf("%d %d", &i, &j);
            for (int y = 0; y < 3; y++) {
                for (int x = 0; x < 3; x++) {
                    scanf("%c", &ch);
                }
                scanf("\n");
            }
            
        } else if (strcmp(query, "ROTATE") == 0) {
            scanf("%s", query);
            
        } else /*if (strcmp(query, "MIRROR") == 0)*/ {
            scanf("%s", query);
            
        }
    }
	return 0;
}
