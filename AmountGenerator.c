#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double *getRandom(){
    srand(time(NULL));
    //double num = (double) (rand() % (100 - 0 + 1)) + 0;   //Genera un int entre 0 a 100
    double num = (double)rand()/RAND_MAX*100.0-1.0;         //Genera un double entre 0 a 100
    double divisor = (double)rand()/RAND_MAX + 12;          //Genera un double entre 12 y 13
    double div = num / divisor;                             //Valor que entra a la función exp()
    int val = round(exp(div));                              //Redondeo del valor para conseguir un int de cantidad de procesos
    printf("%f \n", num);
    printf("%f \n", divisor);
    printf("%f \n", div);
    printf("%d \n", val);
    double arr[2] = {num, val};
    printf("Random number: %f \n", arr[0]);
    printf("Amount: %f \n", arr[1]);
    return arr;
}

/*
void test(){
    for(int i = 0; i<100; i++){
        srand ( time ( NULL));
        //double x = 12.5;
        double x = (double)rand()/RAND_MAX + 12;//float in range -1 to 1
        double div = i / x;
        int val = round(exp(div));
        printf("Random number: %d \n", i);
        printf("%f \n", x);
        printf("%d \n\n", val);
    }
}
*/

int main()
{
    double *arr = getRandom();
    printf("Random number: %f \n", arr[0]);
    printf("Amount: %f \n", arr[1]);

    return 0;

}
