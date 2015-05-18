#include <stdio.h>
int digitValue(int n, int k);
int main()
{
    int num, digit;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the digit position: ");
    scanf("%d", &digit);
    printf("Digit value: %d\n", digitValue(num, digit));
    return 0;
}
int digitValue(int n, int k)
{
    /* add thefunction code here */
    while (k > 1) {
        n /= 10;
        k--;
    };
    return n % 10;
}
