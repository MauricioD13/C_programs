#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct REGISTRO {
    int ID;
    char *nombre;
    float nota;
}REGISTRO;
void llenar(REGISTRO *entrada,char *linea){
    char *token=malloc(sizeof(linea));
    token=strtok(linea,";");
    printf("TOKEN: %s\n",token);
    entrada->ID=atoi(token);
    token=strtok(NULL,";");
    entrada->nombre=token;
    token=strtok(NULL,";");
    entrada->nota=atof(token);
}

void print_registros(REGISTRO **tabla_registros,int cont){

    for(int i=0;i<cont;i++){
        printf("\n Persona: %d \n ID:%d\n Nombre: %s\n nota:%3f\n",i,(*(tabla_registros+i))->ID,(*(tabla_registros+i))->nombre,(*(tabla_registros+i))->nota);
    }
}

int main(){
    FILE *archivo;
    REGISTRO **tabla_registros=malloc(10*sizeof(REGISTRO*));
    char *linea=malloc(100*sizeof(char));
    archivo = fopen("notes.txt","r");
    printf("Archivo: %s\n",archivo);
    if(archivo==NULL){
        printf("\n Ha habido un problema con el archivo\n");
        return 1;
    }
    else{
        printf("\n El archivo ha sido abierto exitosamente \n");
    }
    int cont=0;
    while(feof(archivo)==0){
        REGISTRO *registro=malloc(sizeof(REGISTRO));
        fgets(linea,1000,archivo);
        llenar(registro,linea);
        *(tabla_registros+cont)=registro;
        cont++;
    }
    print_registros(tabla_registros,cont);
    fclose(archivo);
}