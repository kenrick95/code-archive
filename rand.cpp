/* rand example: guess the number */
#include <stdio.h> /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */
 
int main ()
{
int iSecret, iGuess;
 
/* initialize random seed: */
srand (time(NULL));
 
for (int i = 0; i<=100; i++) {
iSecret = rand() % 2;
 
printf("%d\n",iSecret);
}
return 0;
}
