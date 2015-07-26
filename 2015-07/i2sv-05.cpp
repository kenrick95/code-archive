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
    string str;
    cin >> str;
    int ls = str.size();
    int maxi = 0;
    for (int i = 0 ; i < ls - 1; i++) {
        for (int j = 1; j < ls - i; j++) {

            //    cout << i << " " << j << " " << str.substr(i, j) << " " << str.find(str.substr(i, j), i + 1) << " " << (str.find(str.substr(i, j), i + j)  != string::npos ) << endl;
            if (str.find(str.substr(i, j), i + j) != string::npos) {
                maxi = max(maxi, j);
            }
        }
    }
    cout << maxi << endl;

    return 0;
}
