#include <stdio.h>
void function0();
void function1(int h, int k);
void function2(int *h, int *k);
int main()
{
int h, k;
h = 5;
k = 15;
printf("h = %d, k = %d\n", h, k); /* line (i) */
function0();
printf("h = %d, k = %d\n", h, k); /* line (ii) */
function1(h, k);
printf("h = %d, k = %d\n", h, k); /* line (iii) */
function2(&h, &k);
printf("h = %d, k = %d\n", h, k); /* line (iv) */
return 0;
}
void function0()
{
int h, k;
h = k = -100;
printf("h = %d, k = %d\n", h, k); /* line (v) */
}
void function1(int h, int k)
{
printf("h = %d, k = %d\n", h, k); /* line (vi) */
h = k = 100;
printf("h = %d, k = %d\n", h, k); /* line (vii) */
}
void function2(int *h, int *k)
{
printf("h = %d, k = %d\n", *h, *k); /* line (viii) */
*h = *k = 200;
printf("h = %d, k = %d\n", *h, *k); /* line (ix) */
}
