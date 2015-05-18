#include <stdio.h>

int main() {
    char ar1[4][6] = {
                    {'P', 'e', 't', 'e', 'r'},
                    {'J','o','h','n','n','y'},
                    {'M','a','r','y'},
                    {'K','e','n','n','y'}
                    };
    char *ar2, *ar3[2];
    char *ptr1, **ptr2, ***ptr3;
    char ch;
    
    printf("%p\n",&ch);
    printf("%p\n",&ptr1);
    printf("%p\n",&ptr2);
    printf("%p\n",&ptr3);
    printf("\n");
    ch = 'a';
    ptr1 = &ch; ptr2 = &ptr1; ptr3 = &ptr2;
    printf("%p\n",&ptr2);
    printf("%p\n",**ptr3);
    printf("%p\n",*ptr3);
    printf("%p\n",*ptr2);
    
    ar2 = &ar1[1][1];
    ar3[0] = &ar1[0][0];
    ar3[1] = &ar1[1][0];
    printf("%s\n", &ar1[0][0]);
    printf("%s\n", &ar1[1][0]);
    printf("%s\n", &ar1[2][0]);
    printf("%s\n", &ar1[3][0]);
    printf("\n");
    printf("%s\n", ar2);
    printf("%s\n", ar3[0]);
    printf("%s\n", ar3[1]);
    
    printf("\n");
    printf("%s\n", &ar1[1][4]);
    printf("%s\n", ar2-3);
    printf("%s\n", ar3[0]+1);
    printf("%s\n", ar3[1]+2);
    
    
    printf("\n");
    printf("%s\n", &ar1[3][0]-1);
    printf("%s\n", &ar1[3][0]-2);
    printf("%s\n", &ar1[3][0]-3);
    printf("%s\n", &ar1[3][0]-4);
    
    return 0;
}
