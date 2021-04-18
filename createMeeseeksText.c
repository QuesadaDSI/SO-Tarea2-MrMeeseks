#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
//#include <pthread.h>
/*
void* newMeeseeksAux(){
	pid_t pid;
	pid = fork();
	if (pid < 0){
		fprintf (stderr,"Meeseeks creation failed");
	}
	else if (pid == 0){
		printf("(PT)Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d)\n", getpid(), getppid());
		exit(0);
	}
	else if (pid > 0){
		printf("(PT)Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d)\n", getpid(), getppid());
		waitpid(pid,NULL,0);
	}
	return NULL;
}
*/

float timeGenerator (){
    float random_value;
    srand(time(NULL));
    random_value = 0.5 + (float)rand()/RAND_MAX*4.5;
    //printf("%f\n",random_value);
    random_value = floorf(random_value*100)/100;
    //printf("%f\n",random_value);
    return random_value;
}

double inflate(double num){
	double divisor = (double)rand()/RAND_MAX + 100;
	double div = num / divisor;
	num += div;
	return num;
}

int newMeeseeksText( int difficulty )
{
	// hay que traer la dificultad en double para poder hacer el inflate
	// puede ser que tambien los fd (pipes) tengan que ser doubles?
    int children = 3;
    int diff = difficulty; 														//Nivel de dificultad, tiene que ser la variable que cambia y se pasa por pipes
    float time = timeGenerator();												//Tiempo entre 0.5 y 5 segundos que va a durar la simulacion
    int isParent = 0;
    int parentPipe[2];															//padre lee en parentPipe[0] y escribe en childPipe[1]
    int childPipe[2];
    int fd[2];															//hijo lee en childPipe[0] y escribe en parentPipe[1]
    fd[0] = diff;
    pid_t pids[children];                                                       //Crea un array de pid_t del tamaño indicado
    //int parent;
    for(int i = 0; i < children; i++){                                          //Itera hasta completar con la cantidad de hijos requerida
    	if (pipe(fd) == -1){
    		printf("Error: Unable to open pipe\n");
    		return 1;
    	}
        pids[i] = fork();
        if( pids[i] < 0) perror("Fork failed");                                  //Caso que dé negativo y por lo tanto error
        else if (pids[i] == 0){                                                 //Caso cuando se crea un hijo
        	//isParent = 1;
            printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d)\n", getpid(), getppid());
            //recibe el nivel de dificultad
            //int gain = inflate(diff); 											//valor del porcentaje de dificultad aumentado
            //write(fd[1],&gain,sizeof(int)); 									//tal vez el size tenga que ser del double?
            //close(fd[1]);														//se cierra
            exit(0);                                                            //Se sale de la iteración actual del for para crear únuicamente un hijo
        }
        //else{
        	//int dificultadChild;
        	//read(fd[0], dificultadChild, sizeof(int));
        	//close(fd[0]);
        	//aca se obtiene el numero dado del child
        //}//
    }
    //waitpid(parent,NULL,0);

    return 0;
}