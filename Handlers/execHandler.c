#include <stdlib.h>

void execHandler(){
    //Funcion para el manejo de la ejecucion
    //Variable donde se almacena el nombre del programa que se desea ejecutar
    char fileName[60];
    printf("-------------------------------------\n");
    printf("Please input the program file name\n> ");
    scanf("%s", fileName);
    char handle[3] = "./";
    //Se concatena el nombre del archivo con "./" para poder pasarse como un comando al sistema
    strncat(handle,fileName,60);
    printf("--------(program execution)----------\n");
    //La funcion "reservada" system permite ejecutar el parametro que se le pase como un 
    //Comando en consola
    int status = system(handle);
    if (status == -1){
    	printf("Program not executed! Existence is pain\n");
    }
    else{
    	printf("Program executed! Look at meeeeee\n");
    }
    printf("-------------------------------------\n");
}