#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int newMeeseeksText(){
	int cant = 3;
	while (cant > 0){
		pid_t pid;
		pid = fork();
		if (pid < 0){
			fprintf (stderr,"Meeseeks creation failed");
		}
		else if (pid == 0){
			printf("Hi I'm Mr. Meeseeks! Look at Meeee. (%d,%d)\n", getpid(), getppid());
			exit(0);
		}
		cant = cant - 1;
	}
	return 0;
}
