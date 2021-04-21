#include "tinyexpr.c"
#include <math.h>

void mathHandler(){
    char expression[60];
    printf("-------------------------------------\n");
    printf("Please input the mathematical expression \n> ");
    scanf("%s", expression);
    double result = te_interp(expression,0);
    if (isnan(result)){
    	printf("No es numero\n");
    }
    else{
    	printf("Result: %f\n", result);
	}    
    //return 0;
    printf("-------------------------------------\n");
}