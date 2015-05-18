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
    char w[63];
    int dict[63];
    int n, ans, c = 0, las, len;
    bool cool;
    
	while (scanf("%d", &n) != EOF) {
        ans = 0;
        c++;
        for (int i = 0; i < n; i++) {
            scanf("%s", w);
            memset(dict, 0, sizeof dict);
            len = strlen(w);
            if (len >= 2)
                cool = true;
            else
                continue;
            
            for (int j = 0; j < len; j++) {
                dict[w[j] - 97]++;
            }
            sort(dict, dict + 26);
            las = -1;
            for (int j = 25; j >= 0; j--) {
                //printf("%d", dict[j]);
                
                if (dict[j] != 0) {
                    if (las == dict[j]) {
                        cool = false;
                        break;
                    } else {
                        las = dict[j];
                    }
                }
            }
            if (cool) ans++;
            
            
        }
        printf("Case %d: %d\n", c, ans);
        
        
    }
    
	return 0;
}
