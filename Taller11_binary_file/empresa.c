#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct EMPLEADO
{
    char *codigo;
    char *apellido;
    char *nombre;
    char *celular;
}EMPLEADO;


int tokenized_lines(char *datos,char **lineas){

    char *token=malloc(sizeof(datos));
    char *copy=malloc(sizeof(datos));
    char *temp;
    
    strcpy(copy,datos);
    
    token=strtok(copy,"\n");
    
    
    int i=0;
    while(token!=NULL){
        
        *(lineas+i)=token;
        token=strtok(NULL,"\n");
        if(i>10){
            break;
        }
        i++;
    }
    
    return i;
}
void tokenized_datos(char *linea){
    printf("Aqui voy\n");
    char *token=malloc(sizeof(linea));
    char *copy=malloc(sizeof(linea));
    
    EMPLEADO *empleado=malloc(sizeof(EMPLEADO));
    strcpy(copy,linea);
    
    char *codigo=malloc(sizeof(linea));
    char *apellido=malloc(sizeof(linea));
    char *nombre=malloc(sizeof(linea));
    char *celular=malloc(sizeof(linea));
    
    codigo=strtok(copy,",");
    empleado->codigo=codigo;
    apellido=strtok(NULL,",");
    empleado->apellido=apellido;
    nombre=strtok(NULL,",");
    empleado->nombre=nombre;
    celular=strtok(NULL,",");
    empleado->celular=celular;
    printf("Voy saliendo\n");

}




int main(){
    FILE *datos_binarios;
    FILE *indice_binarios;

    char *datos=malloc(100*sizeof(char*));
    char *indices=malloc(100*sizeof(char*));
    
    datos_binarios = fopen("datos.bin","rb");
    indice_binarios = fopen("indice.bin","rb");
    
    fread(datos,sizeof(char),200,datos_binarios);
    fread(indices,sizeof(char),100,indice_binarios);
    char **lineas=malloc(100*sizeof(datos));
    printf("%s\n",datos);
    printf("%s\n",indices);
    int cont_lineas=0;
    cont_lineas=tokenized_lines(datos,lineas);

    for(int i = 0; i<cont_lineas; i++){
        printf("lineas:%s\n",*(lineas+i));
    }

    tokenized_datos(*(lineas+1));

    fclose(datos_binarios);
    fclose(indice_binarios);

}