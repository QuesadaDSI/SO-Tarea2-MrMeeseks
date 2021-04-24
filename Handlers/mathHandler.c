#include "../TinyExpr/tinyexpr.c"
#include <math.h>

//Funcion para el manejo de la operacion aritmetica
void mathHandler(){
    char expression[60];
    printf("-------------------------------------\n");
    printf("Please input the mathematical expression \n> ");
    scanf("%s", expression);
    //te_interp retorna la respuesta a la expression que se le pase por parametro
    //O retorna NaN en caso de que la respuesta no sea un numero en si
    double result = te_interp(expression,0);
    //En caso de que result sea un NaN se imprime un mensaje mas "user-friendly"
    if (isnan(result)){
    	printf("No es numero\n");
    }
    else{
    	printf("Result: %f\n", result);
	}    
    printf("-------------------------------------\n");
}