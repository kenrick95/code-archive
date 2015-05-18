#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: Faktorial
 * URL: http://tokilearning.org/training/7/chapter/77/problem/314
 */

int NA, NB, a[25], b[25];
bool num[1010], check[1010];
vector<int> factn[1010]; //number
vector<int> facte[1010]; //exponent

bool isprime(int i) {
    return num[i];
}

void sieve() {
    memset(num, false, sizeof num);
    memset(check, false, sizeof check);
    
    for (int n = 2; n < 100; n++) {
        if (check[n]) continue;
        
        num[n] = true;
        check[n] = true;
        for (int i = 2; n * i < 1000; i++) {
            num[n * i] = false;
            check[n * i] = true;
        }
    }
    for (int n = 101; n < 1000; n++) {
        if (!check[n]) {
            num[n] = true;
        }
    }
}

void inpf(int type, int n) {
    int sz = factn[type].size();
    for (int i = 0; i < sz; i++) {
        if (factn[type][i] == n) {
            facte[type][i]++;
            return;
        }
    }
    factn[type].push_back(n);
    facte[type].push_back(1);
}

void primef(int a, int type) {
    // type: 1: nom; 2: denom
    int i, c = a, d;
    while (c % 2 == 0) {
        inpf(type, 2);
        c = c / 2;
    }
    i = 3;
    d = (int) sqrt(c) + 1;
    while (i <= d) {
        if (c % i == 0) {
            inpf(type, i);
            c = c / i;
        } else {
            i += 2;
        }
    }
    if (i > d) {
        if (isprime(c)) {
            inpf(type, c);
        }
    }
}

int main(){
	// need: isprime, primef, sort
    
    scanf("%d", &NA);
    for (int i = 0; i < NA; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &NB);
    for (int i = 0; i < NB; i++) {
        scanf("%d", &b[i]);
    }
    
    sieve();
    /*int i = 0;
    for (int n = 2; n < 1000; n++) {
        if (num[n]) {
            printf("%d ", n);
            i++;
        }
    }
    printf("%d", i);*/
    
    
    
    for (int i = 0; i < NA; i++) {
        for (int j = 2 ; j <= a[i]; j++) {
            primef(j, 1);
        }
    }
    for (int i = 0; i < NB; i++) {
        for (int j = 2 ; j <= b[i]; j++) {
            primef(j, 2);
        }
    }
    
    
    //printf("\nNOM ");
    int sz1 = factn[1].size();
    /*printf("%d\n", sz1);
    for (int i = 0; i < sz1; i++) {
        printf("%d (%d), ", factn[1][i], facte[1][i]);
    }*/
    
    //printf("\nDENOM ");
    int sz2 = factn[2].size();
    /*printf("%d\n", sz2);
    for (int i = 0; i < sz2; i++) {
        printf("%d (%d), ", factn[2][i], facte[2][i]);
    }*/
    
    int i = 0, j = 0;
    while (i < sz1 && j < sz2) {
        //printf("%d: %d %d!\n", i, factn[1][i], facte[1][i]);
        //printf("%d: %d %d#\n", j, factn[2][j], facte[2][j]);
        if (factn[1][i] == factn[1][j]) {
            factn[3].push_back(factn[1][i]);
            facte[3].push_back(facte[1][i] - facte[2][j]);
            i++;
            j++;
        } else if (factn[1][i] < factn[1][j]) {
            factn[3].push_back(factn[1][i]);
            facte[3].push_back(facte[1][i]);
            i++;
        } else { // if (factn[1][i] > factn[1][j]) {
            factn[3].push_back(factn[2][j]);
            facte[3].push_back(-facte[2][j]);
            j++;
        }
    }
    //printf("lalal\n");
    while (i < sz1) {
        //printf("%d: %d %d!\n", i, factn[1][i], facte[1][i]);
        if (factn[1][i] == factn[2][sz2-1]) {
            factn[3].push_back(factn[1][i]);
            facte[3].push_back(facte[1][i] - facte[2][sz2-1]);
            i++;
        } else {
            factn[3].push_back(factn[1][i]);
            facte[3].push_back(facte[1][i]);
            i++;
        }
    }
    //printf("lalal\n");
    while (j < sz2) {
        //printf("%d: %d %d#\n", j, factn[2][j], facte[2][j]);
        if (factn[1][sz1-1] == factn[2][j]) {
            factn[3].push_back(factn[2][j]);
            facte[3].push_back(facte[1][sz2-1] - facte[2][j]);
            j++;
        } else { // if (factn[1][i] > factn[1][j]) {
            factn[3].push_back(factn[2][j]);
            facte[3].push_back(-facte[2][j]);
            j++;
        }
    }
    
    //printf("\nFINAL ");
    int sz3 = factn[3].size();
    //printf("%d\n", sz3);
    
    
    int n_pos = 0, n_neg = 0;

    
    for (int i = 0; i < sz3; i++) {
        //printf("%d (%d), ", factn[3][i], facte[3][i]);
        if (facte[3][i] > 0) n_pos++;
        else if (facte[3][i] < 0) n_neg++;
    }
    
    for (int i = 0; i < sz3; i++) {
        if (facte[3][i] > 0) {
            printf("%d", factn[3][i]);
            if (facte[3][i] > 1) {
                printf("(%d)", facte[3][i]);
            }
            if (n_pos > 1) {
                printf(" ");
                n_pos--;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < sz3; i++) {
        if (facte[3][i] < 0) {
            printf("%d", factn[3][i]);
            if (-facte[3][i] > 1) {
                printf("(%d)", -facte[3][i]);
            }
            if (n_neg > 1) {
                printf(" ");
                n_neg--;
            }
        }
    }
    printf("\n");
	return 0;
}
