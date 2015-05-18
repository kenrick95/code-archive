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

map<string, bool> sav;

char mult(char a, char b) {
    /**
     * LET -1 represented as 0
     *     -i represented as a
     *     -j represented as b
     *     -k represented as c
     */
    char ans = a;
    if (a == '1') {
        ans = b;
    } else if (b == '1') {
        ans = a;
    } else if (a == '0') {
        switch (b) {
            case '1': ans = '0'; break;
            case 'i': ans = 'a'; break;
            case 'j': ans = 'b'; break;
            case 'k': ans = 'c'; break;
            case '0': ans = '1'; break;
            case 'a': ans = 'i'; break;
            case 'b': ans = 'j'; break;
            case 'c': ans = 'k'; break;
        }
    }  else if (b == '0') {
        switch (a) {
            case '1': ans = '0'; break;
            case 'i': ans = 'a'; break;
            case 'j': ans = 'b'; break;
            case 'k': ans = 'c'; break;
            case '0': ans = '1'; break;
            case 'a': ans = 'i'; break;
            case 'b': ans = 'j'; break;
            case 'c': ans = 'k'; break;
        }
    } else {
        switch (a) {
            case 'i': switch (b) {
                case 'i': ans = '0'; break; // 0 == -1
                case 'j': ans = 'k'; break;
                case 'k': ans = 'b'; break; // b == -j
                case 'a': ans = '1'; break;
                case 'b': ans = 'c'; break; // c == -k
                case 'c': ans = 'j'; break;
            }
            break;
            case 'j': switch (b) {
                case 'i': ans = 'c'; break; // c == -k
                case 'j': ans = '0'; break; // 0 == -1
                case 'k': ans = 'i'; break;
                case 'a': ans = 'k'; break;
                case 'b': ans = '1'; break;
                case 'c': ans = 'a'; break; // a == -i
            }
            break;
            case 'k': switch (b) {
                case 'i': ans = 'j'; break;
                case 'j': ans = 'a'; break; // a == -i
                case 'k': ans = '0'; break; // 0 == -1
                case 'a': ans = 'b'; break; // b == -j
                case 'b': ans = 'i'; break;
                case 'c': ans = '1'; break;
            }
            break;
            case 'a': switch (b) {
                case 'i': ans = '1'; break;
                case 'j': ans = 'c'; break; // c == -k
                case 'k': ans = 'j'; break;
                case 'a': ans = '0'; break; // 0 == -1
                case 'b': ans = 'k'; break;
                case 'c': ans = 'b'; break; // b == -j
            }
            break;
            case 'b': switch (b) {
                case 'i': ans = 'k'; break;
                case 'j': ans = '1'; break;
                case 'k': ans = 'a'; break; // a == -i
                case 'a': ans = 'c'; break; // c == -k
                case 'b': ans = '0'; break; // 0 == -1
                case 'c': ans = 'i'; break;
            }
            break;
            case 'c': switch (b) {
                case 'i': ans = 'b'; break; // b == -j
                case 'j': ans = 'i'; break;
                case 'k': ans = '1'; break;
                case 'a': ans = 'j'; break;
                case 'b': ans = 'a'; break; // a == -i
                case 'c': ans = '0'; break; // 0 == -1
            }
            break;
        }
    }
    return ans;
}

bool reduce2(char st[], int last, char target) {
    if (last == 0)
        return (target == st[0]);

    if (sav.count((string) st) > 0)
        return sav[(string) st];

    int size = (int) ceil((last + 1) / 2.);
    char sn[size + 1];
    for (int i = 0; i < size; i++) {
        sn[i] = mult(st[i * 2], st[i * 2 + 1]);
    }
    sn[size] = '\0';
    // printf("[%d: %d] [%s] >>> [%s]\n", last, size, st, sn);

    return sav[(string) st] = reduce2(sn, size - 1, target);
}

bool reduce(char st[], int start, int end, char target) {
    if (start == end)
        return (target == st[start]);

    char s[end - start + 1];
    strncpy(s, st + start, end - start + 1);
    s[end - start + 1] = '\0';

    return reduce2(s, end - start, target);
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T;
    int L, X;
    char s[10010], st[10010];
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &L, &X);
        scanf("%s", s);
        for (int i = 0; i < X; ++i)
        {
            strcpy(st + L * i, s);
        }
        // printf("%s\n", st);
        // reduce(st, 0, L * X - 1, 'i');
        bool can = false;
        for (int i = 0; i < L * X - 1; ++i)
        {
            for (int j = i + 1; j < L * X - 1; ++j)
            {
                if ( reduce(st, 0, i, 'i')
                    && reduce(st, i + 1, j, 'j')
                    && reduce(st, j + 1, L * X - 1, 'k')) {
                    can = true;
                    break;
                }
            }
        }
        printf("Case #%d: ", t);
        if (can) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
