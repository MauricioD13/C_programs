#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*Autor: Mauricio David Cuello Alzate
 Carrera: Ing Electronica
 Compilador: gcc en terminal
 NOTA: No pude quitarle el salto de linea en el archivo final
*/ 

int tokenized(char **numbers,char* linea){
    char *copy=malloc(sizeof(linea));
    char *token=malloc(sizeof(linea));
    strcpy(copy,linea);
    int cont=0;
    token=strtok(copy,":");
    while(token!=NULL){
        *(numbers+cont)=token;
        
        token=strtok(NULL,":");
        cont++;
    }
    return cont;

}




int main(){
    FILE *archivo1;
    char *linea1=malloc(100*sizeof(char));
    char *linea2=malloc(100*sizeof(char));
    char *linea3=malloc(100*sizeof(char));

    archivo1 = fopen("file1.txt","r");
    if(archivo1==NULL){
        printf("\n Ha habido un problema con el archivo\n");
        return 1;
    }
    else{
        printf("\n El archivo1 ha sido abierto exitosamente \n");
    }
    FILE *archivo2;
    archivo2=fopen("file2.txt","r");
    if(archivo2==NULL){
        printf("\n Ha habido un problema con el archivo\n");
    }
    else{
        printf("\n El archivo2 ha sido abierto exitosamente \n");
    }
    FILE *archivo3;
    archivo3=fopen("file3.txt","w");
    if(archivo3==NULL){
        printf("\n Ha habido un problema con el archivo\n");
    }
    else{
        printf("\n El archivo3 ha sido abierto exitosamente \n");
    }
    char **numbers1=malloc(1000*sizeof(char*));
    char **numbers2=malloc(1000*sizeof(char*));
    char **numbers3=malloc(1000*sizeof(char*));
    int cont1=0;
    int cont2=0;
    int cont3=0;
    
    while(feof(archivo1)==0 && feof(archivo2)==0 && feof(archivo3)==0){
        
        fgets(linea1,1000,archivo1);
        cont1=tokenized(numbers1,linea1);
        fgets(linea2,1000,archivo2);
        cont2=tokenized(numbers2,linea2);
        char *temp=malloc(sizeof(linea1));
        for(int i=0;i<cont1;i++){
            temp=*(numbers1+i);
            *(numbers3+i)=temp;
        }
        cont3=cont1;
        for(int j=0;j<cont2;j++){
            if(strcmp(*(numbers2+j),*(numbers3+j))!=0){
                *(numbers3+cont1-1+j)=*(numbers2+j);
                cont3++;
            }
        }
        char *word=malloc(100*sizeof(linea1));
        char *convert=malloc(100*sizeof(linea1));
        strcpy(word,(*(numbers3)));
        strncat(word,":",2);
        for(int k=1;k<cont3;k++){
            strcpy(convert,(*(numbers3+k)));
            strncat(word,convert,4);
            strncat(word,":",4);
        }
        fputs(word,archivo3);
        fputs("-----\n",archivo3);
    }

    fclose(archivo3);
    fclose(archivo2);
    fclose(archivo1);

}