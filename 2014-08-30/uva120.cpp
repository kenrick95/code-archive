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
	
    //pancake sorting
    // for each stage, take largest elem of the stage to the bottom by:
    //    flip the largest to the top, and then flip to the bottom
    // done
    int n = 0, a[64], b[64], temp, max_idx;
    char str[256];
    while (fgets(str, 255, stdin)) {

        n = 0;
        int id = 0;
        bool first_ln = true;
        while (str[id] != 0) {
            char temp[5];
            int i = 0;
            while (str[id] != ' ' && str[id] != 0) temp[i++] = str[id++];
            temp[i] = 0;
            a[n++] = atoi(temp);
            if (str[id] == ' ') id++;
            
            if (!first_ln) printf(" ");
            first_ln = false;
            
            printf("%d", a[n - 1]);
        }
        // printf("n = %d\n", n);
        printf("\n");
    
        first_ln = true;
        for (int i = 0; i < n; i++) {
            temp = 0;
            for (int j = 0; j < n - i; j++) {
                if (a[j] > temp) {
                    temp = a[j];
                    max_idx = j;
                }
            }
            // flip [0 ... i], a[0] to a[i]!!!
            
            // printf("[%d] ", max_idx);
            if (max_idx != n-i-1) {
                if (max_idx != 0) {
                    // max elem to top
                    for (int j = 0; j <= max_idx / 2; j++) {
                        swap(a[max_idx-j], a[j]);
                    }
                    
                    if (!first_ln) printf(" ");
                    first_ln = false;
                    printf("%d", n - max_idx);
                }
                // max elem to bottom
                for (int j = 0; j < (n-i) / 2; j++) {
                    swap(a[n-j-i-1], a[j]);
                }
                
                if (!first_ln) printf(" ");
                first_ln = false;
                printf("%d", i+1);
            }
            //printf("\n");
            
            //for (int x = 0; x < n; x++) printf("%d ", a[x]);
            //printf("\n");
        }
        if (!first_ln) printf(" ");
        printf("0\n");
    }
	return 0;
}
