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

char st1[40040],st2[55];
int t,T,x,y,z,len, len2;
int sav[40040][55];

int f(int i, int left) {
    //printf("%d %d\n", i, left);
    if (left == 0) {
        return 1;
    }
    if (i == len -1) {
        return 0;
    }
    if (sav[i][left] >= 0) return sav[i][left];
    
    int temp = 0, j, temp2, temp3 = len2 - left;
    for (j = i + 1; j < len; j++) {
        if (st1[j] == st2[temp3]) {
            temp2 = temp + f(j, left - 1);
            temp = (temp2 > 1000000007) ? (temp2 % 1000000007) : temp2;
        }
    }
    sav[i][left] = temp;
    return temp;
}
/*
f(i, j)
{

if(j > M) return 1;
if(i > N) return 0;
if(x[i] == y[j]) return f(i + 1, j + 1) + f(i + 1, j);
else return f(i + 1, j);

}
*/

int main() {
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        scanf("%s", st1);
        scanf("%s", st2);
        len = strlen(st1);
        len2 = strlen(st2);
        
        int temp = 0, j, temp2;
        for (int i = 0; i < len + 1; i++) {
            for (int j = 0; j < len2 + 1; j++) {
                sav[i][j] = -1;
            }
        }
        for (j = 0; j < len; j++) {
            if (st1[j] == st2[0]) {
                temp2 = temp + f(j, len2 - 1);
                temp = (temp2 > 1000000007) ? (temp2 % 1000000007) : temp2;
            }
        }
        printf("Kasus #%d: %d\n", t, temp);
    }
	return 0;
}
