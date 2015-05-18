#include <cstdio>        // #include <stdio.h>
#include <cstring>
/*
http://www.tokilearning.org/lx/problem/1631
* find Ammar
* jika ada yg cinta Ammar, maka dia itu cewek
* tentuin yg lain dari sini
* hmmm, graph theory
*/
int main() {
    int n, i, j;
    char ans[100];
    int e[110][110];
    char v[110];
    memset(e, 0, sizeof(e));
    memset(v, 0, sizeof(v));
    
    scanf("%d",&n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                e[i][j] = 1;
                continue;
            }
            printf("CINTA %d %d\n", i, j);
            fflush(stdout);
            scanf("%s", ans);
            if (strcmp(ans, "YA") == 0) {
                e[i][j] = 1;
            } else {
                e[i][j] = 0;
            }
        }
    }
    
    int ammar = 0;
    for (i = 1; i <= n; i++) {
        ammar = i;
        for (j = 1; j <= n; j++) {
            if (e[i][j] == 0) {
                ammar = 0;
            }
        }
        if (ammar) break;
    }
    v[ammar] = 'A';
    
    for (i = 1; i <= n; i++) {
        if (e[i][ammar]) {
            v[i] = 'E';
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (e[i][j] && v[j]=='E') {
                v[i] = 'O';
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (e[i][j] && v[j]=='O') {
                v[i] = 'E';
            }
        }
    }

    printf("JAWAB\n");
    fflush(stdout);
    for (i = 1; i <= n; i++) {
        printf("%c", v[i]);
        fflush(stdout);
    }

    return 0;
}	
