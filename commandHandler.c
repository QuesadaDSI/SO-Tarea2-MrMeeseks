#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include "amountGenerator.h"


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
        
        if(scanf("%d%c", &dif, &term) != 2 || term != '\n'){
            flag = false;
            empty_stdin();
        }
        else if(dif>=0 && dif <=100) flag = true;

        else{
            flag = false;
            empty_stdin();
        }
    } while (flag != true);
    return dif;
}

void difficulty(){
    int flag;
    struct Results curr;
    do{
		printf("\nDifficulty: \n   1) Leave it to Mr. Meeseeks \n   2) You decide\n\n> ");
        scanf("%d", &flag);
		switch(flag){
            case 1:
                ;
                curr = generateAll();
                printf("Difficulty generated: %d\n", curr.number);
                printf("Amount of processes: %d\n", curr.process);
				empty_stdin();
                break;

            case 2:
                ;
                int dif = validateInt();
                
                curr = generateProcesses(dif);
                printf("Difficulty generated: %d\n", curr.number);
                printf("Amount of processes: %d\n", curr.process);
				empty_stdin();
                break;
            default:
                printf("Can't do! Mr. Meeseks does not understand. Try again!\n\n");
        }
    } while(flag != 2);
}

void commandHandler(){
    int flag;
    
    do{
		printf("\nI'm Mr. Meeseeks, look at me! \n   1) Textual command \n   2) Operations \n   3) Execute program \n   4) Exit \n\n> ");
        scanf("%d", &flag);
		switch(flag){
            case 1:
                difficulty();

            case 2:
                //printf("Math");
				empty_stdin();
                break;
            case 3:
                printf("Execute");
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