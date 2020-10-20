#include <stdio.h>
#include <stdlib.h>
#include "perrin.h"
//Autor: Mauricio David Cuello Alzate
//Carrera: Ingenieria Electronica
//Compilado en VS y con gcc en cmd
int main(){
    
    int number=0;
    int option=0;
    int **perrin_pointers;
    int *perrin_array;
    int cont=0;
    
    int enter=1;
    while(enter){
        option=0;
        printf("Que desea hacer? \n(1) Imprimir numero de la serie de perrin \n(2) Imprimir numero primos de los numero que saco anteriormente \n");
        printf("(3) Comprobar la funcion deleter \n(4) Hacer todo en secuencia\n(5) Salida \n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            printf("Cantidad de numeros?");
            scanf("%d",&number);
            perrin_array=perrin_series(number);
            break;
        case 2:
            perrin_pointers=perrin_primes(perrin_array,number,&cont);
            break;
        case 3:
            deleter(perrin_pointers,number,&cont);
            break;
        case 4:
            if(number){
                free(perrin_pointers);
                free(perrin_array);
            }
            cont=0;
            printf("Cantidad de numeros?");
            scanf("%d",&number);
            perrin_array=perrin_series(number);
            perrin_pointers=perrin_primes(perrin_array,number,&cont);
            deleter(perrin_pointers,number,&cont);
            break;
        case 5:
            printf("Adios");
            enter=0;
            break;
        default:
            printf("Hiciste algo mal :(  volvamos a comenzar ;) \n");
            option=0;
            break;
        }
    }
    free(perrin_pointers);
    free(perrin_array);
}