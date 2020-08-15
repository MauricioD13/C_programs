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
        j++;
    }
}
void generate(int *vector,int *quantity,int **pointers){
    int cont=1;
    while(cont<*quantity){
        *(vector+cont)=rand()%100;
        *(pointers+cont)=(vector+cont);
        cont++;  
    }
}

int main(){
    srand(time(NULL));
    int *quantity;
    *quantity=5;
    int **pointers=(int**)malloc(5*sizeof(int));
    int *vector=(int *)malloc(5*sizeof(int));
    generate(vector,quantity,pointers);
    for(int j=1;j<*quantity;j++){
        printf("Apuntador *pointer+j: %p ,contenido *pointers+j %d \n",*(pointers+j),**(pointers+j));
    }
    sort(pointers,quantity);
    printf("----------RESULTADOS---------\n");
    for(int j=1;j<*quantity;j++){
        printf("Apuntador *pointer+j: %p ,contenido *pointers+j %d \n",*(pointers+j),**(pointers+j));
    }

}
