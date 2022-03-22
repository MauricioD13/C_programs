#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *A=malloc(5*sizeof(char));
    A="A";
    char *alfa="A\0B\0C\0";
    char *y="=A1 + A2";
    char *result=malloc(sizeof(y));
    char *A1;
    char *A2;
    char *copy=malloc(sizeof(y));
    strcpy(copy,y);
    
    result=strtok(copy,"=");
    printf("result: %s\n",result);
    A1=strtok(result,"+");
    printf("result: %s\n",A1); // La funcion strtok devuelve la parte hasta la que encuentra el string especificado, el resto queda en la funcion 
    A2=strtok(NULL," ");// Si no se le pasa un string y previamente se le hizo un strtok a otra cadena, entonces por defecto la funcion strtok se ejecuta en la siguiente 
                        // de la cadena rota anteriormente
    printf("result: %s\n",A2);
    

    char *result2=malloc(100*sizeof(char));
    snprintf(result2,10,"%d",2);
    if(!(strcmp(A,strtok(A2,result2)))){
        printf("Soy un DIOS\n");
    }
    printf("alfa: %s\n",alfa);
    
    

}