#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Nombre: Mauricio David Cuello Alzate
  Carrera: Ing Electronica
  compilador: gcc en terminal
  Nota: El archivo de entrada esta separado por ";" y la cantidad de elementos a leer y escribir de estar hardcodeada
*/
typedef struct REGISTRO {
    int *ID;
    char *nombre;
    float *nota;
}REGISTRO;

typedef struct CANDITATO
{
    char *ID;
    char *names;
    char *ciudad;
    char *planes;
};


void llenar(REGISTRO *entrada,char *linea){
    char *token=malloc(10*sizeof(linea));
    char *copy=malloc(10*sizeof(linea));
    int *ID=malloc(sizeof(int));
    char *nombre=malloc(sizeof(char *));
    float *nota=malloc(sizeof(float));
    strcpy(copy,linea);
    token=strtok(copy,";");
    *ID=atoi(token);
    entrada->ID=ID;


    token=strtok(NULL,";");
    nombre=token;
    entrada->nombre=nombre;


    token=strtok(NULL,";");
    *nota=atof(token);
    entrada->nota=nota;
   
}



void print_registros(REGISTRO **tabla_registros,int cont){

    for(int i=0;i<cont;i++){
        printf("\n Persona: %d \n ID:%d\n Nombre: %s\n nota:%3f\n",i,(*(tabla_registros+i))->ID,(*(tabla_registros+i))->nombre,(*(tabla_registros+i))->nota);
    }
}
void print_strings(char **array, size_t len) 
{ 
    size_t i;
 
    for(i=0; i<len; i++){ 
        printf("%s|", array[i]);
    }
    printf("\n");
 
} 
int comparar(const void *a, const void *b) 
{ 
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
} 
char* evaluar(float x){
    char *result;
    if(x<3){
        result="C";
    }else if(3<x && x<4){
        result="B";
    }else if(4<=x){
        result="A";
    }
    return result;

}
void imprimir(char *strings[3],REGISTRO **tabla_registros,int n){
    FILE *nuevo_archivo;
    nuevo_archivo=fopen("sort_notes.txt","w");
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            int result = strcmp(((*(tabla_registros+i))->nombre),strings[j]);
            if(!result){
                char* printed=malloc(100*sizeof(char));
                char* result=malloc(100*sizeof(char));
                snprintf(result,10,"%d",*((*(tabla_registros+i))->ID));
                printed=result;
                strcat(printed,"\t");
                strcat(printed,((*(tabla_registros+i))->nombre));
                strcat(printed,"\t");

                char buf[100]; 
                
                gcvt(*((*(tabla_registros+i))->nota),3, buf); 
  

                strcat(printed,buf);
                strcat(printed,"\t");
                char* eval;
                eval=evaluar(*((*(tabla_registros+i))->nota));
                strcat(printed,eval);
                strcat(printed,"\n");
                int status=fputs(printed,nuevo_archivo);
            } 
            
        }
    }
    fclose(nuevo_archivo);

}



 
int main(){
    int n=3; //Cantidad de elementos
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
        cont+=1;
    }
    print_registros(tabla_registros,cont);
    
    char *strings[n];
    for(int i=0;i<n;i++){
        char *copy=malloc(sizeof(char*));
        char *token=malloc(sizeof(char*));
        strings[i]=((*(tabla_registros+i))->nombre);
    }
    size_t strings_len = sizeof(strings) / sizeof(char *);
    qsort(strings, strings_len, sizeof(char *),comparar);
    
    imprimir(strings,tabla_registros,n);
    
    
    fclose(archivo);
    free(tabla_registros);
}