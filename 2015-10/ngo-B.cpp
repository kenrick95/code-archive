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
    int T; scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int d;
        char s[1024];
        scanf("%d", &d);
        scanf("%s", s);
        int ls = strlen(s);
        vector<char> ans;
        int tmp = 0, cnt = 0;
        for (int i = 0; i < ls; i++) {
            if (s[i] == '[') {
                tmp++;
            } else if (s[i] == ']') {
                tmp--;
                if (tmp == d - 1) {
                    ans.push_back(s[i]);
                    ans.push_back('\n');
                    cnt++;
                }
            }
            if (tmp >= d) {
                ans.push_back(s[i]);
            }
        }
        printf("%d\n", cnt);
        for (int i = 0; i < ans.size(); i++) {
            printf("%c", ans[i]);
        }
    }
    return 0;
}
