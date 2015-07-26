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
    string res;
    cin >> res;
    int bet = 1;
    n -= 1;
    int win = 0;
    int ls = res.length();
    for (int i = 0; i < ls; i++) {
        
        // cout << n << " " << bet << endl;
        if (res[i] == 'W') {
            n += bet * 2;
            bet = 1;
        } else {
            bet *= 2;
        }
        // cout << n << " " << bet << endl;
        if (bet > n)
            break;
        if (i < ls - 1)
            n -= bet;
        
        // cout << n << " " << bet << endl;
        // cout << endl;
    }
    cout << n << "\n";

    return 0;
}
