#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#include <set>
#define DEBUG printf("TEST\n")
#define HOLD scanf("%*c%*c")

using namespace std;

int N, K;
struct bt {
    int x[336];
    int nDigit;
    /*
    bt operator + (const bt &A) {
        bt ans;
        for (int i = 0; i < 400; i++) {
            ans.x[i] = x[i] + A.x[i];
            if (ans.x[i] >= 1000000000) {
                ans.x[i] -= 1000000000;
                ans.x[i+1] += 1;
            }
        }
        return ans;
    }
    bt operator = (const int &A) {
        bt ans;
        for (int i = 0; i < 400; i++) {
            ans.x[i] = x[i] = 0;
        }
        ans.x[0] = x[0] = A;
        return ans;
    }*/
};

bt dp[100001][2];

bt num;

bool greaterThan(bt a, int b) {
    return (a.x[0] > b);
}

bt f(int idx)
{
    
    
    
    
    
        //printf("%d %d\n", idx, L);
     if(greaterThan(dp[idx][L], -1)) return dp[idx][L];
     
     int nDigit = dp[idx][L].nDigit;
     for (int i = 0; i < nDigit; i++) {
        dp[idx][L].x[i] = 0;
     }
     
     if (idx == N) {
         dp[idx][L].x[0] = 1;
         dp[idx][L].nDigit = 1;
         return dp[idx][L];
    } 
    bt ret;
    
    for (int cur = idx+2; cur < N; cur++) {
        ret = f(cur);
        
        dp[idx] += f(cur) * min(cur-idx-1 , k );
    }
    
    
     if (L == 0) {
         for(int i = 1; i <= N - idx; ++i) {
             ret = f(idx + i, 1);
             nDigit = max(ret.nDigit, dp[idx][L].nDigit);
             
             for (int j = 0; j < nDigit; j++) {
                    dp[idx][L].x[j] = dp[idx][L].x[j] + ret.x[j];
                    if (dp[idx][L].x[j] >= 1000000000) {
                        dp[idx][L].x[j] -= 1000000000;
                        dp[idx][L].x[j+1] += 1;
                    }
             }
             if (dp[idx][L].x[nDigit] > 0) {
                 dp[idx][L].nDigit++;
            }
         }
     }

     return dp[idx][L];
}

int main()
{
     
     for(int i = 0; i <= 100000; ++i) {
         dp[i][0].x[0] = dp[i][1].x[0] = -1;
         dp[i][0].nDigit = dp[i][1].nDigit = 1;
     }
     
     scanf("%d %d", &N, &K);
     bt ans = f(0, 0);
     bt ans2= f(0, 1);
     int nDigit = max(ans.nDigit, ans2.nDigit);
     for (int j = 0; j < nDigit; j++) {
                 ans.x[j] = ans.x[j] + ans2.x[j];
                    if (ans.x[j] >= 1000000000) {
                        ans.x[j] -= 1000000000;
                        ans.x[j+1] += 1;
                    }
             }
     
     bool trail = true;
     for (int i = nDigit+1; i >= 0; i--) {
         if (trail) {
             if (ans.x[i] != 0) {
                 printf("%d", ans.x[i]);
                 trail = false;
             }
         } else {
             printf("%d", ans.x[i]);
         }
     }
     printf("\n");
     return 0;
}
