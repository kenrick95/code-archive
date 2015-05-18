#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>
//#include <bits/stdc++.h>
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
    int N;
    //char name[255];
    string name;
    map<string, int> ma;
    
    //cin >> N;
    while (cin >> N) {
        ma.clear();
        for (int i = 0; i < N ; i++) {
            //scanf("%s", name);
            cin >> name;
            if (ma.count(name) > 0) ma[name]++;
            else ma[name] = 1;
        }
        for (int i = 0; i < N - 1 ; i++) {
            //scanf("%s", name);
            cin >> name;
            ma[name]--;
        }
        for (map<string,int>::iterator it=ma.begin(); it!=ma.end(); ++it) {
            //cout<< it->first << " ";
            
            if (it->second == 1) {
                cout<< it->first << "\n";
            }
        }

        //cin >> N;
    }
    return 0;
}
