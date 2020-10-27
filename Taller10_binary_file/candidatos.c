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
typedef struct MUNICIPIO{
    char *nombre;
    int  *ID;
    int  *votos;
}MUNICIPIO;




void llenar_candidatos(char *linea,CANDIDATO *candidatos,int *cont_candidatos){
    
    CANDIDATO temp;

    
    char *ID=malloc(sizeof(linea));
    char *nombre=malloc(10*sizeof(linea));
    char *ciudad=malloc(10*sizeof(linea));
    char *plan=malloc(10*sizeof(linea));
    char *copy=malloc(10*sizeof(linea));
    strcpy(copy,linea);
    ID=strtok(copy,",");
    temp.ID=ID;
    nombre=strtok(NULL,",");
    temp.nombre=nombre;
    ciudad=strtok(NULL,",");
    temp.ciudad=ciudad;
    plan=strtok(NULL,",");
    temp.plan=plan;
    temp.conteo=0;
    *(candidatos+*(cont_candidatos))=temp;
    
}
   
void leerBinario(CANDIDATO *candidatos,int *cont_candidatos){
    FILE *archivo_candidatos;
    char * nombres=malloc(50*sizeof(char));
    archivo_candidatos=fopen("candidatos.dat","rb");

    if(archivo_candidatos==NULL) printf("Problema abriendo archivo binario\n");
    else printf("Archivo binario abierto exitosamente\n");

    fseek(archivo_candidatos,0,SEEK_END);
    int length=ftell(archivo_candidatos);
    fseek(archivo_candidatos,0,SEEK_SET);


    while(ftell(archivo_candidatos)!=length){
        fread(nombres,sizeof(char),50,archivo_candidatos);
        llenar_candidatos(nombres,candidatos,cont_candidatos);
        *(cont_candidatos)=*(cont_candidatos)+1;
    }
    fclose(archivo_candidatos);
}


void leerTexto(char * file,char **lineas_texto,int *cont){
    printf("FILE:%s\n",file);
    
    FILE *archivo_texto;
    char *linea=malloc(100*sizeof(char*));
    archivo_texto= fopen(file,"r");
    if(archivo_texto==NULL) printf("Error abriendo el archivo texto");
    else printf("Archivo texto abierto exitosamente\n");

    
    while(feof(archivo_texto)==0){
            fgets(linea,100,archivo_texto);
            *(lineas_texto+*(cont))=linea;
            *(cont)=*(cont)+1;
    }
    
    (fclose(archivo_texto)!=0) ? printf("Error cerrado archivo texto\n") : printf("Archivo texto cerrado exitosamente\n");
    
}



void imprimir_candidatos(CANDIDATO *candidatos,int cont){
    for(int i=0;i<cont;i++){
        printf("ID:%s\n",(candidatos+i)->ID);
        printf("nombre:%s\n",(candidatos+i)->nombre);
        printf("Ciudad:%s\n",(candidatos+i)->ciudad);
        printf("Plan:%s\n",(candidatos+i)->plan);
    }
}
void arreglar(char *linea,char **ID,int *votos){
    char *copy = malloc(sizeof(linea));
    char *token = malloc(sizeof(linea));
    strcpy(copy,linea);
    strtok(copy,",");
    token=strtok(NULL,",");
    *(ID)=token;
    token=strtok(NULL,",");
    *(votos)=atoi(token);
}

void leer_municipios(char *file,CANDIDATO *candidatos, MUNICIPIO *municipios,int cont_candidatos){
    FILE *archivo_municipio;
    char *linea = malloc(100*sizeof(char));
    archivo_municipio= fopen(file,"r");
    char *copy = malloc(sizeof(file));
    
    if(archivo_municipio==NULL) printf("Error abriendo el archivo texto");
    else printf("Archivo texto abierto exitosamente\n");
    int cont_municipio=0;
    MUNICIPIO municipio;
    char *nombre=malloc(sizeof(file));
    strcpy(copy,file);
    nombre=strtok(copy,".");
    municipio.nombre=nombre;
    while(feof(archivo_municipio)==0){
            char *ID = malloc(10*sizeof(char*));
            int votos;
            fgets(linea,100,archivo_municipio);
            arreglar(linea,&ID,&votos);
            conteo_votos(municipio,candidatos); // Aqui voy -> FALTA ESTA FUNCION
    }
    fclose(archivo_municipio);
}

int main(){


    int cont_candidatos=0;
    
    
    CANDIDATO *candidatos=malloc(100*sizeof(CANDIDATO));
    
    leerBinario(candidatos,&cont_candidatos);
    //imprimir_candidatos(candidatos,cont_candidatos);

    //Excepcion
    CANDIDATO blancos;
    blancos.ID="blancos";
    blancos.nombre="blancos";
    blancos.ciudad="blancos";
    blancos.plan="blancos";
    blancos.conteo=0;
    
    *(candidatos+cont_candidatos)=blancos;
    cont_candidatos++;
    
    CANDIDATO nulos;
    nulos.ID="nulos";
    nulos.nombre="nulos";
    nulos.ciudad="nulos";
    nulos.plan="nulos";
    nulos.conteo=0;

    *(candidatos+cont_candidatos)=nulos;

    cont_candidatos++;
    //imprimir_candidatos(candidatos,cont_candidatos);

    char **files_name=malloc(200*sizeof(char*));
    int cont_files=0;
    leerTexto("municipios.txt",files_name,&cont_files);
    MUNICIPIO *municipios=malloc(cont_files*sizeof(MUNICIPIO));

    for(int j=0;j<cont_files;j++){
            leer_municipios(*(files_name+j),candidatos,municipios,cont_candidatos);
    }


}