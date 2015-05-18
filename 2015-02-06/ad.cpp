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

int penalty[128][16];
bool submit[128];
bool ac[128][16];
int final_solve[128];
int final_penalty[128];
char line[255];
int cont, prob, subtime; char ver;

struct da {
    int penalty;
    int solve;
    int id;
};
da contestant[128];
bool comp (da X, da A) {
    return (X.solve > A.solve)
        || (X.solve == A.solve && X.penalty < A.penalty)
        || (X.solve == A.solve && X.penalty == A.penalty && X.id < A.id);
}
void reset() {
    memset(penalty, 0, sizeof penalty);
    memset(submit, false, sizeof submit);
    memset( ac, false, sizeof ac);
    memset( final_solve, 0, sizeof final_solve);
    memset( final_penalty, 0, sizeof final_penalty);
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int T;
    scanf("%d", &T);
    reset();
    scanf("\n");
    for (int t = 0; t < T;) {
        if (fgets(line, 255, stdin) == NULL || strcmp(line, "\n") == 0) {
            // end of case
            //printf("aa");
            int cnt = 0;
            for (int i = 1; i <= 100; i++) {
                if (submit[i]) {
                    //printf("aa%d", i);
                    for (int j = 1; j <= 9; j++) {
                        final_solve[i] = final_solve[i] + (ac[i][j] ? 1 : 0);
                        final_penalty[i] = final_penalty[i] + (ac[i][j] ? penalty[i][j] : 0);
                    }
                    //printf("aa%d", i);
                    contestant[cnt].penalty = final_penalty[i];
                    contestant[cnt].solve = final_solve[i];
                    contestant[cnt].id = i;
                    cnt++;
                }
            }
            //printf("aa");
            sort(contestant, contestant + cnt, comp);
            for (int i = 0; i < cnt; i++) {
                printf("%d %d %d\n", contestant[i].id, contestant[i].solve, contestant[i].penalty);
            }
            t++; reset();
            if (t < T) printf("\n");
            continue;
        }
        sscanf(line, "%d %d %d %c\n", &cont, &prob, &subtime, &ver);
        //printf("[%d] %d %d %d %c\n", t, cont, prob, subtime, ver);
        submit[cont] = true;
        if (ver == 'I')
            penalty[cont][prob] += 20;
        else if (ver == 'C') {
            ac[cont][prob] = true;
            penalty[cont][prob] += subtime;
        }
    }
    return 0;
}
