#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*Autor: Mauricio David Cuello Alzate
 Carrera: Ing Electronica
 Compilador: gcc en terminal
*/ 






int main(){
    FILE *archivo1;
    char *linea1=malloc(100*sizeof(char));
    char *linea2=malloc(100*sizeof(char));
    archivo1 = fopen("f1.txt","r");
    if(archivo1==NULL){
        printf("\n Ha habido un problema con el archivo\n");
        return 1;
    }
    else{
        printf("\n El archivo ha sido abierto exitosamente \n");
    }
    FILE *archivo2;
    archivo2=fopen("f2.txt","r");
    if(archivo2==NULL){
        printf("\n Ha habido un problema con el archivo\n");
    }
    else{
        printf("\n El nuevo archivo ha sido abierto exitosamente \n");
    }

    while(feof(archivo1)==0 && feof(archivo2)==0){
        
        fgets(linea1,1000,archivo1);
        fgets(linea2,1000,archivo2);
        if(strcmp(linea1,linea2)){
            printf("< %s\n",linea1);
            printf("> %s\n",linea2);
        }
        char *copy=malloc(100*sizeof(char));
        
        
    }



}