#include <stdio.h>
#include <stdlib.h>
void sort(int **pointers,int *quantity){
    int *aux=NULL;
    printf("%d",*quantity);
    for(int i=0;i<(*quantity)-1;i++){
        for(int j=0;j<(*quantity-1);j++){
            if(*(*pointers+j)>*(*pointers+j+1)){
                aux=(*pointers+j);
                *(pointers+j)=*(pointers+j+1);
                *(pointers+j+1)=aux;
            }
        }
    }
}
void generate(int *quantity,int **pointers){
    printf("%d",rand());
}

int main(){
    int *quantity;
    *quantity=5;
    int *vector=(int *)calloc(*quantity,sizeof(int));
    generate(quantity,vector);
    int *pointers[5];
    for(int i=0;i<5;i++){
        pointers[i]=&vector[i];
    }
    sort(pointers,quantity);
    
    for(int i=0;i<5;i++){
        printf("apuntador %p al vector de la posicion %d tiene el valor %d \n",pointers[i],i,*pointers[i]);
    }
}
