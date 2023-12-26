#include<stdio.h>

int isPerfect(int num)
{
   //variables
   int i,sum=0;
 
   for(i=1;i<=num/2;i++)
       if(num%i==0)  
           sum += i;
   if(sum == num)
       return 1;
   //else return 0
   return 0;
}
//driveer program
int main()
{

   int i;
 
   printf("The Starting Number : 1 \n");
   printf("The Ending Number : 1000 \n");
   for(i=1;i<=1000;i++)
       if(isPerfect(i))   //function calling
           printf("%d ",i);
}