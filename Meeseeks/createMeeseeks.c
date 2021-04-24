#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../Handlers/mathHandler.c"
#include "../Handlers/execHandler.c"

//Meeseek (fork()) generado para el manejo de consultas aritmeticas
int newMeeseeksOperation(int meeseeksI)
{
    pid_t pid;
    pid = fork();
    if (pid<0){
        fprintf(stderr,"Meeseeks creation failed");
    }
    else if (pid == 0){
        int i = meeseeksI + 1;
        printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d,%d,%d)\n", getpid(), getppid(),1, i);
        //Llamada a la funcion para el manejo de la operacion aritmetica
        mathHandler();
        exit(0);
    }
    else{
        waitpid(pid,NULL,0);
    }
    return 1;
}

//Meeseek (fork()) generado para el manejo de consultas de ejecucion de programas externos
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
        //Llamada a la funcion para el manejo de la ejecucion
        execHandler();
        exit(0);
    }
    else{
        waitpid(pid,NULL,0);
    }
    return 1;
}
