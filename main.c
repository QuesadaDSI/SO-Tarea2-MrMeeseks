#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdbool.h>
#include "commandHandler.h"

//typedef enum {true,false} bool;
/*
static int get_shared_block(char *filename,int size){
    key_t key;
    key = ftok(filename,0);
    if (key == IPC_RESULT_ERROR){
        return IPC_RESULT_ERROR;
    }
    return shmget(key,size,0644|IPC_CREAT);
}

char * attach_memory_block(char *filename, int size){
    int shared_block_id = get_shared_block(filename,size);
    char *result;
    if (shared_block_id == IPC_RESULT_ERROR){
        return NULL;
    }
    result = shmat(shared_block_id,NULL,0);
    if (result == (char *)IPC_RESULT_ERROR){
        return NULL;
    }
    return result;
}

bool detach_memory_block(char *block){
    return (shmdt(block) != IPC_RESULT_ERROR);
} 

bool destroy_memory_block(char *filename){
    int shared_block_id = get_shared_block(filename, 0);
    if (shared_block_id == IPC_RESULT_ERROR){
        return NULL;
    }
    return(shmctl(shared_block_id, IPC_RMID,NULL) != IPC_RESULT_ERROR);
}
*/
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
    /*
    key_t keyRequest = ftok("requestFile",65);
    key_t keyMeeseeks = ftok("meeseeksFile",65);
    int requestID = shmget(keyRequest, sizeof(int),IPC_CREAT | 777 );
    int meeseeksID = shmget(keyMeeseeks, sizeof(int),IPC_CREAT | 777 );
    int requestQuantity =  shmat(requestID,0,0);
    int meeseeksQuantity = shmat(meeseeksID,0,0);
    if (requestQuantity < 0){
        printf("Error requestQuantity\n");
    }
    if (meeseeksQuantity < 0){
        printf("Error meeseeksQuantity\n");
    }
    printf("requestQuantity is %d\n",requestQuantity);
    printf("meeseeksQuantity is %d\n",meeseeksQuantity);
    */
    struct counter C;
    int meeseeksQuantity;
    int requestQuantity;
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
