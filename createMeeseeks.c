#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "mathHandler.c"
#include "execHandler.c"

int newMeeseeksOperation()
{
    //float simulationTime = timeGenerator();
    pid_t pid;
    pid = fork();
    if (pid<0){
        fprintf(stderr,"Meeseeks creation failed");
    }
    else if (pid == 0){
        printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d)\n", getpid(), getppid());
        mathHandler();
        //sleep(simulationTime);
        exit(0);
    }
    else{
        //printf("Original Meeseeks");
        waitpid(pid,NULL,0);
    }
    return 1;
}

int newMeeseeksExec()
{
    //float simulationTime = timeGenerator();
    pid_t pid;
    pid = fork();
    if (pid<0){
        fprintf(stderr,"Meeseeks creation failed");
    }
    else if (pid == 0){
        printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d)\n", getpid(), getppid());
        //sleep(simulationTime);
        execHandler();
        exit(0);
    }
    else{
        //printf("Original Meeseeks");
        waitpid(pid,NULL,0);
    }
    return 1;
}
