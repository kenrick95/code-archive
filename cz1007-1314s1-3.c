#include <stdio.h>

void countZeros(int num, int *count) {
    if (num < 10) {
        *count = (num == 0);
    } else {
        countZeros(num / 10, count);
        if (num % 10 == 0) (*count)++;
    }
}

int main ()  {
    int count = 0;
    countZeros(101020, &count);
    printf("%d\n", count);
    return 0;
}
