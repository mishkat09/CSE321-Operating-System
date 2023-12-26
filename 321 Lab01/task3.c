#include <stdio.h>
#include <string.h>
#include <ctype.h>

void check(char *pass)
{
    int len = strlen(pass);
    int lower = 0, upper = 0, digit = 0, special = 0;
    char spc_char[] = {'_','$','#','@'};
    for (int i = 0; i < len; i++) {
        if (islower(pass[i]))
        lower = 1;
        if (isupper(pass[i]))
        upper = 1;
        if (isdigit(pass[i]))
        digit = 1;
        for(int j=0; j < 4; j++)
        {
            if (spc_char[j] == pass[i])
            special = 1;
        }
    }
    if(lower == 0)
    {
        printf("Lower case missing, ");
    }
    if(upper == 0)
    {
        printf("Upper case missing, ");
    }
    if(digit == 0)
    {
        printf("Digit missing, ");
    }
    if(special == 0)
    {
        printf("Special character missing");
    }
    if(lower == 1 && upper == 1 && special == 1 && digit == 1)
    {
        printf("Ok");
    }
}

int main()
{
    char pass[100];
    printf("Enter password:\n");
    fgets(pass, 100, stdin);
    pass[strcspn(pass, "\n")] = 0;
    check(pass);
    return 0;
}