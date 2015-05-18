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

bool monkeyTrouble(bool aSmile, bool bSmile) {
    return !!(aSmile^bSmile);
}

int countXX(char* str) {
    if (str[1] == '\0') return 0;
    return (str[0] == 'x' && str[1] == 'x') + countXX(str + 1);
}

void string_bits(char* str) {
    int n = 1;
    while (*str != '\0') {
        if (n) printf("%c", *str);
        n = !n;
        str++;
    }
    printf("\n");
}

int squirrelPlay (int temp, bool isSummer) {
    return (isSummer) ? (60 <= temp && temp <= 100) : (60 <= temp && temp <= 90);
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	printf("monkeyTrouble\n");
	printf("%d\n", monkeyTrouble(1, 1));
	printf("%d\n", monkeyTrouble(1, 0));
	printf("%d\n", monkeyTrouble(0, 1));
	printf("%d\n", monkeyTrouble(0, 0));
    
    
	printf("CountXX\n");
	printf("%d\n", countXX("abcxx"));
	printf("%d\n", countXX("xxx"));
	printf("%d\n", countXX("xxxx"));
	printf("%d\n", countXX("x"));
    
    int arr[100], n;
	printf("sameFirstLast\n");
	printf("input N then followed by N numbers;\n");
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
	printf("%d\n", (n >= 1) && (arr[0] == arr[n-1]));
    
    
	printf("string_bits\n");
	string_bits("Hello");
	string_bits("Hi");
	string_bits("Heeololeo");
    
    
    printf("squirrelPlay\n");
	printf("%d\n", squirrelPlay(70, false));
	printf("%d\n", squirrelPlay(95, false));
	printf("%d\n", squirrelPlay(95, true));
    
	return 0;
}
