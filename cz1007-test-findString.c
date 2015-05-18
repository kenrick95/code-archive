#include <stdio.h>

int findString (char *s, char *t) {
    // test if s is substring of t
    int i = 0, j = 0;
    while (t[i]) {
        j = 0;
        while (s[j]) {
            if (s[j] == t[i+j])
                j++;
            else
                break;
        }
        if (s[j] == '\0') {
            return 1;
        }
        i++;
    }
    return -1;
}

int main() {
    char st1[500], st2[500];
    scanf("%s", st1);
    scanf("%s", st2);
    printf("%d\n", findString(st1, st2));
    return 0;
}
