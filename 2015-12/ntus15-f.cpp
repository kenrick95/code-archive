#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
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

struct pos {
  int x, y;
  int v;
  pos(int _x, int _y) : x(_x), y(_y) { v = 0;};
  pos(int _x, int _y, int _v) : x(_x), y(_y), v(_v) {};
  pos() { x = y = v = 0; };
};


int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int n, w, h, l;
    char m[32][32];
    pos rob[8];
    pos direc[4];
    direc[0] = pos(0, 1);
    direc[1] = pos(0, -1);
    direc[2] = pos(1, 0);
    direc[3] = pos(-1, 0);

    int dist[32][32];

    while (scanf("%d %d %d %d", &n, &w, &h, &l) != EOF) {
      for (int i = 0; i < h; i++)
        scanf("%s", &m[i]);

      pos target;
      for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
          if ('0' < m[i][j] < '9')
            rob[m[i][j] - '0' - 1] = pos(j, i);
          else if (m[i][j] == 'X') {
            target = pos(j, i);
            m[i][j] = '.';
          }

          dist[i][j] = INF;
        }


      queue<pos> q;
      for (int i = 0; i < n; i++) {
        q.push(pos(rob[i].x, rob[i].y, i + 1));
        dist[rob[i].y][rob[i].x] = 0;
      }
      while (!q.empty()) {
        pos head = q.front();
        q.pop();
        printf("%d %d %d\n", head.x, head.y, head.v);

        if (head.x == target.x && head.y == target.y && head.v == 1) {
          break;
        }


        for (int i = 0; i < 4; i++) {
          pos temp = pos(head.x, head.y);
          while (direc[i].x != 0 &&
            0 <= temp.x + direc[i].x &&
            temp.x + direc[i].x < w &&
            m[temp.y][temp.x + direc[i].x] == '.') {

            temp.x += direc[i].x;
          }
          while (direc[i].y != 0 &&
            0 <= temp.y + direc[i].y &&
            temp.y + direc[i].y < h &&
            m[temp.y + direc[i].y][temp.x] == '.') {

            temp.y += direc[i].y;
          }
          printf("temp: [%d] %d %d; %d %d\n", i, direc[i].x, direc[i].y, temp.x, temp.y);
          printf("%d %d\n", direc[1].x, direc[1].y);
          printf("[%d] %d %d\n", i, direc[i].x, direc[i].y);
          printf("%d %d\n", direc[1].x, direc[1].y);
          printf("[%d] %d %d\n", i, direc[i].x, direc[i].y);
          if (dist[head.y][head.x] + 1 < dist[temp.y][temp.x]) {
            dist[temp.y][temp.x] = dist[head.y][head.x] + 1;
            q.push(pos(temp.x, temp.y, head.v));
          }

        }

      }

      printf("%d\n", dist[target.y][target.x]);
    }
    return 0;
}
