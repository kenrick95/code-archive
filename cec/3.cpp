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
    char st[100010];
    int ch, lch, tch, ltch, ich, itch;
    
	while (scanf("%s", st) != EOF) {
        int ls = strlen(st);
        tch = st[0];
        ltch = 0;
        lch = 0;
        for (int i = 0; i < ls; i++) {
            if (st[i] == tch) {
                ltch++;
            } else {
                tch = st[i];
                ltch = 1;
                itch = i;
            }
            if (ltch > lch) {
                lch = ltch;
                ch = tch;
                ich = itch;
            }
        }
        printf("%d ", ich);
        for (int i = 0; i < lch; i++) {
            printf("%c", ch);
        }
        printf("\n");
    };
    
	return 0;
}
