#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
#include <pthread.h>
#include <stdlib.h>

void* Hello(void* arg){
    int num=*(int*)arg;
    printf("thread-%d running \n",num);
    sleep(1);
    printf("thread-%d closed \n",num);
    free(arg);
}


int main(int argc, char* argv[])
{
    pthread_t p1[5];
    
    int i;
    
    for(i=1;i<6;i++){
        
    
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
