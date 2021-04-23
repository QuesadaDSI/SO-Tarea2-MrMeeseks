#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <semaphore.h>
#include "amountGenerator.h"
#include "createMeeseeks.h"
#include "createMeeseeksText.h"

int meeseeksI; 

struct counter
{
    int meeseeksCount;
    int requestCount;
};

void empty_stdin (void) /* simple helper-function to empty stdin */
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

int validateInt(){
    bool flag = false;
    int dif;
    char term;
    do{
        printf("Enter diffiulty: ");
        scanf("%d", &dif);
        if(dif>=0 && dif <=100){
              flag = true; 
        } 
        else if(scanf("%d%c", &dif, &term) != 2 || term != '\n'){
            flag = false;
            empty_stdin();
            printf("Please enter a valid number");
        }
        else{
            flag = false;
            empty_stdin();
            printf("Please enter a valid number");
        }
    } while (flag != true);
    return dif;
}


void difficulty(){
    int flag;
    struct Results curr;
    char request[100];
    printf("\nEnter your request for Mr.Meeseeks\n>");
    scanf("%s", request);
    do{
		printf("\nDifficulty: \n   1) Leave it to Mr. Meeseeks \n   2) You decide\n\n> ");
        scanf("%d", &flag);
		switch(flag){
            case 1:
                ;
                curr = generateAll();
                printf("Difficulty generated: %d\n", curr.number);
				empty_stdin();
                newMeeseeksText(curr.number); //Crea los tres mee6 minimos para tareas "textuales"
                break;

            case 2:
                ;
                int dif = validateInt();
                curr = generateProcesses(dif);
				empty_stdin();
                newMeeseeksText(curr.number);
                break;
            default:
                printf("Can't do! Mr. Meeseks does not understand. Try again!\n\n");
        }
    } while(flag != 2);
}

struct counter commandHandler(){
    int flag;
    struct counter c;
    int reqCount = 0;
    c.meeseeksCount = 0;
    c.requestCount = 0;
    //sem_init(&semaforo,1,1);
    do{
		printf("\nThis is Box. Select an option:\n   1) Textual command \n   2) Operations \n   3) Execute program \n   4) Exit \n> ");
        scanf("%d", &flag);
		switch(flag){
            case 1:
                ;
                //pedir la fucking consulta
                //sem_wait(&semaforo);
                reqCount++;
                difficulty();
                empty_stdin();
                break;
                //sem_post(&semaforo);
            case 2:
                ;
                //sem_wait(&semaforo);
                reqCount++;
                int mee6Op = newMeeseeksOperation();
				empty_stdin();
                c.meeseeksCount += mee6Op;
                //sem_post(&semaforo);
                break;
            case 3:
                ;
                //sem_wait(&semaforo);
                reqCount++;
                int mee6Exec = newMeeseeksExec();
				empty_stdin();
                c.meeseeksCount += mee6Exec;
                //sem_post(&semaforo);
                break;
            case 4:
                printf("Existence is pain!\n\n");
                empty_stdin();
                break;
            default:
                printf("Can't do! Mr. Meeseks does not understand. Try again!\n\n");
        }
    } while(flag != 4);
    c.requestCount = reqCount;
    return c;
}