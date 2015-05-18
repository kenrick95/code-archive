#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: 
 * URL: 
 */
const char suitName[4][32] = {"Clubs", "Diamonds", "Hearts", "Spades"};
const char valueName[13][32] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int n, deck[512][64], k, sh[128][64];
    scanf("%d", &n);
    for (int j = 0; j < 52; j++) {
        deck[0][j] = j;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 52; j++) {
            scanf("%d", &sh[i][j]);
        }
    }
    int cur = 0;
    while (scanf("%d", &k) != EOF) {
        if (cur >= 1) printf("\n");
        for (int j = 0; j < 52; j++) {
            deck[cur+1][sh[k-1][j]-1] = deck[cur][j];
        }
        cur++;
        for (int j = 0; j < 52; j++) {
            printf("%s of %s\n", valueName[deck[cur][j] % 13], suitName[deck[cur][j] / 13]);
        }
    }
    
    
    return 0;
}
