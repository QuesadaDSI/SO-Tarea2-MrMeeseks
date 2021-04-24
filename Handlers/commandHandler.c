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

void empty_stdin (void) /* simple helper-function to empty stdin */
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

//Funcion para verificar si la dificultad ingresada
//Para las consultas textuales es un numero entero u otro caracter
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

//Funcion para el manejo del nivel de dificultad de las consultas textuales 
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
            //Manejo del nivel de dificultad determinado por el Meeseeks 
            case 1:
                ;
                curr = generateAll();
                printf("Difficulty generated: %d\n", curr.number);
				empty_stdin();
                newMeeseeksText(curr.number); 
                break;
            //Manejo del nivel de dificultad determinado por el usuario
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

//Funcion para el manejo de los distintos tipos de consultas
void commandHandler(){
    int flag;
    do{
		printf("\nThis is Box. Select an option:\n   1) Textual command \n   2) Operations \n   3) Execute program \n   4) Exit \n> ");
        scanf("%d", &flag);
		switch(flag){
            case 1:
                ;
                difficulty();
                empty_stdin();
                break;
            case 2:
                ;
                int mee6Op = newMeeseeksOperation();
				empty_stdin();
                break;
            case 3:
                ;
                int mee6Exec = newMeeseeksExec();
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