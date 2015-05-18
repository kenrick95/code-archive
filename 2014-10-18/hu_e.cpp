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

int disp[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int cst(int num) {
    if (num == 0) return disp[0];
    
    int temp = 0;
    while (num > 0) {
        temp += disp[num % 10];
        num /= 10;
    }
    return temp;
    
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int H,M,S, Stime, Etime, Ltime, Ctime;
    
    char Q[255];
    int sc, Hsc, Gsc, cost, Tc = 0;
    
	while (scanf("%s %d:%d:%d", Q, &H, &M, &S) != EOF) {
        
        if (strcmp(Q, "START") == 0) {
            sc = Hsc = Gsc = Ctime = cost = 0;
            Stime = H * 3600 + M * 60 + S;
            Ltime = Stime;
            Tc++;
        } else if (strcmp(Q, "SCORE") == 0) {
            Ctime = H * 3600 + M * 60 + S;
            // calc prev cost
            cost += (Ctime - Ltime) * (cst(Hsc) + cst(Gsc));
            //printf("%d: %d (%d) - %d (%d)\n", cost, Hsc, cst(Hsc), Gsc, cst(Gsc));
            
            // update score
            scanf("%s %d", Q, &sc);
            if (strcmp(Q, "home") == 0) {
                Hsc += sc;
            } else { //guest
                Gsc += sc;
            }
            Ltime = Ctime;
            
        } else { //end
            Etime = H * 3600 + M * 60 + S;
            // calc prev cost
            cost += (Etime - Ltime) * (cst(Hsc) + cst(Gsc));
            printf("Case %d: %d\n", Tc, cost);
        }
        
        
    }
	return 0;
}
