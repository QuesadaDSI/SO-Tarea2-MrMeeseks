#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "commandHandler.h"



int validInt(){
    printf("Select an option:\n 1) Create new Meeseeks\n 2) Exit\n> ");
    int num;
    char term;
    if(scanf("%d%c", &num, &term) != 2 || term != '\n'){
        return 4;
    }
        
    else
        return num;
}

int main(){
    printf("--------------------------------------------------------\n");
    printf("This is a Meeseeks Box. Let me show you how it works.\n"
            "You press this, you make a request (Mr. Meeseeks, open Jerry's stupid mayonnaise jar),the Meeseeks fulfills the request aaaaand then it stops existing.\n"
            "Trust me, they are fine with it.\n"
            "Knock yourselves out, just *burps* keep your request simple, they're not gods.\n");
    printf("--------------------------------------------------------\n");

    int flag;
    int requestQuantity = 0;
    int meeseeksQuantity = 0;
    struct counter C;
    do{
        flag = validInt();
        switch(flag){
            case 1:
                ;
                C = commandHandler();
                break;
            case 2:
                meeseeksQuantity = C.meeseeksCount;
                requestQuantity = C.requestCount;
                printf("Goodbye\n");
                printf("Total amount of tasks %d\n",requestQuantity);
                printf("Total amount of Meeseeks created %d\n", meeseeksQuantity);
                break;
            default:
                printf("Cannot understand, try again\n\n");
                printf("Select an option:\n 1) Create new Meeseeks\n 2) Exit\n> ");
                empty_stdin();
                break;
        }

    } while (flag != 2);

    return 0;
}
