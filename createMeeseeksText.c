#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <string.h>
#include <sys/wait.h>

float timeGenerator (){
    float random_value;
    srand(time(NULL));
    random_value = 0.5 + (float)rand()/RAND_MAX*4.5;
    random_value = floorf(random_value*100)/100;
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
	/*
	printf("Entra\n");
    int p1[2]; // C => P (read from child, child writes)
    int p2[2]; // P => C (read from parent, parent writes)
    
    if (pipe(p1) == -1) {
        return 1;
    }
    if (pipe(p2) == -1) {
        return 2;
    }
    pid_t pid;
    pid = fork();
    pid = fork();
    if (pid == -1) {
        return 3;
    }
    
    if (pid == 0) {
        // Child process
        close(p1[0]); //No necesitamos leer aca
        close(p2[1]); //No necesitamos escrbir aca
        printf("Soy child #%d de %d\n",getpid(),getppid());
        int x;
        if (read(p2[0], &x, sizeof(int)) == -1) {
            return 3;
        }
        printf("Received %d\n", x);
        
        x *= 4;
        
        if (write(p1[1], &x, sizeof(int)) == -1) {
            return 4;
        }
        printf("Wrote %d\n", x);
        close(p1[1]);
        close(p2[0]);
    } else {
        // Parent process
        close(p1[1]); //No necesitamos escribir aca
        close(p2[0]); //No necesitamos leer aca
        
        srand(time(NULL));
        int y = rand() % 10;
        
        
        if (write(p2[1], &y, sizeof(y)) == -1) {
            return 5;
        }
        printf("Wrote %d\n", y);
        if (read(p1[0], &y, sizeof(y)) == -1) {
            return 6;
        }
        printf("Result is %d\n", y);
        
        close(p1[0]);
        close(p2[1]);
        wait(NULL);
    }
    
    return 0;*/
	
	int children = 2;
    double diff = (double)difficulty; 											//Nivel de dificultad, tiene que ser la variable que cambia y se pasa por pipes    
    float simulationTime = timeGenerator();												//Tiempo entre 0.5 y 5 segundos que va a durar la simulacion
    int isParent = 0;
    pid_t pids[children];                                                       //Crea un array de pid_t del tamaño indicado
	double p1[2]; // C => P (read from child, child writes)
	double p2[2]; // P => C (read from parent, parent writes)
	
	/*int candadoWriter;
	int candadoReader;
	sem_t *sem_writer = sem_open(candadoWriter,IPC_CREAT,0660,0);
	if (sem_writer == SEM_FAILED){
		perror("Fallo el sem_writer");
		exit(0);
	}
	sem_t *sem_reader = sem_open(candadoReader,IPC_CREAT,0660,0);
	if (sem_reader == SEM_FAILED){
		perror("Fallo el sem_reader");
		exit(0);
	}*/
	if (pipe(p1) == -1) {
    	printf("fallo el pipe 1\n");
        return 1;
    }
    if (pipe(p2) == -1) {
    	printf("fallo el pipe 2\n");
        return 2;
    }
    sleep(simulationTime);
    for(int i = 0; i < children; i++){                                          //Itera hasta completar con la cantidad de hijos requerida      
        pids[i] = fork();
        if( pids[i] < 0){
        	perror("Fork failed");                                 				 //Caso que dé negativo y por lo tanto error
        } 
        else if (pids[i] == 0){                                                 //Caso cuando se crea un hijo
        	//close(p1[0]); 														//No necesitamos leer aca
        	//close(p2[1]); 														//No necesitamos escrbir aca
            printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d)\n", getpid(), getppid());
            double newDiff;
            //wait(getppid());
            //sem_wait(sem_writer);
            if (read(p2[0], &newDiff, sizeof(newDiff)) == -1) {
	            return 3;
	        }
	        //sem_close(sem_reader);
	        printf("Recibe la dificultad en %f\n", newDiff);  
            newDiff = inflate(diff);											//Nuevo nivel de dificultad
            //sem_wait(sem_reader);
            if (write(p1[1], &newDiff, sizeof(newDiff)) == -1) {
	           return 4;
	        }
	        //sem_post(sem_reader);
	        printf("Nueva dificultad es %f\n",newDiff);

	        //close(p1[1]);
	        //lose(p2[0]);
	        //sleep(10);
	        //sem_close(sem_reader);
	        exit(0);
	    }
        else{
        	//close(p1[1]); //No necesitamos escribir aca
	        //close(p2[0]); //No necesitamos leer aca
	        //sem_wait(sem_reader);
        	if (write(p2[1], &diff, sizeof(diff) + 1) == -1) {
	            return 5;
	        }
	        //sem_post(sem_reader);
	        printf("Escribe la dificultad en %f\n", diff);
	        //sem_wait(sem_writer); 
        	if (read(p1[0], &diff, sizeof(diff) + 1) == -1) {
	            return 6;
	        }
	        printf("La dificultad es %f\n", diff);
	        //sem_close(sem_reader);
	        	        
	        //close(p1[0]);
	        //close(p2[1]);
	        wait(NULL);     
        }
    }
    return 0;
}