#include<stdio.h>
int main()
{
    int length;
    char string[] =" I  love  python  programming ";
    length = sizeof(string)/sizeof(string[0]);
    for(int i=0;i<length;i++){
        if(string[i]==' '){
            for(int j=i;j<length;j++)
                {
                    string[j]=string[j+1];
                }

        }
    }
    printf("%s",string);
}
