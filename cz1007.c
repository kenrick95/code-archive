#include <stdio.h>

int strcmp(char *s1, char *s2) {
    int i = 0;
    while (s1[i] == s2[i]) i++;
    return (s1[i] < s2[i]) ? -1 : (s1[i] > s2[i]);
}

int main(){
    printf("%d", strcmp("aaaa", "bbb"));
    printf("%d", strcmp("aaaa", "aaaa"));
    printf("%d", strcmp("bbb", "a"));
    printf("%d", strcmp("b", "a"));
	return 0;
}
