#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cubetas_lib.h"

void sort(int **columns,int *numbers,int number,int N){ //Funcion para ordenar los numero en la matriz de la manera correspondiente
    int row=11;
    int cont=0;
    printf("Digito numero:%d\n",number+1);
    if(number==0){
        for(int j=0;j<N;j++){
            row=*(numbers+j)%10;
            while(1){
                if(*(*(columns+row)+cont)==0){
                *(*(columns+row)+cont)=*(numbers+j);
                break;
                }
                else{
                    cont++;
                }
            }
            cont=0;
        }  
    }
    else{
        for(int j=0;j<N;j++){
            int x;
            if(number==1){
                x=(int)pow(100,number);
            }
            else{
                x=(int)pow(10,number+1);
            }
            row=floor((*(numbers+j)%x)/pow(10,number));
            while(1){
                if(*(*(columns+row)+cont)==0){
                *(*(columns+row)+cont)=*(numbers+j);
                break;
                }
                else{
                    cont++;
                }
            }
            cont=0;
        }
    }
}

void print_matrix(int **matrix,int N){ //Funcion para imprimir la matriz
    for(int i=0;i<10;i++){
        printf("FILA %d: \t",i);
        for(int j=0;j<N;j++){
            printf("%d \t",*(*(matrix+i)+j));
        }
        printf("\n");
    }
}

void generate_matrix(int N, int **columns){ //Funcion que genera la matriz con apuntadores
    for(int j=0;j<10;j++){
            int *rows=malloc(N* sizeof(int));
            for(int i=0;i<N;i++){
                *(rows+i)=0;
            }
            *(columns+j)=rows;
    }
}

void organized(int *numbers,int N,int **matrix){ //Funcion que reorganiza el vector de numeros
    int cont=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<N;j++){
            if((*(*(matrix+i)+j))!=0){
                *(numbers+cont)=*(*(matrix+i)+j);
                cont++;
            }
        }

    }
}

void generate(int *vector,int N,int quantity){
    for(int cont=0;cont<N;cont++){
        *(vector+cont)=rand()%((int)pow(10,quantity))==0?1:rand()%((int)pow(10,quantity));        
        printf("generate: %d",*(vector+cont));
    }

}