#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_CHILDREN 508

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

void rickSanchez(int pid){
	printf("I've been trying to help (the user) for two days, an eternity in Meeseeks time, and nothing's worked\n");
}

int newMeeseeksText( int difficulty, int meeseeksI )
{
	int childrenCounter = 0;
    double diff = (double)difficulty; 											//Nivel de dificultad, tiene que ser la variable que cambia y se pasa por pipes    
    int meeseeksIText = meeseeksI;
    float simulationTime = timeGenerator();										//Tiempo entre 0.5 y 5 segundos que va a durar la simulacion
    time_t start_time;
    time_t current_time;
    time(&start_time);
    time(&current_time);
    double timeDiff;
    printf("Simulation Time> %f\n", simulationTime);
    while (timeDiff < simulationTime){
    	pid_t pid;
	    int fd[2];
	    int fdC[2];
	    int solved = 0;
	    int parentProcess;
	    for(int num_process = 1; num_process < MAX_CHILDREN+1; num_process++){
	   		timeDiff =  difftime(current_time, start_time);
	   		time(&current_time);
	    	if (diff >= 85){														//Check if it is solved
	    		solved = 1;
	    		printf("Your request has been solved! Look at meeeeeeee!\n");
	    		return childrenCounter;
	    	}
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
	    	if (pid == 0){															//Child process															
	    		double newDiff;
	    		int i = meeseeksIText + num_process;
	    		printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d,%d,%d)\n", getpid(), getppid(),num_process,i);
	    		close(fd[1]);
	    		if (read(fd[0], &newDiff, sizeof(newDiff)) <= 0){					//Read from pipe
	    			perror("Read failed\n");
	    			exit(EXIT_FAILURE);
	    		}
	    		newDiff = inflate(newDiff);
	    		close(fdC[0]);
	    		write(fdC[1], &newDiff,sizeof(newDiff));
	    		exit(0);
	    	}
	    	else{																	//Parent process
	    		parentProcess = getpid();
	    		close(fd[0]);
	    		write(fd[1], &diff,sizeof(diff));
	    		wait(NULL);
	    		double diffFromChild;
	    		close(fdC[1]);
	    		if (read(fdC[0], &diffFromChild, sizeof(diffFromChild)) <= 0){					//Read from pipe
	    			perror("Read failed\n");
	    			exit(EXIT_FAILURE);
	    		}
	    		diff = diffFromChild;
	    	}
	    	childrenCounter = num_process;
	    }
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