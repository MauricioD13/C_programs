#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(char ***matrix){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%s \t\t",*(*(matrix+j)+i));       
        }
        printf("\n");
    }
}

void generate_matrix(char ***matrix){
    for(int i=0;i<5;i++){
        char **row=malloc(5*sizeof(char*));
        for(int i=0;i<5;i++){
                *(row+i)=0;
        }
        *(matrix+i)=row;

    }
}
int detect_type(char* cell){
    char *result=malloc(sizeof(cell));
    result=strtok(cell,"=");
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
                *(values)=i; //Columna
                *(values+1)=j;//Fila
                return 1;
            }
        }
    }
}
int searching_complete(char ***matrix,char *cell){
    int option;
    char *copy=malloc(sizeof(cell));
    char *token;
    option=detect_type(cell);
    if(option==1){
        printf("Es un numero\n");
    }
    else{
        //Es una ecuacion
        int quantity=terms_quantity(cell);
        int *values=malloc(2*sizeof(int));
        int *results=malloc(quantity*sizeof(int));
        
        //printf("Cantidad de terminos: %d\n",quantity);
        strcpy(copy,cell);
        token=strtok(copy,"=");
        char* complete=malloc(sizeof(token));
        token=strtok(token," ");
        char* chunk=malloc(sizeof(token));
        //printf("TOKEN:%s|\n",token);
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
            int number;
            int convert=atoi(*(terms+i));
            if(!convert){
                search(*(terms+i),values);
                printf("El valor de %s es: columna %d fila %d\n",*(terms+i),*values,*(values+1));
                number=search_in_matrix(*values,*(values+1),matrix);
            }
            else{
                *(results+i)=convert;
            }
        }
    }
}

int search_in_matrix(int columns,int row,char ***matrix){
    

}


/*  1. Crear matriz $
    2. Introduccior valores en la matriz  $
    3. Distinguir celda con numeros o con ecuaciones -> Comparacion de strings despues de strtok $
    4. Si es una ecuacion saber cuantos valores tiene $
    5. Separa cada valor para saber a que celda esta haciendo referencia 
    6. Distinguir si lo valores en la celda referenciada son un ecuación o un entero
    7. Hacer la operacion
*/
int main(){
    //char dicc[]={"A","B","C"};
    char entry[200];
    
    char *p;
    char *q;
    char *z;
    char *y;
    char *rest;
    char *copy;
    
    char ***matrix=malloc(5*sizeof(entry));
    //*(*(matrix+columna)+fila)
    generate_matrix(matrix);
    **matrix="10";
    *(*(matrix+1))="34";
    *(*(matrix+1)+1)="17";
    *(*(matrix+2)+0)="37";
    *(*(matrix+0)+1)="40";
    *(*(matrix+2)+1)="34";
    *(*(matrix+0)+2)="=A1 + A2";
    *(*(matrix+1)+2)="=B1 + B2";
    *(*(matrix+2)+2)="=C1 + 8 + C2";
    *(*(matrix+3)+0)="=A1 + B1 + C1";
    *(*(matrix+3)+1)="=A2 + B2 + C2";
    print_matrix(matrix);
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(*(*(matrix+j)+i)!=NULL){
                searching_complete(matrix,*(*(matrix+j)+i));
            }
        }
    } 
}