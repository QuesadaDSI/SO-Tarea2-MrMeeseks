#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int newMeeseeksOperation()
{
    pid_t pid;
    pid = fork();
    if (pid<0){
        fprintf(stderr,"Meeseeks creation failed");
    }
    else if (pid == 0){
        printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d)\n", getpid(), getppid());
    }
    else{
        printf("Original Meeseeks");
    }
    return 0;
}

int newMeeseeksExec()
{
    pid_t pid;
    pid = fork();
    if (pid<0){
        fprintf(stderr,"Meeseeks creation failed");
    }
    else if (pid == 0){
        printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d)\n", getpid(), getppid());
    }
    else{
        printf("Original Meeseeks");
    }
    return 0;
}
