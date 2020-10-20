#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cubetas_lib.h"
//Autor: Mauricio David Cuello Alzate
//Carrera: Ingenieria electronica
//Repositorio: https://minerva.javeriana.edu.co/mdavid_cuello/c_programs
//Compilador: gcc en Visual o en terminal, gcc de MinGW
int main(){
    const int N=6;
    int quantity; //Cantidad de cifras
    printf("Cantidad de digitos que desea evaluar?: ");
    scanf("%1d",&quantity); //Maximo un digito por lo que si se ingresan mas digitos solo tomara el primero
    int *numbers=malloc(N*sizeof(int));
    generate(numbers,N,quantity);
    
    for(int i=0;i<quantity;i++){
        int **columns=malloc(10 *sizeof(int*));
        generate_matrix(N,columns);
        sort(columns,numbers,i,N);
        print_matrix(columns,N);
        organized(numbers,N,columns);
        printf("-----------------------------------------\n");
    }

}