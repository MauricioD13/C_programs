#include <stdlib.h>
#include <stdio.h>
#include "perrin.h"

int *perrin_series(int number){
    int *perrin_array=malloc(number*sizeof(int));
    *perrin_array=3;
    *(perrin_array+1)=0;
    *(perrin_array+2)=2;
    for(int i=3;i<number;i++){
        *(perrin_array+i)=*(perrin_array+i-2)+*(perrin_array+i-3);
    }
    for(int j=0;j<number;j++){
        printf("Numeros: %d \n",*(perrin_array+j));
    }
    return perrin_array;
}

int **perrin_primes(int *perrin_array,int number,int *cont){
    int **perrin_pointers=malloc(number*sizeof(int*));
    for(int i=1;i<number;i++){
        if(!(*(perrin_array+i)%i)){
            *(perrin_pointers+*cont)=perrin_array+i;
            printf("perrin_array address: %p, perrin_pointers content: %p,  perrin_array content: %d \n",perrin_array+i,*(perrin_pointers+*cont),*(perrin_array+i));
            *cont+=1;
        }
    }
    for(int j=0;j<number;j++){
        if(j>=*cont){
            *(perrin_pointers+j)=NULL;
        }
    }
    return perrin_pointers;
}

void deleter(int **perrin_pointers,int number,int *cont){
    for(int i=0;i<number;i++){
        if(*(perrin_pointers+i)==NULL){
            free(*(perrin_pointers+i));
        }
    }
    for(int j=0;j<*cont;j++){
        printf("Prime numbers: %d \n",**(perrin_pointers+j));
    }
}
