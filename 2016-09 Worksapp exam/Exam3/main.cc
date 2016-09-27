#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
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

int n, m, k;
char mp[8][32][32];
bool ign[256];
char cmpstr[8][256], i_cmpstr = 0;
map <string, bool> dict;

// int compute_hash(int i, int cur_idx) {
//     int ret = 0;
//     for (int ix = 0; ix < i_cmpstr; ix++) {
//         if (ign[ix] || ix == cur_idx)
//             continue;
//         ret = ret * 2 + (cmpstr[i][ix] - '0');
//     }
//     return ret;
// }
string get_hash(int i, int cur_idx) {
    string ret = "";
    for (int ix = 0; ix < i_cmpstr; ix++) {
        if (ign[ix] || ix == cur_idx)
            continue;
        ret.push_back(cmpstr[i][ix]);
    }
    return ret;
}


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < k; i++) {
        for (int r = 0; r < n; r++) {
            scanf("%s", &mp[i][r]);
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            bool same = true;
            int same_val = mp[0][r][c];
            for (int i = 1; i < k; i++) {
                if (same_val != mp[i][r][c]) {
                    same = false;
                    break;
                }
            }
            if (!same) {
                for (int i = 0; i < k; i++) {
                    cmpstr[i][i_cmpstr] = mp[i][r][c];
                }
                i_cmpstr++;
            }
        }
    }
    // for (int i = 0; i < k; i++) {
    //     cmpstr[i][i_cmpstr + 1] = '\0';
    //     printf("%s\n", cmpstr[i]);
    // }
    // printf("%d\n", i_cmpstr);

    for (int ix = 0; ix < i_cmpstr; ix++) {
        // let say we remove cmpstr[..][ix], can we still uniquely identify cmpstr?
        bool can = true;

        dict.clear();
        for (int i = 0; i < k; i++) {
            // int hash = compute_hash(i, ix);
            string hash = get_hash(i, ix);
            // printf("%d -> %d\n", i, hash);
            if (dict.count(hash) > 0) {
                // collision
                can = false;
                break;
            }
            dict[hash] = true;
        }
        if (can) {
            ign[ix] = true;
        }
    }

    int ans = i_cmpstr;
    for (int ix = 0; ix < i_cmpstr; ix++) {
        if (ign[ix])
            ans--;
    }
    printf("%d\n", ans);


    return 0;
}
