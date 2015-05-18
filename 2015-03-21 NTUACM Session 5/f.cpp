#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem 
 * @url    
 * @status  
 */


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    char s1[1024], s2[1024];
    vector<char> ans;
    while (gets(s1)) {
        gets(s2);
        bool m1[1024], m2[1024];
        memset(m1, false, sizeof m1);
        memset(m2, false, sizeof m2);
        ans.clear();
        int l1 = strlen(s1), l2 = strlen(s2);
        // 1 should be longer than 2
        if (l1 < l2) {
            swap(s1, s2);
        }
        l1 = strlen(s1), l2 = strlen(s2);
        
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                if (s1[i] == s2[j] && !m2[j]) {
                    m2[j] = true;
                    ans.push_back(s1[i]);
                    break;
                } 
            }
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            printf("%c", ans[i]);
        }
        printf("\n");
        
    }
    return 0;
}
