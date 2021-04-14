#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "createMeeseeks.h"

void requestHandler(){
	//revisar que tipo de consulta
	int requestType;
	printf("Que tipo de consulta?\n1)Consulta aritmetica\n2)Consulta de otro tipo\n>");
	scanf("%d",&requestType);
	if (requestType == 1){
		//artimetica
		//llama un solo meeseeks
		printf("Llame un meeseeks para el calculo\n");
		newMeeseeks();
	}
	else if (requestType == 2){
		printf("Llame un meeseeks para el calculo\n");
		//obtener dificultad
		//random o ingresa		
	}
	else{
		printf("Seleccione una opcion validad");
	}
}