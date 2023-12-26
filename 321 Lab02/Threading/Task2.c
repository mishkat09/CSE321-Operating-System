#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
#include <pthread.h>
#include <stdlib.h>

void prnt(int x){
    
    static int a=1;
    int b=x;
    
      for(int i=x;i<x+5;i++){
        printf("Thread %d Prints %d \n",b,a);
        a++;
    
}
}

void* Hello(void* arg){
    int num=*(int*)arg;
    
    
    
    prnt(num);
    
    free(arg);
}


int main(int argc, char* argv[])
{
    pthread_t p1[5];
    
    int i;
    
    for(i=0;i<5;i++){
        
    
    int* a=malloc(sizeof(int));
    *a =i;
    
    if(pthread_create(&p1[i],NULL,&Hello,a)!=0){
        return 1;
        
    }
    
    if (pthread_join(p1[i],NULL)!=0){
        return 2;
    }
    
 
    }

    return 0;
    
}

