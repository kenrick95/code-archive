#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: TOKI Open 2014 - Day 1 (Run 2): Multiple Choice
 * URL: http://167.205.32.28/contest/4/problem/view/4/
 */
int N, P, Q;
char A[2020], B[2020], cor[2020][6];
map<pair<int, pair<int, int> > , int> sav;

int test(int i, int scoreA, int scoreB) {
    if (i == N - 1) {
        if ((scoreA == P) && (scoreB == Q)) {
            return 1;
        } else {
            return 0;
        }
    }
    if (sav.count(make_pair(i, make_pair(scoreA, scoreB))) > 0) {
        return sav[make_pair(i, make_pair(scoreA, scoreB))];
    }
    int ret = 0;
    for (int j = 0; j < 5; j++) {
        if (cor[i + 1][j] != '.') {
            //printf("%d%c; ", i + 1, cor[i + 1][j]);
            if (((scoreA + (cor[i + 1][j] == A[i + 1])) <= P) && ((scoreB + (cor[i + 1][j] == B[i + 1])) <= Q)) {
                ret = (ret + test(i + 1, scoreA + (cor[i + 1][j] == A[i + 1]), scoreB + (cor[i + 1][j] == B[i + 1]))) % 1000000007;;
            }
        }
    }
    ret = ret % 1000000007;
    sav[make_pair(i, make_pair(scoreA, scoreB))] = ret;
    return ret;
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    
    scanf("%d %d %d\n", &N, &P, &Q);
    for (int i = 0; i < N; i++) {
        scanf("%c", &A[i]);
        if (i + 1 != N ) scanf(" ");
        else scanf("\n");
    }
    for (int i = 0; i < N; i++) {
        scanf("%c",&B[i]);
        if (i + 1 != N ) scanf(" ");
        else scanf("\n");
    }
    for (int i = 0; i < N; i++) {
        scanf("%s", cor[i]);
        //~ for (int j = 0; j < 5; j++) {
            //~ scanf("%c", &cor[i][j]);
        //~ }
        //~ if (i + 1 != N) scanf("\n");
    }
    
    //~ printf("\n======\n");
    //~ for (int i = 0; i < N; i++) {
        //~ printf("%c", A[i]);
    //~ }
    //~ printf("\n======\n");
    //~ for (int i = 0; i < N; i++) {
        //~ printf("%c",B[i]);
    //~ }
    //~ printf("\n======\n");
    //~ for (int i = 0; i < N; i++) {
        //~ for (int j = 0; j < 5; j++) {
            //~ printf("%c", cor[i][j]);
        //~ }
        //~ printf("\n");
    //~ }
    //~ printf("\n======\n");
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        if (cor[0][i] != '.') {
            //printf("%d%c; ", i, cor[0][i]);
            ans = (ans + test(0, ('a' + i) == A[0], ('a' + i) == B[0])) % 1000000007;
        }
    }
    printf("%d\n", ans);
    return 0;
}
