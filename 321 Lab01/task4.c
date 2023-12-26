#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMAIL_LEN 100

int main()
{
    int i, j, temp;
    char email[MAX_EMAIL_LEN];
    printf("Enter Email: ");
    fgets(email, MAX_EMAIL_LEN, stdin);
    char substr[20] = "@sheba.xyz";
    for (i = 0; email[i] != '\0'; i++)
    {
        j = 0;
        if (email[i] == substr[j])
        {
            temp = i + 1;
            while (email[i] == substr[j])
            {
                i++;
                j++;
            }
            if (substr[j] == '\0')
            {
                printf("Email address is okay\n");
                exit(0);
            }
            else
            {
                i = temp;
                temp = 0;
            }
        }
    }
    if (temp == 0)
        printf("Email address is outdated\n");
    return 0;
}