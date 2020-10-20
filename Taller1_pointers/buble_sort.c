#include <stdio.h>

int main(){
    int aux;
    int vector[5]={8,2,6,3,1};
    int flag=1;
    while(flag>=1){
        for(int i=4;i>0;i--){
            if(vector[i]<vector[i-1]){
                printf("comparacion entre %d y %d \n",vector[i],vector[i-1]);
                aux=vector[i];
                vector[i]=vector[i-1];
                vector[i-1]=aux;
                flag=flag+1;
            }if(flag==9){
                flag=0;
            }
        }
    }
    for(int i=0;i<5;i++){
      printf("vector en la posicion %d tiene el valor %d \n",i,vector[i]);
    }
}
