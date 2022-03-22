#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "make_files.h"

int generar(){
    //file pointer
    
    //Facturas
    char *Fecha[3] ={"07-Feb-19","09-Mar-19","23-Mar-19"}; // Maxima longitud del string 10 bytes
    int ID_surcursal[3]={2020,2021,2020};
    int  valor[3]={300000,700000,500000};
    int  valor_IVA[3]={48000,112000,80000};
    int ID_vendedor[3]={00001,00002,00001};

    //Vendedores
    int ID_vendedor_vendedores[3]={00001,00002,00003};
    char *nombre[3] ={"Gustavo Mora","Laura Pinto","Hamilton Perez"};
    int comision[3]={1,2,1};
    int  valor_comision[3]={0,0,0};
    
    
    int option=0;
    printf("[1] Generar archivos binario de facturas\n");
    printf("[2] Generar archivos binario de vendedores\n");
    printf("[3] Generar archivos texto de comision\n");
    printf("[4] Generar todo los archivos\n");
    printf("Opcion?:");

    scanf("%d",&option);
    //Variable for message length
    int length = 0;
    //create and open the binary file
    if(option==1){
        FILE *fp0 = NULL;
        fp0 = fopen("Facturas.dat", "wb");
        if(fp0 == NULL)
        {
            printf("Error in creating the file\n");
            exit(1);
        }
        int temp;
        
        for(int i = 0;i<3;i++){
            length = strlen(Fecha[i]);
            fwrite(Fecha[i], sizeof(char),length, fp0);
            fseek(fp0,1,SEEK_CUR);
            fwrite(&ID_surcursal[i],sizeof(int),1,fp0);
            fwrite(&valor[i],sizeof(int),1,fp0);
            fwrite(&valor_IVA[i],sizeof(int),1,fp0);
            fwrite(&ID_vendedor[i],sizeof(int),1,fp0);
            //fseek(fp,8,SEEK_CUR);
            printf("ftell:%d\n",ftell(fp0));
            //Cada linea de este archivio tiene un tamaño de 30 bytes
        }
        fflush(fp0);
        fclose(fp0);
        return 0;
    }
     if(option==2){
        FILE *fp1 = NULL;
        fp1 = fopen("Vendedores.dat", "wb");
        if(fp1 == NULL)
        {
            printf("Error in creating the file\n");
            exit(1);
        }
        int temp;
        
        for(int i = 0;i<3;i++){
            length = strlen(nombre[i]);
            fwrite(&(ID_vendedor_vendedores[i]),sizeof(int),1,fp1);
            temp=ftell(fp1);
            fwrite(nombre[i], sizeof(char),length, fp1);
            fseek(fp1,20-(ftell(fp1)-temp),SEEK_CUR);
            fwrite(&(comision[i]),sizeof(int),1,fp1);
            fwrite(&(valor_comision[i]),sizeof(int),1,fp1);
            printf("ftell:%d\n",ftell(fp1));
            //Cada linea de este archivio tiene un tamaño de 32 bytes
        }
        fflush(fp1);
        fclose(fp1);
        
        return 0;
    }
    if(option==3){
        FILE *archivo_texto;
        archivo_texto = fopen("comisiones.txt","w");
        char *comision[3]= {"1","2","3"};
        char *descripcion[3] = {"Comision Total","Comision Temporal","Comision Parcial"};
        char *porcentaje[3] = {"5","0.5","12"};

        for(int i = 0; i < 3 ; i++){
            fputs(comision[i],archivo_texto);
            fputs(";",archivo_texto);
            fputs(descripcion[i],archivo_texto);
            fputs(";",archivo_texto);
            fputs(porcentaje[i],archivo_texto);
            fputs("\n",archivo_texto);
        }
        fflush(archivo_texto);
        fclose(archivo_texto);
        return 0;
    }
    if(option==4){
        FILE *fp0 = NULL;
        fp0 = fopen("Facturas.dat", "wb");
        if(fp0 == NULL)
        {
            printf("Error in creating the file\n");
            exit(1);
        }
        int temp;
        
        for(int i = 0;i<3;i++){
            length = strlen(Fecha[i]);
            fwrite(Fecha[i], sizeof(char),length, fp0);
            fseek(fp0,1,SEEK_CUR);
            fwrite(&ID_surcursal[i],sizeof(int),1,fp0);
            fwrite(&valor[i],sizeof(int),1,fp0);
            fwrite(&valor_IVA[i],sizeof(int),1,fp0);
            fwrite(&ID_vendedor[i],sizeof(int),1,fp0);
            //fseek(fp,8,SEEK_CUR);
            
            //Cada linea de este archivio tiene un tamaño de 30 bytes
        }
        fflush(fp0);
        fclose(fp0);

        FILE *fp1 = NULL;
        fp1 = fopen("Vendedores.dat", "wb");
        if(fp1 == NULL)
        {
            printf("Error in creating the file\n");
            exit(1);
        }
        
        
        for(int i = 0;i<3;i++){
            length = strlen(nombre[i]);
            fwrite(&(ID_vendedor_vendedores[i]),sizeof(int),1,fp1);
            temp=ftell(fp1);
            fwrite(nombre[i], sizeof(char),length, fp1);
            fseek(fp1,20-(ftell(fp1)-temp),SEEK_CUR);
            fwrite(&(comision[i]),sizeof(int),1,fp1);
            fwrite(&(valor_comision[i]),sizeof(int),1,fp1);
            
            //Cada linea de este archivio tiene un tamaño de 32 bytes
        }
        fflush(fp1);
        fclose(fp1);
        FILE *archivo_texto;
        archivo_texto = fopen("comisiones.txt","w");
        char *comision[3]= {"1","2","3"};
        char *descripcion[3] = {"Comision Total","Comision Temporal","Comision Parcial"};
        char *porcentaje[3] = {"5","0.5","12"};

        for(int i = 0; i < 3 ; i++){
            fputs(comision[i],archivo_texto);
            fputs(";",archivo_texto);
            fputs(descripcion[i],archivo_texto);
            fputs(";",archivo_texto);
            fputs(porcentaje[i],archivo_texto);
            fputs("\n",archivo_texto);
        }
        fflush(archivo_texto);
        fclose(archivo_texto);
        return 0;
        

    }
}