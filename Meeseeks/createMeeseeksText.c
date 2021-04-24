#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <string.h>
#include <sys/wait.h>

//Cantidad máxima de hijos que se determinaron se pueden tener al mismo tiempo
//Si se pasa de la cantidad de hijos, Linux tira error que muchos archivos están abiertos
//Tras este valor no se pueden hacer más mediciones
#define MAX_CHILDREN 508

//Genera un un valor aleatorio entre 0.5 y 5.0 segundos 
//Genera valores de 1 punto decimal
float timeGenerator (){
    float random_value;
    srand(time(NULL));
    random_value = 0.5 + (float)rand()/RAND_MAX*4.5;
    random_value = floorf(random_value*100)/100;
    return random_value;
}

//"Infla" el valor de la dificultad
//Cada nodo "apoya" o infla el valor de la dificultad, por lo cual, conforme mayor sea la dificultad (más fácil el request) más va a aportar el nodo actual
double inflate(double num){
	double divisor = (double)rand()/RAND_MAX + 100;
	double div = num / divisor;
	num += div;
	return num;
}

//"Plan de contingencia" 
//Es un simple print con referencia a la serie; no es una funcion sumamente necesaria
//Ya que el plan de contingencia real esta en el MAX_CHILDRENst) más va a aportar el nodo actual
void rickSanchez(int pid){
	printf("I've been trying to help (the user) for two days, an eternity in Meeseeks time, and nothing's worked\n");
}

//Funcion para el manejo de las solicitudes textuales
int newMeeseeksText( int difficulty, int meeseeksI )
{
	int childrenCounter = 0;
	//Nivel de dificultad, tiene que ser la variable que cambia y se pasa por pipes
    double diff = (double)difficulty; 											    
    int meeseeksIText = meeseeksI;
    //Tiempo entre 0.5 y 5 segundos que va a durar la simulacion
    float simulationTime = timeGenerator();
    //Declaracion de variables de tiempo a utilizar para usar un "temporizador"
    //Y detener el programa si su tiempo es mayor al declarado para la simulacion										
    time_t start_time;
    time_t current_time;
    time(&start_time);
    time(&current_time);
    double timeDiff;
    printf("Simulation Time> %f\n", simulationTime);
    //Manejo del tiempo de simulacion
    while (timeDiff < simulationTime){
    	pid_t pid;
    	//Declaracion del pipe utilizado para comunicacion padre->hijo
	    int fd[2];
	    //Declaracion del pipe utilizado para comunicacion hijo->padre
	    int fdC[2];
	    int solved = 0;
	    int parentProcess;
	    for(int num_process = 1; num_process < MAX_CHILDREN+1; num_process++){
	   		timeDiff =  difftime(current_time, start_time);
	   		time(&current_time);
	   		//Revisa si el nivel de dificultad aumento al punto de ser resuelto
	    	if (diff >= 85){	    																
	    		solved = 1;
	    		printf("Your request has been solved! Look at meeeeeeee!\n");
	    		return childrenCounter;
	    	}
	    	//Declaracion de los pipes a utilizar y revision de fallo
	    	if(pipe(fd) == -1){
	    		perror("Parent Pipe failed\n");
	    		continue;
	    	}

	    	if(pipe(fdC) == -1){
	    		perror("Child Pipe failed\n");
	    		continue;
	    	}
	    	pid = fork();
	    	if (pid < 0){
	    		perror("Fork failed\n");
	    		exit(1);
	    	}
	    	//Codigo del proceso hijo	
	    	if (pid == 0){																													
	    		double newDiff;
	    		int i = meeseeksIText + num_process;
	    		printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d,%d,%d)\n", getpid(), getppid(),num_process,i);
	    		close(fd[1]);
	    		//Lee del pipe
	    		if (read(fd[0], &newDiff, sizeof(newDiff)) <= 0){					
	    			perror("Read failed\n");
	    			exit(EXIT_FAILURE);
	    		}
	    		//Cambia el valor de dificultad utilizando la funcion inflate
	    		newDiff = inflate(newDiff);
	    		//Escribe en el pipe el dado modificado
	    		close(fdC[0]);
	    		write(fdC[1], &newDiff,sizeof(newDiff));
	    		exit(0);
	    	}
	    	//Codigo del proceso padre
	    	else{																	
	    		parentProcess = getpid();
	    		//Escribe en el pipe el nivel de dificultad
	    		close(fd[0]);
	    		write(fd[1], &diff,sizeof(diff));
	    		wait(NULL);
	    		double diffFromChild;
	    		close(fdC[1]);
	    		//Lee del pipe
	    		if (read(fdC[0], &diffFromChild, sizeof(diffFromChild)) <= 0){					
	    			perror("Read failed\n");
	    			exit(EXIT_FAILURE);
	    		}
	    		diff = diffFromChild;
	    	}
	    	childrenCounter = num_process;
	    }
	    //Plan de contingencia
	    //No se puede sobre pasar del numero escogido de procesos hijos
	    //Este se escogio debido a que despues de varias pruebas se verifico que el mayor numero de pipes
	    //Que se pueden manejar es de 509
	    if( childrenCounter = MAX_CHILDREN && solved == 0){
	    	printf("Meeseeks don't usually have to exist this long!\n");
	    	rickSanchez(parentProcess);
	    	return childrenCounter;
	    }
	    return childrenCounter;
    }
    printf("I don't think this is working. I give up.\n");
    printf("(Unable to execute).\n");
  	return childrenCounter;
}