#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main()
{
    //file pointer
    FILE *fp = NULL;
    //Message
    char * ID[3] ={"100","101","102"};
    char * names[3]={"Ana Maria Arango","Diego Hernandez","Oscar Lozano"};
    char * ciudad[3]={"Bogota","Buenvaventura","Cartagena"};
    char * planes[3]={"Plan 1","Plan 2","Plan 3"};

    
    //Variable for message length
    int length = 0;
    //create and open the binary file
    fp = fopen("candidatos.dat", "wb");
    if(fp == NULL)
    {
        printf("Error in creating the file\n");
        exit(1);
    }
    int temp;
    
    for(int i = 0;i<3;i++){
        length = strlen(ID[i]);
        fwrite(ID[i], sizeof(char),length, fp);
        fwrite(",",sizeof(char),1,fp);
        length = strlen(names[i]);
        fwrite(names[i],sizeof(char),length,fp);
        fwrite(",",sizeof(char),1,fp);
        length = strlen(ciudad[i]);
        fwrite(ciudad[i],sizeof(char),length,fp);
        fwrite(",",sizeof(char),1,fp);
        length = strlen(planes[i]);
        fwrite(planes[i],sizeof(char),length,fp);
        temp=ftell(fp);
        printf("ftell antes:%d\n",temp);
        fseek(fp,(50*(i+1))-temp,SEEK_CUR);
        printf("ftell:%d\n",ftell(fp));
        
    }
    fflush(fp);
    fclose(fp);
    return 0;
}