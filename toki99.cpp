#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: The Alien of Yogyakarta: The Curse of The IFO
 * URL: http://tokilearning.org/training/7/chapter/72/problem/99
 */

int N,M,B;
int map[55][55];
int mark[55][55];
int dp_sum[55][55];
int dp_batu[55][55];

int main(){
	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &B);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 9999) {
				mark[y][x] = 1;
			} else {
				mark[y][x] = 0;
			}
		}
	}
	for (int y = 0; y <= N+1; y++) {
		for (int x = 0; x <= M+1; x++) {
			dp_sum[y][x] = 0;
			dp_batu[y][x] = 0;
		}
	}
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (x*y == 1) {
				dp_sum[y][x] = mark[y][x] ? 0 : map[y][x];
				dp_batu[y][x] = mark[y][x];
			} else if (x == 1) {
				dp_sum[y][x] = dp_sum[y-1][x] + (mark[y][x] ? 0 : map[y][x]);
				dp_batu[y][x] = dp_batu[y-1][x] +  mark[y][x];
			} else if (y == 1) {
				dp_sum[y][x] = dp_sum[y][x-1] + (mark[y][x] ? 0 : map[y][x]);
				dp_batu[y][x] = dp_batu[y][x-1] +  mark[y][x];
			} else {
				dp_sum[y][x] = dp_sum[y-1][x] + dp_sum[y][x-1] - dp_sum[y-1][x-1] + (mark[y][x] ? 0 : map[y][x]);
				dp_batu[y][x] = dp_batu[y-1][x] + dp_batu[y][x-1] - dp_batu[y-1][x-1] +  mark[y][x];
			}
		}
	}
	
	/*for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cout<<dp_sum[y][x]<<"&";
			cout<<dp_batu[y][x];
		}
		cout<<endl;
	}*/
	
	int temp_max = -1000000007;
	int batu_min = 1000000007;
	int temp  = 0;
	int batu  = 0;
	for (int y1 = 1; y1 <= N; y1++) {
		for (int x1 = 1; x1 <= M; x1++) {
			//cout<<"(" << x1 << "," << y1<<")"<<endl;
			for (int y2 = y1; y2 <= N; y2++) {
				for (int x2 = x1; x2 <= M; x2++) {
					temp = dp_sum[y2][x2] - dp_sum[y2][x1-1] - dp_sum[y1-1][x2] + dp_sum[y1-1][x1-1];
					batu = dp_batu[y2][x2] - dp_batu[y2][x1-1] - dp_batu[y1-1][x2] + dp_batu[y1-1][x1-1];
					//cout<<"     (" << x2 << "," << y2<<")"<<" -- "<<temp<<" | "<<batu<<endl;
					if ((temp > temp_max) && (batu <= B)) {
						temp_max = temp;
						batu_min = batu;
					} else if ((temp == temp_max) && (batu <= B) && (batu > batu_min)) {
						batu_min = batu;
					}
					
				}
			}
			//cout<<endl;
		}
	}
	printf("%d %d\n", temp_max, batu_min);
	
	return 0;
}
