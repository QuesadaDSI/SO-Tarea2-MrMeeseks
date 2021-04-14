#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "requestHandler.h"

int main(){
    printf("--------------------------------------------------------\n");
    printf("This is a Meeseeks Box. Let me show you how it works.\nYou press this, you make a request (Mr. Meeseeks, open Jerry's stupid mayonnaise jar),the Meeseeks fulfills the request aaaaand then it stops existing.\nTrust me, they are fine with it.\nKnock yourselves out, just *burps* keep your request simple, they're not gods.\n");
    printf("--------------------------------------------------------\n");
    //press button and make request
    int flag;
    int cantRequest = 0;
    while (flag != 2){
        printf("Presione:\n 1) Crear nuevo Meeseeks\n 2) Salir\n> ");
        scanf("%d",&flag);
        if (flag == 1){
            cantRequest = cantRequest + 1; 
            requestHandler();
        }
        else if((flag != 1) && (flag != 2)){
            printf("Por favor presione el boton.\n");
        }
        if (flag == 2){
            printf("Weno bye\n");
            printf("Cantidad de requests> %d\n",cantRequest);
        }
        printf("--------------------------------------------------------\n");
    }
}
