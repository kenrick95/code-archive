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
struct tupl { int a, b; };

int f(int a, int b) {
	return ((7 * a + 57 * b) % 21);
}

tupl g(int x) {
	tupl y;
	y.a = x % 3;
	y.b = x % 7;
	return y;
}

int main(){
	int i,j;
	tupl k;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 7; j++) {
			printf("f(%d,%d) = %d\n",i,j,f(i,j));
		}
	}
	
	printf("\n");
	for (i = 0; i < 21; i++) {
		k = g(i);
		printf("g(%d) = (%d,%d)\n",i,k.a, k.b);
	}
	
	printf("\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 7; j++) {
			k = g(i);
			printf("f o g (%d,%d)  = %d\n",i,j,f(k.a, k.b));
		}
	}
	return 0;
}
