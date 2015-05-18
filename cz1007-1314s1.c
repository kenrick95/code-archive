#include <stdio.h>
int f (char *sl, char *s2) ; 
int main ( )  {
    char a[80] = "abcdefg";
    char b[80] = "ace";
    int n = f(a, b);
    printf ("%d %s", n, a); 
    return 0;
}

int f (char *s1, char *s2) {
    int i = 0, j;
    char *s = s1; 
    while ( * (s2+i) != '\0') {
        for (j = 0, s1 = s; *s1 != '\0'; s1++)
            if (*s1 != *(s2+i)) s[j++] = *s1;
        s[j] = '\0';
        i++;
    }
    return j;
}
