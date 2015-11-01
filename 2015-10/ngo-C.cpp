#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
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
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int T, n, h, a[100005], pcnt, ncnt, zcnt;
    vector<int> pf, nf;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        pf.clear();
        nf.clear();
        pcnt = ncnt = zcnt = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > 0) {
                pcnt++;
                pf.push_back(a[i]);
            } else if (a[i] < 0) {
                ncnt++;
                nf.push_back(a[i]);
            }
        }
        zcnt = n - (ncnt + pcnt);
        bool possible = true;
        // printf("%d %d %d %d\n", n, pcnt, ncnt, zcnt);
        if (zcnt == 0) {
            // no zero
            if (pcnt == ncnt || pcnt == ncnt + 1|| 1 + pcnt == ncnt) {
                // always negative
                if (pcnt == ncnt || 1 + pcnt == ncnt) {
                    for (int i = 0; i < n; i++) {
                        if (i % 2 == 0) {
                            printf("%d", nf.back());
                            nf.pop_back();
                        } else {
                            printf("%d", pf.back());
                            pf.pop_back();
                        }
                        if (i + 1 < n)
                            printf(" ");
                        else
                            printf("\n");
                    }
                } else {
                    for (int i = 0; i < n; i++) {
                        if (i % 2 == 0) {
                            printf("%d", pf.back());
                            pf.pop_back();
                        } else {
                            printf("%d", nf.back());
                            nf.pop_back();
                        }
                        if (i + 1 < n)
                            printf(" ");
                        else
                            printf("\n");
                    }
                }
            } else if (pcnt == 0 || ncnt == 0) {
                // always positive
                if (pcnt == 0) {
                    for (int i = 0; i < n; i++) {
                        printf("%d", nf.back());
                        nf.pop_back();
                        if (i + 1 < n)
                            printf(" ");
                        else
                            printf("\n");
                    }
                } else {
                    for (int i = 0; i < n; i++) {
                        printf("%d", pf.back());
                        pf.pop_back();
                        if (i + 1 < n)
                            printf(" ");
                        else
                            printf("\n");
                    }
                }
            } else {
                possible = false;
            }
        } else {
            if (ncnt + pcnt == zcnt + 1 || ncnt + pcnt <= zcnt) {
                // always zero
                if (ncnt + pcnt <= zcnt) {
                    for (int i = 0; i < n; i++) {
                        if (i % 2 == 0) {
                            printf("0");
                        } else {
                            if (pf.size() > 0) {
                                printf("%d", pf.back());
                                pf.pop_back();
                            } else if (nf.size() > 0) {
                                printf("%d", nf.back());
                                nf.pop_back();
                            } else {
                                printf("0");
                            }
                        }
                        if (i + 1 < n)
                            printf(" ");
                        else
                            printf("\n");
                    }
                } else if (zcnt == n) {
                    for (int i = 0; i < n; i++) {
                        printf("0");
                        if (i + 1 < n)
                            printf(" ");
                        else
                            printf("\n");
                    }
                } else {
                    for (int i = 0; i < n; i++) {
                        if (i % 2 == 0) {
                            if (pf.size() > 0) {
                                printf("%d", pf.back());
                                pf.pop_back();
                            } else {
                                printf("%d", nf.back());
                                nf.pop_back();
                            }
                        } else {
                            printf("0");
                        }
                        if (i + 1 < n)
                            printf(" ");
                        else
                            printf("\n");
                    }
                }
            } else {
                possible = false;
            }
        }
        if (!possible) {
            printf("mustahil\n");
            continue;
        }
    }
    return 0;
}
