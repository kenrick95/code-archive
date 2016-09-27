#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
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

int v[32], ls;
char str[100005];
int f(int i, char init) {
  if (i >= ls)
    return 0;
  printf(" ");
  int ret = 0;
  if (str[i] == init) {
    ret = 1 + f(i + 1, init);
    printf("!!!! %d %c: %d\n", i, init, ret);
    return ret;
  }
  ret = f(i + 1, init) + f(i + 1, str[i]);
  printf("%d: init %c; str[i]: %c; ret: %d\n", i, init, str[i], ret);
  return ret;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    for (int i = 0; i < 26; i++) {
      scanf("%d", &v[i]);
    }
    scanf("%s", str);
    ls = strlen(str);

    printf("%d\n", f(0, '\0'));

    return 0;
}
