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
int calc_offset(int year) {
    int offset = 11;
    // how many Julian leap-year that is not Gregorian leap-year?
    for (int i = 17; i <= min(99, year / 100); i++) {
      if (i % 4 == 0)
        continue;
      offset++;
    }
    return offset;
}
bool Gleap(int year) {
  return (year % 400 == 0 ? 1 : (year % 100 != 0 && year % 4 == 0) ? 1 : 0);
}
bool JbutnotGleap(int year) {
  return (year % 4 == 0 && year % 100 == 0 && year % 400 != 0) ? 1 : 0;
}
int dom(int month, int year) {
  switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
    case 4: case 6: case 9: case 11: return 30;
    case 2: return Gleap(year) ? 29 : 28;
  }
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int Y, M, D;
    while (scanf("%d-%d-%d", &Y, &M, &D) != EOF) {
      int offset = calc_offset(Y);
      // before 1700-02-28, offset should be 11; after that, offset should be 12
      if (JbutnotGleap(Y) && (M == 1 || (M == 2 && D <= 29))) {
        offset--;
      }
      //printf("offset: %d\n", offset);

      // what if offset > dom(M, Y) ?
      int x = dom(M, Y);
      int y = x - D;
      if(offset > y) {
        offset -= y;
        D = dom(M, Y);
        if(M == 12) {
          ++Y;
          M = 1;
        }
        else
          ++M;
        while (offset > dom(M, Y)) {
          //printf("offset: %04d; D: %02d; M: %02d; Y: %04d\n", offset, D, M, Y);
          if (M == 12) {
            Y += 1;
            M = 1;
            offset -= 31;
          } else {
            offset -= dom(M, Y);
            M += 1;
          }
        }
        if(offset > 0) {
          D = offset;
        }
      }
      else {
        D = D + offset;
        offset = 0;
      }




      printf("%d-%02d-%02d\n", Y, M, D);
    }
    return 0;
}
