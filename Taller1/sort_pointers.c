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
    printf("--------GENERATE-------- \n",*quantity);
    for(int cont=1;cont<*quantity;cont++){
        *(pointers+cont)=(vector+cont); 
        *(vector+cont)=rand()%100;        
    }

}

int main(){

    srand(time(NULL));
    int quantity;
    printf("Introduzca una cantidad ");
    scanf("%d",&quantity);
    //Asignacion de memoria dinamica
    int **pointers=(int**)malloc(quantity*sizeof(int*));
    int *vector=(int *)malloc(quantity*sizeof(int));
    
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
