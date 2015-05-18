#include <stdio.h>
/* function prototypes */
long extOddDigits1(long num);
void extOddDigits2(long num, long *result);
int main()
{
    long num, result;
    printf("Enter the number: ");
    scanf("%ld", &num);
    printf("The extracted odd digit number: %ld\n",
    extOddDigits1(num));
    printf("Enter the number: ");
    scanf("%ld", &num);
    extOddDigits2(num, &result);
    printf("The extracted odd digit number: %ld\n", result);
    return 0;
}
long extOddDigits1(long n)
{
    /* add your code here */
    long ret = 0;
    int i = 0, j = 0;
    long odd[101];
    while (n > 0) {
        if ((n % 10) % 2 == 1) odd[i++] = n % 10;
        n /= 10;
    }
    for (j = i-1; j >= 0; j--) ret = ret * 10 + odd[j];
    return (i == 0) ? -1 : ret;
}
void extOddDigits2(long n, long *nd)
{
    /* add your code here */
    *nd = extOddDigits1(n);
    /*
    *nd = 0;
    int i = 0, j = 0;
    long odd[101];
    while (n > 0) {
        if ((n % 10) % 2 == 1) odd[i++] = n % 10;
        n /= 10;
    }
    for (j = i-1; j >= 0; j--) *nd = *nd * 10 + odd[j];
    if (i == 0) *nd = -1;*/
}
