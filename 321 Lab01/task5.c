#include <stdio.h>
#include <string.h>

int main() {
    char strg[1000];
    printf("Enter string : ");
    scanf("%s", strg);
    char *x1, *x2;
    x1 = strg + strlen(strg) - 1;
    x2 = strg;
    int n = 0;
    while (x1 >= x2) {
        if (*x1 == *x2) {
            x1--;
            x2++;
        } else {
            n = 1;
            break;
        }
    }
    if (n) {
        printf("Not Palindrome");
    } else {
        printf("Palindrome");
    }
    return 0;
}
