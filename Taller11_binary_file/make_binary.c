#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct PERSONA{
    char codigo[4];
    char apellido[20];
    char nombre[20];
    char celular[4];
}PERSONA;


int main()
{
    //file pointer
    FILE *fp = NULL;
    FILE *file = NULL;
    //Message
    int codigo[5] ={1021,1064,1052,1033,1005};
    char *apellido[5]={"Zapata Diaz","Sanchez Gomez","Correa Cruz","Arias Mendez","Duarte Garcia"};
    char *nombre[5]={"Teresa","Elizabeth","Carolina","Adriana","Diana Maria"};
    int celular[5]={3102,3164,3000,3174,3165};
    int indices[5]={3,2,4,1,0};
    
    //Variable for message length
    int length = 0;
    //create and open the binary file
    fp = fopen("datos.bin", "wb");
    file = fopen("indice.bin","wb");
    if(fp == NULL || file==NULL)
    {
        printf("Error in creating the file\n");
        exit(1);
    }

    

    for(int i = 0;i<5;i++){
        
        fwrite(&codigo[i],sizeof(int),1,fp);

        length=(strlen(apellido[i]));
        fwrite(apellido[i],length+1,1,fp);
        fseek(fp,(20-length),SEEK_CUR);

        length=(strlen(nombre[i]));
        fwrite(nombre[i],length+1,1,fp);
        fseek(fp,(20-length),SEEK_CUR);

        fwrite(&celular[i],sizeof(int),1,fp);
        

        fwrite(&indices[i],sizeof(int),1,file);
        
    }

    fflush(fp);
    fclose(fp);
    fclose(file);
    return 0;
}