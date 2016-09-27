#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cassert>
#include <map>
#include <deque>
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
    freopen("highcard.in","r",stdin);
    freopen("highcard.out","w",stdout);
    int n;
    bool x[100005];
    int in[100005];
    memset(x, 0, sizeof x);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      x[a] = true;
      in[i] = a;
    }
    deque<int> dq;
    for (int i = 1 ; i <= 2 * n; i++) {
      if (!x[i]) {
        dq.push_back(i);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      // get lowest card higher than in[i]. if can't, use lowest card.
      deque<int>::iterator a = lower_bound(dq.begin(), dq.end(), in[i]);
      //cout << *a << " vs " << in[i] << endl;
      if (a == dq.end()) {
        dq.pop_front();
      } else {
        dq.erase(a);
        ans++;
      }
    }
    printf("%d\n", ans);


    return 0;
}
