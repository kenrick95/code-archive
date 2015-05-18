#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
//#include <bits/stdc++.h>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */

map <string, string> ma;
map <string, int> ma_cnt;
int T, N;
char ar[10010][2][15];
string head, tail;

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        ma.clear();
        ma_cnt.clear();
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%s", ar[i][0]);
            scanf("%s", ar[i][1]);
            ma[ar[i][0]] = ar[i][1];
            if (ma_cnt.count(ar[i][0]) > 0) {
                ma_cnt[ar[i][0]]++;
            } else {
                ma_cnt[ar[i][0]] = 1;
            }
            if (ma_cnt.count(ar[i][1]) > 0) {
                ma_cnt[ar[i][1]]++;
            } else {
                ma_cnt[ar[i][1]] = 1;
            }
        }
        string head = ar[0][0], tail = ar[0][1];
        for (int i = 0; i < N; i++) {
            //cout<<ar[i][0]<<" "<<ma_cnt[ar[i][0]]<<endl;
            if (ma_cnt[ar[i][0]] == 1) {
                head = ar[i][0];
                break;
            }
        }
        for (int i = 0; i < N; i++) {
            if (ma_cnt[ar[i][1]] == 1) {
                tail = ar[i][1];
                break;
            }
        }
        printf("Case #%d:", t);
        for (int i = 0; i < N; i++) {
            cout<<" "<<head<<"-"<<ma[head];
            //printf(" %s-%s", head, ma[head]);
            head = ma[head];
        }
        printf("\n");
        
    }
    return 0;
}
