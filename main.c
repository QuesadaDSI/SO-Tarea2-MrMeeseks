#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
#include <stdbool.h>


#include <string.h>
#include <time.h>
#include "amountGenerator.h"
#include "createMeeseeks.h"
#include "createMeeseeksText.h"

typedef struct {
    int mee6;
    int request;
    sem_t sem;
} SharedStuff;

SharedStuff *shCounter;

void createCounter(){
    size_t size = sizeof(SharedStuff);
    shCounter = (SharedStuff *) mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    sem_init(&shCounter->sem, 1, 1);
    shCounter->mee6 = 0;
    shCounter->request = 0;
}

void addToStuff(int i) {
    sem_wait(&shCounter->sem);
    shCounter->mee6 += i;
    shCounter->request += 1;
    sem_post(&shCounter->sem);
}

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


int difficulty(int meeseeksI){
    int flag;
    struct Results curr;
    char request[100];
    int meeseeksCreated;
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
                meeseeksCreated = newMeeseeksText(curr.number,meeseeksI); //Crea los tres mee6 minimos para tareas "textuales"
                break;

            case 2:
                ;
                int dif = validateInt();
                curr = generateProcesses(dif);
                empty_stdin();
                 meeseeksCreated = newMeeseeksText(curr.number,meeseeksI);
                break;
            default:
                printf("Can't do! Mr. Meeseks does not understand. Try again!\n\n");
        }
    } while(flag != 2);
    //printf("Se hicieron estos Meeseeks en difficulty> %d\n",meeseeksCreated);
    return meeseeksCreated;
}

void commandHandler(){
    int flag;
    do{
        printf("\nThis is Box. Select an option:\n   1) Textual command \n   2) Operations \n   3) Execute program \n   4) Exit \n> ");
        scanf("%d", &flag);
        int currentMeeseeks = shCounter->mee6;
        //printf("Current Meeseeks > %d\n", currentMeeseeks);
        switch(flag){
            case 1:
                ;
                int textualMeeseeksCreated = difficulty(currentMeeseeks);
                //printf("Se hicieron estos Meeseeks al final> %d\n",textualMeeseeksCreated);
                addToStuff(textualMeeseeksCreated);
                empty_stdin();
                break;
            case 2:
                ;
                int mee6Op = newMeeseeksOperation(currentMeeseeks);
                addToStuff(1);
                empty_stdin();
                break;
            case 3:
                ;
                int mee6Exec = newMeeseeksExec(currentMeeseeks);
                addToStuff(1);
                empty_stdin();
                break;
            case 4:
                printf("Existence is pain!\n\n");
                empty_stdin();
                break;
            default:
                printf("Can't do! Mr. Meeseks does not understand. Try again!\n\n");
        }
    } while(flag != 4);
}


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
    createCounter();
    printf("--------------------------------------------------------\n");
    printf("This is a Meeseeks Box. Let me show you how it works.\n"
            "You press this, you make a request (Mr. Meeseeks, open Jerry's stupid mayonnaise jar),the Meeseeks fulfills the request aaaaand then it stops existing.\n"
            "Trust me, they are fine with it.\n"
            "Knock yourselves out, just *burps* keep your request simple, they're not gods.\n");
    printf("--------------------------------------------------------\n");

    int flag;
    do{
        flag = validInt();
        switch(flag){
            case 1:
                ;
                commandHandler();
                break;
            case 2:
                printf("Goodbye\n");
                printf("Total amount of tasks %d\n",shCounter->request);
                printf("Total amount of Meeseeks created %d\n", shCounter->mee6);
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
