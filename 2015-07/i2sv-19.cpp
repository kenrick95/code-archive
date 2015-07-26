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
    cin >> n;
    int pat[64];
    for (int i = 0; i < n; i++) {
        cin >> pat[i];
    }
    string str;
    cin >> str;
    int ls = str.size();
    int cnt = 0;    
    for (int i = 0 ; i < ls; i++) {
        if (str[i] == 'S' && pat[i] <= 2 || str[i] == 'J' && pat[i] > 2) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
