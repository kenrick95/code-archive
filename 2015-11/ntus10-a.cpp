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

bool isNumber(char c) {
  return ('0' <= c && c <= '9');
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    char s[1024];
    vector<char> ans;
    char last_cond = '\0', last2_cond = '\0';
    fgets(s, 1024, stdin);
    int ls = strlen(s);

    int cnt_dot = 0;
    for (int i = 0; i < ls; i++) {
      //printf("%c: ", s[i]);
      //printf("\n");


      if (isNumber(s[i])) {
        if (last2_cond == 'n' && last_cond == ' ') {
          ans.push_back(' ');
        }
        ans.push_back(s[i]);

        if (last_cond == 'n')
          continue;
        last2_cond = last_cond;
        last_cond = 'n';
      } else if (s[i] == ',') {
        ans.push_back(s[i]);
        if (i < ls - 2) {
          ans.push_back(' ');
        }
        if (last_cond == ',')
          continue;
        last2_cond = last_cond;
        last_cond = ',';
      } else if (s[i] == '.') {
        cnt_dot++;
        if (cnt_dot == 1 && i > 0 && last_cond != ',') {
          if (last_cond == ' ' && last2_cond != ',') {
            ans.push_back(' ');
          } else if (last_cond != ' ') {
            ans.push_back(' ');
          }

        }
        if (cnt_dot == 3) {

          ans.push_back('.');
          ans.push_back('.');
          ans.push_back('.');
          cnt_dot = 0;

        }

        if (last_cond == '.')
          continue;
        last2_cond = last_cond;
        last_cond = '.';
      } else if (s[i] == ' ') {
        if (last_cond == ' ')
          continue;
        last2_cond = last_cond;
        last_cond = ' ';
      }
    }
    for (int i = 0; i < ans.size(); i++) {
      printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
}
