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

int loc(char name[]) {
    if (strcmp(name, "Alice") == 0
    || strcmp(name, "Ariel") == 0
    || strcmp(name, "Aurora") == 0
    || strcmp(name, "Phil") == 0
    || strcmp(name, "Peter") == 0
    || strcmp(name, "Olaf") == 0
    || strcmp(name, "Phoebus") == 0
    || strcmp(name, "Ralph") == 0
    || strcmp(name, "Robin") == 0) {
        return 1;
    } else if (strcmp(name, "Bambi") == 0
    || strcmp(name, "Bolt") == 0
    || strcmp(name, "Belle") == 0
    || strcmp(name, "Mulan") == 0
    || strcmp(name, "Mowgli") == 0
    || strcmp(name, "Mickey") == 0
    || strcmp(name, "Silver") == 0
    || strcmp(name, "Simba") == 0
    || strcmp(name, "Stitch") == 0) {
        return 2;
    } else if (strcmp(name, "Dumbo") == 0
    || strcmp(name, "Genie") == 0
    || strcmp(name, "Jiminy") == 0
    || strcmp(name, "Kuzko") == 0
    || strcmp(name, "Kida") == 0
    || strcmp(name, "Kenai") == 0
    || strcmp(name, "Tarzan") == 0
    || strcmp(name, "Tiana") == 0
    || strcmp(name, "Winnie") == 0) {
        return 3;
    }
    return 0;
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int n, cur = 1, next = 0, ans = 0;
    char name[255];
	scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        next = loc(name);
        ans += abs(next - cur);
        cur = next;
        //printf("%d\n", ans);
    }
    printf("%d\n", ans);
	return 0;
}
