#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>


int main()
{
    int pid, status;
    pid = fork();
    
    if (pid==0){
        int npid =fork();
       
        
        if (npid ==0){
            printf("I am grandchild \n");
        }
        else{
            wait(&status);
            printf("I am child \n");
        }
    }
    else{
        wait(&status);
        printf("I am parent \n");
    }
    
    

    return 0;
}
