#include <stdlib.h>

void execHandler(){
    char fileName[60];
    printf("Please input the program file name\n> ");
    scanf("%s", &fileName);
    char handle[3] = "./";
    strncat(handle,fileName,60);
    printf("%s\n",handle);
    int status = system(handle);
    if (status == -1){
    	printf("Program not executed! Existence is pain\n");
    }
    else{
    	printf("Program executed! Look at meeeeee\n");
    }
}