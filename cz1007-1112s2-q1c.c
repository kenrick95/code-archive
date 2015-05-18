#include <stdio.h>
 
int digitPos(int n, int digit) {
    /*printf("%d\n", n);*/
    int tmp = 0;
    if (n % 10 == digit)
        return 1;
    else if (n<0)
        return 0;
    else {
        tmp = digitPos(n/10, digit);
        return (tmp == 0) ? 0 : (tmp + 1);
    }
}
 
int main() {
    printf("%d\n", digitPos(1234567890, 3));
    printf("%d\n", digitPos(1234567890, 0));
    printf("%d\n", digitPos(1234567890, 1));
    return 0;
}
