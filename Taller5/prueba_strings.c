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

int search(char *cell,int *values){
    char *alfa="A\0B\0C\0";
    char *result=malloc(sizeof(cell));
    char *token=malloc(sizeof(char));
    char *copy=malloc(sizeof(char));
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            snprintf(result,10,"%d",j+1);
            strcpy(copy,cell);
            token=strtok(copy,result);
            if(!(strcmp(alfa+(i*2),token))){
                *(values)=i;
                *(values)=j;
                return 1;
            }
        }
    }
}
int main(){
    char *y="=A1 + C2 + B3";
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
        int *values=malloc(2*sizeof(int));
        
        printf("Cantidad de terminos: %d\n",quantity);
        strcpy(copy,y);
        token=strtok(copy,"=");
        char* complete=malloc(sizeof(token));
        token=strtok(token," ");
        char* chunk=malloc(sizeof(token));
        printf("TOKEN:%s|\n",token);
        char **terms=malloc(quantity*sizeof(token));
        int cont=1;
        *(terms)=token;
        while(token!=NULL){
            token=strtok(NULL,"+");
            if(token!=NULL){
                *(terms+cont)=token+1;
                cont++;  
            }
        }
        for(int i=0;i<quantity;i++){
            printf("terms:%s|\n",*(terms+i));
            search(*(terms+i),values);
        }
    }
    

}