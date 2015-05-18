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
 * 
USACO 2013 November Contest, Bronze
Problem 2. Goldilocks and the N Cows

 * URL: http://usaco.org/index.php?page=viewproblem&cpid=332
 */
 
int N,X,Y,Z,A[20020],B[20020];
int T,minT,maxT;

int check(int temp) {
	int ret = 0;
	for (int i=0; i<N; i++) {
		if (temp < A[i]) {
			ret += X;
		} else if (temp > B[i]) {
			ret += Z;
		} else { // A[i] <= temp <= B[i]
			ret += Y;
		}
	}
	return ret;
}
 
int main(){
	freopen("milktemp.in","r",stdin);
	freopen("milktemp.out","w",stdout);
	scanf("%d %d %d %d", &N, &X, &Y, &Z);
	T = 0;
	minT = 1000000000;
	maxT = 0;
	for (int i=0; i<N; i++) {
		scanf("%d %d",&A[i], &B[i]);
		minT = min(minT, A[i]);
		maxT = max(maxT, B[i]);
	}
	int res = 0;
	for (int i=minT; i<=maxT; i++) {
		res = max(res, check(i));
	}
	printf("%d\n", res);
	return 0;
}
