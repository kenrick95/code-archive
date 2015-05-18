#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#define INF 1000000007

// SIZE: n; MAXCAP: m
#define SIZE 1024
#define MAXCAP 1024

using namespace std;

int n, m;
int w[SIZE], p[SIZE];
// zero-index based (0 .. n)

int sav[SIZE][MAXCAP];
vector<int> res[SIZE][MAXCAP];

int f(int i, int c) {
    if (c < 0) return -INF;
    if (i >= n) return 0;
    //res[i][c]
    // Dynamic programming
    if (sav[i][c] > -1) return sav[i][c];
    // basically just save what will be returned at this state
    

    int take = f(i + 1, c - w[i]) + p[i];
    int dont = f(i + 1, c);
    if (take > dont) {
        // at index i, take it now: give up capacity, take profit
        sav[i][c] = take;
        //res[i][c].push_back(i);
    } else {
        // don't take now: no capacity loss, no profit
        sav[i][c] = dont;
    }
    return sav[i][c];
}
int main(){
    memset(sav, -1, sizeof sav); // initalize content of sav to be -1
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i], &w[i]);
    }
    printf("%d\n", f(0, m));
    return 0;
}
