#include <stdio.h>

int main ( )  {
    struct s1 {
        char c[4], *s;
    } e1 = {"abc", "123"};
    struct s2 {
            char *p;
            struct s1 ss1;
        } e2 = {"xyz", {"def", "456"}};
    printf("%c%c\n", e1.c[0], *e1.s);
    printf("%s%s\n", e1.c, e1.s);
    printf("%s%s\n", e2.p, e2.ss1.s);
    printf("%s%s\n", ++e2.p, ++e2.ss1.s);
    return 0;
}
