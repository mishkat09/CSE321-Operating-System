#include<stdio.h>
#include<sys/types.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{
  
   int count=1;
 
   int a = fork();
  
   count+=1;
   int b = fork();
   count+=1;
   int c = fork();
   count+=1;
   int d=0;
   int e=0;
   int f=0;
  
   
   
   if( a%2 !=0){
       int d=fork();
       count+=1;
   }
   
   if( b%2 !=0){
       int e=fork();
       count+=1;
   }
   
   if( c%2 !=0){
       int f=fork();
       count+=1;
   }
   
  
    printf("Total process created: %d ",count);
       
   
   
 
   return 0;
}
