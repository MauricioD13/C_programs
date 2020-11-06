#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "make_files.h"
/*  Autor: Mauricio David Cuello Alzate
    Carrera: Ing Electronica
    Compilador: gcc en terminal (gcc punto1.c make_files.c -o punto1)
*/
typedef struct FACTURA{
    char* fecha;
    int ID_sucursal;
    int valor_factura;
    int valor_IVA;
    int ID_vendedor;
}FACTURA;
typedef struct VENDEDOR
{
    int ID_vendedor;
    char *nombre;
    int comision;
    int valor_comision;
}VENDEDOR;



void leer_facturas(int ID_vendedor,int *valor_comision,int cant_vendedores){
    
    int dato;
    int valor;
    FILE *archivo_facturas= fopen("Facturas.dat","rb");
    
    for(int i=1;i<cant_vendedores+1;i++){
        fseek(archivo_facturas,(26*i-sizeof(int)),SEEK_SET);
        fread(&dato,sizeof(int),1,archivo_facturas);
        
        if(dato==ID_vendedor){
            fseek(archivo_facturas,(26*i)-(3*sizeof(int)),SEEK_SET);
            fread(&valor,sizeof(int),1,archivo_facturas);
            
            (*valor_comision)=(*valor_comision)+valor;
            
       }
        
    }
    
}



float leer_comision(int comision,char* descripcion){
    FILE *archivo_comision = fopen("comisiones.txt","r");
    float porcentaje;
    char *datos = (char*)malloc(30*sizeof(char));
    char *token = (char*)malloc(20*sizeof(char));
    char *copy = (char*)malloc(20*sizeof(char));
    
    while(feof(archivo_comision)==0){
        fgets(datos,30,archivo_comision);
        strcpy(copy,datos);
        token = strtok(copy,";");
        if(atoi(token) == comision){
            descripcion = strtok(NULL,";");
            porcentaje = atof(strtok(NULL,";"));
            printf("Descripcion:%s\n",descripcion);
            
            break;
        }
        
    }
    
    return porcentaje;
}

void leer_vendedores(){
    
    
    
    FILE *archivo_vendedores= fopen("Vendedores.dat","rb");
    fseek(archivo_vendedores,0,SEEK_END);
    //printf("ftell:%d\n",ftell(archivo_vendedores));
    int cant_vendedores = ftell(archivo_vendedores)/32; // Dado que para la informacion de cada vendedor se usan 30 bytes
    float porcentaje;
    float temp;
    fseek(archivo_vendedores,0,SEEK_SET);
    for(int i=0;i<cant_vendedores;i++){
        VENDEDOR vendedor;
        char *dato_string = (char*)malloc(10*sizeof(char));
        
        fread(&(vendedor.ID_vendedor),sizeof(int),1,archivo_vendedores);
        fread(dato_string,sizeof(char),20,archivo_vendedores);
        vendedor.nombre = dato_string;
        fread(&(vendedor.comision),sizeof(int),1,archivo_vendedores);
        fread(&(vendedor.valor_comision),sizeof(int),1,archivo_vendedores);
        printf("Nombre:%s\t",vendedor.nombre);
        char *descripcion = (char*)malloc(20*sizeof(char));
        porcentaje = leer_comision(vendedor.comision,descripcion); 
        
        leer_facturas(vendedor.ID_vendedor,&(vendedor.valor_comision),cant_vendedores);
        temp = (float)vendedor.valor_comision * (porcentaje/100);
        printf("Valor de comision:%d\n",(int)temp);
        printf("-------------------------------------------------\n");
        
    }
    fclose(archivo_vendedores);

}




int main(){
    int option;
    printf("Punto 1 Parcial 2\n Autor: Mauricio David Cuello Alzate \t Carrera: Ing. Electrónica\n");
    int estado=generar();
    printf("-------------------------------------------------\n");
    printf("[1] Mostrar comision\n");
    printf("[2] Salir\n");
    printf("Opcion?:\n");
    scanf("%d",&option);
    printf("-------------------------------------------------\n");
    if(option==1){
        leer_vendedores();
    }
    
   

}