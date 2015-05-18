#include <cstdio>
int main(){
    int i,j,n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++ ){ 
        for (j = 1; j <= n; j++ ){ 
            printf("%d", (j + i - 2) % n + 1);
        }
        printf("\n");
    }
    
	return 0;
}
