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
    *(*matrix+1)="40";
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
    strcpy(copy,*(*(matrix+0)+2));
    p=strtok(copy,"=");
    p=strtok(p,"+");
    printf("p: %s \n",p);
    q=strtok(NULL,"+");
    printf("q: %s \n",q);
    z=strtok_r(q," ",&rest);
    printf("z: %s \n",z);
    printf("rest: %s\n",rest);
    y=strtok(z,"2");
    
    char *compare="A,B,C";
    
    //Hacer especie de diccionario para las equivalencias con la columna, strcmp funciono
    
    //char *compare2=strtok(*compare,",");
    //printf("y: %s compare:%s \n",y,compare2);
    if(!(strcmp(y,compare))){
        printf("SON IGUALES\n");
    }else{
        printf(":(\n");
    }
    


    
}