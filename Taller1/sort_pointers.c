#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int **pointers,int *quantity){
    int *aux=NULL;
    int i=1,j=1;
    while(j<*quantity-1){
        while(i<*quantity-1){
            if(**(pointers+i)>**(pointers+i+1)){
                aux=*(pointers+i);
                *(pointers+i)=*(pointers+i+1);
                *(pointers+i+1)=aux;
            }
            i++;
        }
        i=1;
        j++;
    }

}
void generate(int *vector,int *quantity,int **pointers){
    int cont;
    printf("--------GENERATE--------\n");
    for(cont=1;cont<*quantity;cont++){
        *(pointers+cont)=vector+cont; 
        *(vector+cont)=rand()%100;        
    }

}

int main(){
    srand(time(NULL));
    int quantity;
    printf("Introduzca una cantidad ");
    scanf("%d",&quantity);
    int **pointers=(int**)malloc(quantity*sizeof(long));
    int *vector=(int *)malloc(quantity*sizeof(long));
    if(vector==NULL||pointers==NULL){
        printf("Hubo un problema con la asignacion de memoria");
    }
    printf("vector inicial: %5p, pointers inicial: %5p  \n",vector,pointers);
    generate(vector,&quantity,pointers);
    printf("------BEFORE SORT-------\n");
    int j=1;
    while(j<quantity){
        printf("j= %d, Apuntador *pointer+j: %5p ,contenido *pointers+j %d \n",j,*(pointers+j),**(pointers+j));
        j++;
    }
    sort(pointers,&quantity);
    printf("----------RESULTADOS---------\n");
    for(int j=1;j<quantity;j++){
        printf("j= %d, Apuntador *pointer+j: %5p ,contenido *pointers+j %d \n",j,*(pointers+j),**(pointers+j));
    }
}
