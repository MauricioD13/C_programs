#include <stdio.h>

int main(){
    int aux;
    int vector[5]={6,2,8,3,1};
    int resultado[5];
    int max=vector[0];
    for(int i=1;i<5;i++){
        if(max<vector[i]){
            max=vector[i];
        }
    }
    printf("maximo %d \n",max);
    for(int i=0;i<5;i++){
        printf("%d \n",vector[i]);
    }
}
