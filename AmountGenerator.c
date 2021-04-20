#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Results {
   int number;
   int n;
};

struct Results generateAll(){
    struct Results Ans;
    srand(time(NULL));
    //double num = (double) (rand() % (100 - 0 + 1)) + 0;   //Genera un int entre 0 a 100
    double num = (double)rand()/RAND_MAX*100.0;             //Genera un double entre 0 a 100
    if (num > 0 && num <= 45 ){
        Ans.n = 3;
    }
    else if (num > 45 && num >= 85){
        Ans.n = 1;
    }
    else{
        Ans.n = 0;
    }
    Ans.number = round(num);
    return Ans;
}

struct Results generateProcesses(int num){
    struct Results Ans;
    if (num > 0 && num <= 45 ){
        Ans.n = 3;
    }
    else if (num > 45 && num >= 85){
        Ans.n = 1;
    }
    else{
        Ans.n = 0;
    } 
    Ans.number = num;
    return Ans;
}