#include <stdio.h>
#include <stdlib.h>
//Autor: Mauricio David Cuello Alzate
//Carrera: Ing Electronica
//Compilador: gcc en visual 
void generate(int *vector,int *quantity){
    for(int cont=0;cont<*quantity;cont++){
        *(vector+cont)=rand()%10;        
    }

}
void histogram(int days_quantity,int *days,int number){
    while(0<number){
        for(int k=0;k<days_quantity;k++){
            if(*(days+k)==number){
                printf("*");
                *(days+k)=*(days+k)-1;
                printf ("\t");
            }
            else{
                printf("\t");
            }
        }
        printf("\n");
        number--;
    }
}
void pretty(int days_quantity){
    printf("----------------------------------------------------\n");
    for(int j=0;j<days_quantity;j++){
        printf("%d \t",j);
    }
    printf("\n");
}
int main(){
    int days_quantity;
    int number=0;
    printf("Cuantos dias quiere? \n");
    //scanf("%d",&days_quantity);
    days_quantity=7;
    int *days=malloc(days_quantity*sizeof(int));
    generate(days,&days_quantity);
    for(int i=0;i<days_quantity;i++){
        printf("days numbers %d: %d\n",i,*(days+i));
        if(number<*(days+i)){
            number=*(days+i);
        }
    }
    histogram(days_quantity,days,number);
    pretty(days_quantity);
}