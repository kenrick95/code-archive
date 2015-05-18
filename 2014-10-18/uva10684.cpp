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
    int n, a[10010], ps[10010];
    
	while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        memset(ps, 0, sizeof ps);
        
        ps[1] = a[1];
        
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i-1] + a[i];
            //printf("- %d ", ps[i]);  
        }
        
        int tmax = -1000000007;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                // [i] to [j];
                tmax = max(tmax, ps[j] - ps[i-1]);
            }
        }
        
        int meh, msf;
        meh = msf = 0;
        for (int i = 1; i <= n; i++) {
            meh = max(0, meh + a[i]);
            msf = max(msf, meh);
        }
        tmax = msf;
        
        //max_ending_here = max_so_far = 0
        //for x in A:
        //    max_ending_here = max(0, max_ending_here + x)
        //    max_so_far = max(max_so_far, max_ending_here)
        
        if (tmax <= 0) {
            printf("Losing streak.\n");
        } else {
            printf("The maximum winning streak is %d.\n", tmax);
        }
          
    }
    
	return 0;
}
