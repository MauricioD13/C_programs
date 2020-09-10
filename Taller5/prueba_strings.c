#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int detect_type(char* cell){
    char *result=strtok(cell,"=");
    if(!(strcmp(cell,result))){
        return 1; //Numero
    }else
    {
        return 2; //Ecuacion
    }
}
int terms_quantity(char* cell){
    char *token=malloc(sizeof(cell));
    char *copy=malloc(sizeof(cell));
    strcpy(copy,cell);
    token=strtok(copy," ");
    int cont=0;
    while(token!=NULL){
        token=strtok(NULL,"+");
        cont++;  
        }
    return cont;
}


int main(){
    char *y="=A1 + A2 + A3 + A3 + B4";
    int option;
    char *copy=malloc(sizeof(y));
    char *token;
    option=detect_type(y);
    if(option==1){
        printf("Es un numero\n");
    }
    else{
        //Es una ecuacion
        int quantity=terms_quantity(y);
        int *values=malloc(quantity*sizeof(int));
        printf("Cantidad de terminos: %d\n",quantity);
        strcpy(copy,y);
        token=strtok(copy,"=");
        printf("token: %s\n",token);
        token=strtok(token,"+");
        char *string_values=malloc(quantity*sizeof(token));
        int cont=0;
        while(token!=NULL){
            printf("TOKEN:%s\n",token);
            *(string_values+cont)=*(token+1);
            token=strtok(NULL,"+");
            cont++;  
        }
        for(int i=0;i<quantity;i++){
            printf("string values: %s\n",(string_values));
        }
    }
    

}