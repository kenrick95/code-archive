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


int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int len;
    bool pal;
	char st[50];
    gets(st);
    
    
    len = strlen(st);
    for (int i = 0; i < len; i++) {
        if (st[i] >= 97) {
            st[i] -= 32;
        }
    }
    
    
    pal = true;
    bool valid = false;
    // if all invalid chars, return false; but this one still true
    int backptr = len-1;
    for (int i = 0; i < len; ) {
        
        if ((48 <= st[i] && st[i] <= 57) || (65 <= st[i] && st[i] <= 90)) {
            if ((48 <= st[backptr] && st[backptr] <= 57) || (65 <= st[backptr] && st[backptr] <= 90)) {
                valid = true;
                if (st[i] != st[backptr]) {
                    pal = false;
                }
                backptr--;
                
            } else {
                backptr--;
                continue;
            }
            i++;
        } else {
            i++;
            continue;
        }
        
        
    }
    if (pal && valid) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    
	return 0;
}
