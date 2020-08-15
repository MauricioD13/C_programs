#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    int **pointers=(int**)malloc(5*sizeof(int));
    int *integers=(int*)malloc(5*sizeof(int));
    int cont=1;
    while(cont<3){
        *(integers+cont)=rand();
        *(pointers+cont)=(integers+cont);
        printf("Apuntador*: %p, Apuntador**: %d, integers %d\n",*pointers,**(pointers+cont),*(integers+cont));
        cont++;  
    }
    
    
    
    
    
    
    /*
    *(integers+1)=rand();
    *(pointers+1)=(integers+1);
    *(integers+2)=rand();
    *(pointers+2)=(integers+2);
    printf("Apuntador*: %p, Apuntador**: %d, integers %d\n",*pointers,**(pointers+1),*(integers+1));
    printf("Apuntador*: %p, Apuntador**: %d, integers %d\n",*pointers,**(pointers+2),*(integers+2));*/
}