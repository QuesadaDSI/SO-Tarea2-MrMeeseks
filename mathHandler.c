#include "tinyexpr.c"

void mathHandler(){
    char expression[60];
    printf("Please input the mathematical expression \n> ");
    scanf("%s", &expression);
    printf("Result: %f\n", te_interp(expression, 0));
    //return 0;
}