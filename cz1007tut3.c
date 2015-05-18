#include <stdio.h>

int number;
int *p;
int some_other;

int main() {
    number = 8;
    some_other = 1;
    p = &some_other;
    printf("%d %p %p %p %d", number, &number, p, &p, *p);
    return 0;
}
