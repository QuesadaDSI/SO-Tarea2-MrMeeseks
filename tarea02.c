#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void createMeeseeks(){
    pid_t pid;
    pid = fork();
    if (pid<0){
        fprinf(stderr,"Fallo en creación de Meeseeks");
    }
    else if (pid == 0){
        printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d,%d,%d)", getpid(), getppid(), N, i;)
    }
}

int main(){
    printf("--------------------------------------------------------\n");
    printf("This is a Meeseeks Box. Let me show you how it works\n 
    You press this, you make a request (Mr. Meeseeks, open Jerry's stupid mayonnaise jar),
    the Meeseeks fulfills the request aaaaand then it stops existing.\n
    Trust me, they are fine with it.\n
    Knock yourselves out, just *burps* keep your request simple, they're not gods.");
    printf("--------------------------------------------------------\n");
    printf("Ingrese el número del tipo de su solicitud.\n
    1) Operacion aritmética\n
    2) Consulta textual\n
    Solicitud > ");
    int requestType;
    scanf("%d",&requestType);
    

}
