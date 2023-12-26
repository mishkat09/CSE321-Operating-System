#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
#include <stdlib.h>

int main()
{
    int pid;
    
    printf("Parent process ID %d \n", getppid());
    pid=fork();
    
    if(pid>0){
        printf("Child process ID %d \n",pid);
        int a=fork();
        
        if(a>0){
        
        printf("Grandchild process ID %d \n",a);
        
        int b=fork();
        
        printf("Grandchild process ID %d \n",b);
        
        
        }
        
        
    
        
    }
    
    

    return 0;
}
