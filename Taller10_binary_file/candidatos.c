#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CANDIDATO{
    char *ID;
    char *nombre;
    char *ciudad;
    char *plan;
    int conteo;

}CANDIDATO;
typedef struct MUNICIPIO
{
    int numero;
    int ID;
    int votos;
    char *tipo;
}MUNICIPIO;

int escribirArchivo(){

}
int leerBinario(char **lineas){
    FILE *archivo_candidatos;
    char * nombres=malloc(100*sizeof(char*));
    archivo_candidatos=fopen("candidatos.dat","rb");

    if(archivo_candidatos==NULL) printf("Problema abriendo archivo\n");
    else printf("Archivo abierto exitosamente\n");
    
    int x=ftell(archivo_candidatos);
    printf("Inicio del archivo: %ld \n",x);

    fread(nombres,sizeof(char),110,archivo_candidatos);
    x=ftell(archivo_candidatos);

    printf("Final del archivo: %ld \n",x);
    char *copy= malloc(sizeof(nombres));

    int length;
    char *token=malloc(sizeof(nombres));
    strcpy(copy,nombres);
    token=strtok(copy,"\n");
    int i=0;
    while(token!=NULL){
        *(lineas+i)=token;
        token=strtok(NULL,"\n");
        i++;    
    }
    rewind(archivo_candidatos);

    (fclose(archivo_candidatos)!=0) ? printf("Error cerrado archivo exitosamente\n") : printf("Archivo cerrado exitosamente\n");
    
    return i;
}


int leerTexto(char * file,char **lineas_texto){
    printf("FILE:%s\n",file);
    int i=0;
    
    FILE *archivo_municipio;
    archivo_municipio= fopen(file,"r");
    if(archivo_municipio==NULL) printf("Error abriendo el archivo");
    else printf("Archivo abierto exitosamente\n");

    
    fscanf(archivo_municipio,"%s",*(lineas_texto));
    i++;
    
    
    
    printf("linea:%s\n",lineas_texto);
    printf("Segui\n");
    (fclose(archivo_municipio)!=0) ? printf("Error cerrado archivo exitosamente") : printf("Archivo cerrado exitosamente");
       
    return i;
    
}


void llenar_candidatos(char **lineas,CANDIDATO **candidatos,int cont_lineas){
    
    CANDIDATO *temp=malloc(sizeof(CANDIDATO));

    printf("Entre\n");
    for(int i=0;i<cont_lineas;i++){
        char *ID=malloc(sizeof(*(lineas)));
        
        char *nombre=malloc(10*sizeof(*(lineas)));
        char *ciudad=malloc(10*sizeof(*(lineas)));
        char *plan=malloc(10*sizeof(*(lineas)));
        char *copy=malloc(10*sizeof(*(lineas)));
        strcpy(copy,*(lineas+i));
        ID=strtok(copy,",");
        temp->ID=ID;
        nombre=strtok(NULL,",");
        temp->nombre=nombre;
        ciudad=strtok(NULL,",");
        temp->ciudad=ciudad;
        plan=strtok(NULL,",");
        temp->plan=plan;
        *(candidatos+i)=temp;
    }
   

}

void tokenized(char *linea,char **files_name){

}


int main(){


    int cont_lineas=0;
    char **lineas=malloc(110*sizeof(char*));
    
    cont_lineas = leerBinario(lineas);
    CANDIDATO **candidatos=malloc(100*sizeof(CANDIDATO*));

    for(int i=0;i<cont_lineas;i++){
        printf("Lineas: %s\n",*(lineas+i));
    }

    llenar_candidatos(lineas,candidatos,cont_lineas);
    

    char **files_name=malloc(200*sizeof(char*));
    int cont_files=0;
    cont_files=leerTexto("municipios.txt",files_name);
    printf("Archivos:%d\n",cont_files);

    
    
    
    char **lineas_texto=malloc(200*sizeof(char*));
    int cont_lineas_texto=0;
    
    cont_lineas_texto=leerTexto(*(files_name+1),lineas_texto);
    for(int j=0;j<cont_lineas_texto;j++){
        printf("Lineas: %s\n",*(lineas_texto+j));
    }





}