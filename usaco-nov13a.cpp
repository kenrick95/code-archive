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
USACO 2013 November Contest, Bronze
Problem 1. Combination Lock
 * URL: http://usaco.org/index.php?page=viewproblem&cpid=331&lang=en
 */
int a[5],b[5],N;

int pos(int i, int x) {
	if ((abs(i - a[x]) <= 2)
	|| (abs(i - a[x]) >= N-2))
	{
		return true;
	}
	return false;
}
int posb(int i, int x) {
	if ((abs(i - b[x]) <= 2)
	|| (abs(i - b[x]) >= N-2))
	{
		return true;
	}
	return false;
}

int check(int i, int j, int k) {
	if ((pos(i,1) && pos(j,2) && pos(k,3))
	|| (posb(i,1) && posb(j,2) && posb(k,3)))
	{
		return true;
	}
	return false;
}
 
int main(){
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	
	int i;
	//int c[1010][1010][1010];
	int res=0;
	
	scanf("%d", &N);
	scanf("%d %d %d",&a[1],&a[2],&a[3]);
	scanf("%d %d %d",&b[1],&b[2],&b[3]);
	
	
	/*
	for (i=1; i<=N; i++) {
		for (j=1; j<=N; j++) {
			for (k=1; k<=N; k++) {
				//check if (i,j,k) is close to a or b
				//if close enough, res++
				if (check(i,j,k)) {
					//printf("%d %d %d\n",i,j,k);
					res ++;
				}
			}
		}
	}*/
	
	int inter[5];
	int range[5];
	
	for (i=1; i<=3; i++) {
		range[i] = 0;
		inter[i] = abs(a[i] - b[i]);
		if (inter[i] == N-4) {
			range[i] = 1;
		} else if (inter[i] == N-3) {
			range[i] = 2;
		} else if (inter[i] == N-2) {
			range[i] = 3;
		} else if (inter[i] == N-1) {
			range[i] = 4;
		} else if (inter[i] == 4) {
			range[i] = 1;
		} else if (inter[i] == 3) {
			range[i] = 2;
		} else if (inter[i] == 2) {
			range[i] = 3;
		} else if (inter[i] == 1) {
			range[i] = 4;
		} else if (inter[i] == 0) {
			range[i] = 5;
		}
		//printf("%d ",range[i]);
	}
	int excl = range[1];
	for (i=2; i<=3; i++) {
		excl *= range[i];
	}
	res = 250;
	res -= excl;
	
	printf("%d\n", res);
	
	return 0;
}
