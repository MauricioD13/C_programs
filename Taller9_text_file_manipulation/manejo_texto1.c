#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*Autor: Mauricio David Cuello Alzate
 Carrera: Ing Electronica
 Compilador: gcc en terminal
*/ 

void upper(char* word, char* result,char **storage){
    
    int i=0;
    char character;
    char convert[2];
    char *upper_word=malloc(100*sizeof(word));
    while(word[i]!='\0'){
        character=toupper(word[i]);
        convert[0]=character;
        convert[1]='\0';
        printf("LETRAS:%s\n",convert);
        strcat(upper_word,convert);
    }
    
    //fputs("\n",nuevo_archivo);
    printf("WORD:%s\n",upper_word+1);
}

void tokenized(char *line,char **storage,FILE *nuevo_archivo){
    char *token=malloc(100*sizeof(char));
    char *word=malloc(100*sizeof(char));
    char *result=malloc(100*sizeof(char));
    
    token=strtok(line,",  .?\n");
    while(token!=NULL){
        
        strcpy(word,token);
        int i=0;
        char character;
        char convert[2];
        char *upper_word=malloc(100*sizeof(word));
        while(word[i]!='\0'){
            character=toupper(word[i]);
            convert[0]=character;
            convert[1]='\0';
            strcat(upper_word,convert);
            i++;
        }
        fputs(upper_word,nuevo_archivo);
        fputs("\t",nuevo_archivo);
        token=strtok(NULL,",  .?\n");
    }
    
}


int main(){
    FILE *archivo;
    char *linea=malloc(100*sizeof(char));
    archivo = fopen("archivo1.txt","r");
    if(archivo==NULL){
        printf("\n Ha habido un problema con el archivo\n");
        return 1;
    }
    else{
        printf("\n El archivo ha sido abierto exitosamente \n");
    }
    FILE *nuevo_archivo;
    nuevo_archivo=fopen("mayusculas.txt","w");
    if(nuevo_archivo==NULL){
        printf("\n Ha habido un problema con el archivo\n");
    }
    else{
        printf("\n El nuevo archivo ha sido abierto exitosamente \n");
    }
    int cont=0;
    char **storage=malloc(10*sizeof(char*));
    while(feof(archivo)==0){
        
        fgets(linea,1000,archivo);
        char *copy=malloc(100*sizeof(char));
        
        strcpy(copy,linea);
        tokenized(copy,storage,nuevo_archivo);
        fputs("\n",nuevo_archivo);
        cont+=1;
    }
    fclose(nuevo_archivo);
    fclose(archivo);
}