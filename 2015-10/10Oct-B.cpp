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

int xo, yo, n, dist;
int px[240], py[240];
map<pair<pair<int, int>, pair<pair<bool, bool>, bool> >, int> sav;

int f(int x, int y, bool d, bool a, bool turn) {
    //printf("%d %d %d %d %d\n", x, y, d, a, turn);
    if (x * x + y * y > dist * dist) {
        if (turn)
            return 1; // dasha win
        else
            return -1;  // anton win
    }
    if (sav.count(make_pair(make_pair(x, y), make_pair(make_pair(d, a), turn))) > 0) {
        return sav[make_pair(make_pair(x, y), make_pair(make_pair(d, a), turn))];
    }


    int m;
    if (turn)
        m = -1;
    else
        m = 1;
    for (int i = 0; i < n; i++) {
        if (turn) {
            m = max(m, f(x + px[i], y + py[i], d, a, !turn));
        } else {
            m = min(m, f(x + px[i], y + py[i], d, a, !turn));
        }
    }
    if (turn && d) {
        m = max(m, f(y, x, !d, a, !turn));
    } else if (!turn && a) {
        m = min(m, f(y, x, d, !a, !turn));
    }
    sav[make_pair(make_pair(x, y), make_pair(make_pair(d, a), turn))] = m;
    //printf("%d %d %d %d %d :: %d\n", x, y, d, a, turn, m);
    


    return m;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    
    scanf("%d %d %d %d", &xo, &yo, &n, &dist);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &px[i], &py[i]);
    }
    // turn: 0 is Anton; 1 is Dasha
    printf("%s\n", f(xo, yo, 0, 0, 0) > 0 ? "Dasha" : "Anton" );
    return 0;
}
