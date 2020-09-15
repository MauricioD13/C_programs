#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  Autor: Mauricio David Cuello Alzate
    Carrera: Ingenieria Electronica
    Compilador: gcc 
    Repositorio: https://minerva.javeriana.edu.co/mdavid_cuello/c_programs.git */

    
void print_matrix(char ***matrix){//Imprime la matriz
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%s \t\t",*(*(matrix+j)+i));       
        }
        printf("\n");
    }
}
void generate_matrix(char ***matrix){//Genera la matriz de cadenas de caracteres
    for(int i=0;i<4;i++){
        char **row=malloc(4*sizeof(char*));
        for(int j=0;j<4;j++){
                *(row+j)=0;
        }
        *(matrix+i)=row;

    }
}
int detect_type(char* cell){//Detecta que tipo de dato esta en la celda, numero o 
    char *result=malloc(sizeof(cell));
    result=strtok(cell,"=");
    if(!(strcmp(cell,result))){
        return 1; //Numero
    }else
    {
        return 2; //Ecuacion
    }
}
int terms_quantity(char* cell){//Cantidad de terminos de la formula o ecuacion
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

int search(char *cell,int *values){//Toma el termino ingresado y busca la celda a la que se refiere
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
/*Si la funcion detect_type devuelve 1 es un numero sino es formula
Si es una formula se busca la cantidad de terminos que tiene la formula
Luego se separan (tokenizado) los terminos 
Se evalua cada termino haciendo conversion a entero, si es un numero diferente de 0 es un entero
Si es un termino que se refiere a otro entonces se entra a la funcion search
Se van sumando los terminos que se tienen*/
    int option;
    char *copy=malloc(sizeof(cell));
    char *token;
    option=detect_type(cell);
    if(option==1){
        //printf("Es un numero\n");
        return 0;
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
        int total=0;
        *(terms)=token;
        while(token!=NULL){
            token=strtok(NULL,"+");
            if(token!=NULL){
                *(terms+cont)=token+1;
                cont++;  
            }
        }
        for(int i=0;i<quantity;i++){
            char *number;
            int convert=atoi(*(terms+i));
            
            if(!convert){
                search(*(terms+i),values);
                number=*(*(matrix+(*values))+(*(values+1)));
                *(results+i)=atoi(number);
                total=*(results+i)+total;
            }
            else{
                *(results+i)=convert;
                total=*(results+i)+total;
            }
            
        }
        return total;
        
    }
}

void strcpy_matrix(char ***matrix_from,char ***matrix_to){//Funcion para copiar matriz de cadenas de caracteres
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            *(*(matrix_to+j)+i)=*(*(matrix_from+j)+i);
        }
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
    char entry[100];
        
    char ***matrix=malloc(4*sizeof(entry));
    char ***total_matrix=malloc(4*sizeof(entry));
    //*(*(matrix+columna)+fila)
    generate_matrix(matrix);
    generate_matrix(total_matrix);
    **matrix="10";
    *(*(matrix+1)+0)="34";
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
    strcpy_matrix(matrix,total_matrix);
    
    int total=0;
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(*(*(matrix+j)+i)!=NULL){
                total=searching_complete(matrix,*(*(matrix+j)+i));
                
                if(total!=0){
                    char *value_matrix=malloc(sizeof(entry));
                    snprintf(value_matrix,10,"%d",total);
                    
                    *(*(total_matrix+j)+i)=value_matrix;
                    
                }
            }
            
        }
        
    } 
    printf("-------RESULT------------\n");
    print_matrix(total_matrix);
}