#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main()
{
    //file pointer
    FILE *fp = NULL;
    FILE *file = NULL;
    //Message
    char * codigo[5] ={"1021","1064","1052","1033","1005"};
    char * apellido[5]={"Zapata Diaz","Sanchez Gomez","Correa Cruz","Arias Mendez","Duarte Garcia"};
    char * nombre[5]={"Teresa","Elizabeth","Carolina","Adriana","Diana Maria"};
    char * celular[5]={"3102","3164","3000","3174","3165"};
    char * indices[6]={"5","4","2","1","3"};
    
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
        length = strlen(codigo[i]);
        fwrite(codigo[i], sizeof(char),length, fp);
        fwrite(",",sizeof(char),1,fp);
        length = strlen(apellido[i]);
        fwrite(apellido[i],sizeof(char),length,fp);
        fwrite(",",sizeof(char),1,fp);
        length = strlen(nombre[i]);
        fwrite(nombre[i],sizeof(char),length,fp);
        fwrite(",",sizeof(char),1,fp);
        length = strlen(celular[i]);
        fwrite(celular[i],sizeof(char),length,fp);
        fwrite("\n",sizeof(char),1,fp);
        fwrite(indices[i],sizeof(char),1,file);
        fwrite("\n",sizeof(char),1,file);
        
    }
    fflush(fp);
    fclose(fp);
    return 0;
}