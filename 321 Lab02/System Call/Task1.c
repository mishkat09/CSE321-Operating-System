#include <stdio.h>


#define size 1000

int main(int argc, char* argv[])
{
   char c;
   FILE *fp;
   fp = fopen("C:\\newfolder\\Tak2.1.txt","w");
   
   if(fp==NULL){
       printf("unable to create");
   }

   
   
   while (TRUE){
       
       
   printf("Enter string : \n");
    fgets(c, size, stdin);

   
   if(c=="-1"){
       break;
   }
   

    fputs(data, fP);
    
}
    fclose(fP);


   return 0;
}