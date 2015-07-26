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
    int n;
    string name, action;
    cin >> n;
    int ans = 0;
    vector<string> park;
    for (int i = 0; i < n; i++) {
        cin >> name >> action;
        if (action[0] == 'a') {
            // arrives
            park.push_back(name);
            ans = max(ans, (int) park.size());
        } else {
            // departs
            for (int j = 0; j < park.size(); j++) {
                if (park[j].compare(name) == 0) {
                    park.erase(park.begin() + j);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
