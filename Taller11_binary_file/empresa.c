#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct EMPLEADO
{
    int codigo;
    char apellido[20];
    char nombre[20];
    int celular;
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

void print_empleado(EMPLEADO *empleados,int indices[5]){
    for(int j=0;j<5;j++){
        printf("indices:%d\n",indices[j]);
        printf("codigo:%d\n",(empleados+(indices[j]))->codigo);
        //printf("longitud cod:%d\n",strlen((empleados+j)->codigo));
        printf("apellido:%s\n",(empleados+(indices[j]))->apellido);
        printf("nombre: %s\n",(empleados+(indices[j]))->nombre);
        printf("celular:%d\n",(empleados+(indices[j]))->celular);
        printf("-----------------------\n");
    }
}

void escribirTexto(EMPLEADO *empleados,int indices[5]){
    FILE *archivo_texto;
    archivo_texto = fopen("datos.txt","w");
    char *result=malloc(sizeof(EMPLEADO));
    char *temp=malloc(sizeof(EMPLEADO));
    for(int k=0;k<5;k++){
        snprintf(result,10,"%d",(empleados+indices[k])->codigo);
        strcat(result,",");
        strcat(result,(empleados+indices[k])->apellido);
        strcat(result,",");
        strcat(result,(empleados+indices[k])->nombre);
        snprintf(temp,10,"%d",(empleados+indices[k])->celular);
        strcat(result,",");
        strcat(result,temp);
        strcat(result,"\n");
        fputs(result,archivo_texto);
    }
    fclose(archivo_texto);
}
int menu(int option){
    printf("Menu\n");
    printf("[1] Imprimir empleados\n");
    printf("[2] Agregar empleado\n"); // No funciono
    printf("[3] Salir\n");
    scanf("%d",&option);
    return option;
}
int main(){

    FILE *datos_binarios;
    FILE *indice_binarios;

    int option=0;
    option=menu(option);
    
    int indices[5];
    int *datos1=malloc(sizeof(int));
    
    char *datos2=malloc(20*sizeof(char*));
    
    
    datos_binarios = fopen("datos.bin","rb");
    indice_binarios = fopen("indice.bin","rb");

    int position;
    fseek(datos_binarios,0,SEEK_END);
    int x=ftell(datos_binarios);
    fseek(datos_binarios,0,SEEK_SET);
    
    EMPLEADO *empleados=malloc(5*sizeof(EMPLEADO));
    int i=0;
    while(position<x){
        EMPLEADO empleado;
        fread(datos1,sizeof(int),1,datos_binarios);
        empleado.codigo=*datos1;
        fread(datos2,sizeof(char),21,datos_binarios);
        strcpy(empleado.apellido,datos2);
        fread(datos2,sizeof(char),21,datos_binarios);
        strcpy(empleado.nombre,datos2);
        fread(datos1,sizeof(int),1,datos_binarios);
        empleado.celular=*datos1;
        
        position=ftell(datos_binarios);  
        *(empleados+i)=empleado;
        i++;
    }

    fseek(indice_binarios,0,SEEK_END);
    x=ftell(indice_binarios);
    
    fseek(indice_binarios,0,SEEK_SET);
    i=0;
    position=0;
    while(position<x){
        fread(datos1,sizeof(int),1,indice_binarios);
        indices[i]=*datos1;
        position=ftell(indice_binarios);
        i++;
    }
   
    while(option!=3){
        if(option==1){
            print_empleado(empleados,indices);
        }
        else if(option==2){
            printf("-----------------------\n");
            printf("||                    ||\n");
            printf("||     No funciono :( ||\n");
            printf("||                    ||\n");
            printf("-----------------------\n");
        }
        option=menu(option);
    }
    escribirTexto(empleados,indices);

    fclose(datos_binarios);
    fclose(indice_binarios);

}