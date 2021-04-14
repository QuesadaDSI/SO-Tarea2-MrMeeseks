#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int newMeeseeks()
{
	pid_t pid;
    pid = fork();
    if (pid<0){
        fprintf(stderr,"Fallo en creación de Meeseeks");
    }
    else if (pid == 0){
        printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d)\n", getpid(), getppid());
    }
    else{
        printf("Meeseeks original");
    }
    return 0;
}
