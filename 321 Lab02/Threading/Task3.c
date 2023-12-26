#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
#include <pthread.h>
#include <stdlib.h>


static int arr[3];

void check(char y[]){
    
   int len=sizeof(y)/sizeof(y[0]);
   int sum;
   int z;
   for(int i=0;i<len;i++){
       z=y[i];
       sum+=z;
       
   }
   
   arr[sizeof(arr)]=sum;
    
}


void* Hello(void* arg,void*nm){
    int num=*(int*)arg;
    
    char name=*(char*)nm;
    
    check(name);
    

    
    free(arg);
    free(nm);
}


int main(int argc, char* argv[])
{
    pthread_t p1[3];
    
    int i;
    
    int res;
    
    for(i=0;i<3;i++){
        
        char nm[20];
        
        printf("Enter name: ");
        scanf("%s",nm);
        
    
    int* a=malloc(sizeof(int));
    *a =i;
    
     char* b=malloc(sizeof(char));
    *b =nm;
    
    if(pthread_create(&p1[i],NULL,&Hello,b)!=0){
        return 1;
        
    }
    
    if (pthread_join(p1[i],NULL)!=0){
        return 2;
    }
    
 
    }
    
    if(arr[0]==arr[1]==arr[2]){
        printf("Youreka");
        
    }
    
    else if(arr[0]==arr[1]||arr[0]==arr[2]||arr[1==arr[2]]){
        printf("Miracle");
    }
    else{
        printf("Hasta LI Vista");
    }

    return 0;
    
}