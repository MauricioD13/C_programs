#include <stdio.h>
#include <stdlib.h>

void generate(int *vector,int *quantity){
    for(int cont=0;cont<*quantity;cont++){
        *(vector+cont)=rand()%10;        
    }

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
        printf("days numbers: %d\n",*(days+i));
        if(number<*(days+i)){
            number=*(days+i);
        }
    }
    while(0<number){
        for(int k=0;k<days_quantity;k++){
            if(*(days+k)==number){
                printf("*");
                *(days+k)=*(days+k)-1;
            }
            else{
                printf("\t");
            }
        }
        printf("\n");
        number--;
    }
}