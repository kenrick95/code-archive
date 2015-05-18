#include <cstdio>
int main(){
	int i;
    for (i = 100; i<=200; i++) {
        freopen("6.pas","w",stdout);
        printf("begin\n");
        printf("writeln('%d')\n", i);
        printf("end.\n");
        fflush(stdout);
    }
	return 0;
}
