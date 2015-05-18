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
 
int rZ, uZa1, uZa2, n, m;
int rF[1010], uF[1010];
int apt_nb[1010], apt_r[1010], apt_u[1010];
int max_util = -1, util = 0, apt = 0;

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d %d %d", &rZ, &uZa1, &uZa2);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &rF[i], &uF[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &apt_nb[i], &apt_r[i], &apt_u[i]);
    }
    
    int frnd = -1;
    // -1: none, 0: alone, >=1: with friend (index = value)
    
    
    // alone
    for (int i = 0; i < m; i++) {
        //if (apt_nb[i] == 2) continue;
        if (apt_r[i] <= rZ) {
            if (apt_nb[i] == 1) {
                util = uZa1 + apt_u[i];
            } else {
                util = uZa2 + apt_u[i];
            }
            
            if (util > max_util) {
                max_util = util;
                frnd = 0;
                apt = i + 1;
            }
        }
    }
    
    // with friend
    
    for (int i = 0; i < m; i++) {
        if (apt_nb[i] == 1) continue;
        for (int j = 0; j < n; j++) {
            if (apt_r[i] <= min(rZ, rF[j]) * 2) {
                util = apt_u[i] + uF[j];
                if (util > max_util) {
                    max_util = util;
                    frnd = j + 1;
                    apt = i + 1;
                }
            }
        }
    }
    
    if (frnd == -1) {
        printf("Forget about apartments. Live in the dormitory.\n");
    } else if (frnd == 0) {
        printf("You should rent the apartment #%d alone.\n", apt);
    } else {
        printf("You should rent the apartment #%d with the friend #%d.\n", apt, frnd);
    }
    
	return 0;
}
