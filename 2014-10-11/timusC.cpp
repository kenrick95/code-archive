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

/* Problem: 
 * URL: 
 */

struct datum
{
    int val, time;
} ac[100005];

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int n, val, d, m, h, min;
    char sign;
	scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c%d %d.%d %d:%d", &sign, &val, &d, &m, &h, &min);
        ac[i].val = val * (sign == '-' ? -1 : 1);
        ac[i].time = m*1000000 + d*10000 + h*100 + min;
        
    }
	return 0;
}
