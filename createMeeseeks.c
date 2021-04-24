#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "mathHandler.c"
#include "execHandler.c"

int newMeeseeksOperation(int meeseeksI)
{
    //float simulationTime = timeGenerator();
    pid_t pid;
    pid = fork();
    if (pid<0){
        fprintf(stderr,"Meeseeks creation failed");
    }
    else if (pid == 0){
        int i = meeseeksI + 1;
        printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d,%d,%d)\n", getpid(), getppid(),1, i);
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

int newMeeseeksExec(int meeseeksI)
{
    pid_t pid;
    pid = fork();
    if (pid<0){
        fprintf(stderr,"Meeseeks creation failed");
    }
    else if (pid == 0){
        int i = meeseeksI + 1;
        printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d,%d,%d)\n", getpid(), getppid(),1, i);
        execHandler();
        exit(0);
    }
    else{
        waitpid(pid,NULL,0);
    }
    return 1;
}
