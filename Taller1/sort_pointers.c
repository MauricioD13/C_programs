#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Autor: Mauricio David Cuello Alzate
//Carrera: Ingenieria electronica


//Funcion para ordenar 
void sort(int **pointers,int *quantity){
    int *aux=NULL;
    int i=1,j=1;
    while(j<*quantity-1){
        while(i<*quantity-1){
            //Se desreferencia dos veces el apuntador pointers para obtener el numero entero a comparar
            if(**(pointers+i)>**(pointers+i+1)){
                aux=*(pointers+i);
                *(pointers+i)=*(pointers+i+1);
                *(pointers+i+1)=aux;
            }
            i++;
        }
        i=1;
        j++;
    }

}


/*Funcion para generar los numeros aleatorios, el valor de pointers sera el la direccion de vector.
Posteriormente se utiliza la funciona rand de la libreria stdlib.h para generar los numeros aleatorios*/
void generate(int *vector,int *quantity,int **pointers){
    for(int cont=1;cont<*quantity;cont++){
        *(pointers+cont)=(vector+cont); 
        *(vector+cont)=rand()%100;        
    }

}

int main(){
    /*Se inicia la semilla para rand() con la hora actual para que efectivamente sean numero aleatorios y diferentes
    cada vez que corra el programa*/
    srand(time(NULL));


    int quantity;
    printf("CODIGO PARA ORDENAR NUMEROS A PARTIR DE APUNTADORES \n")
    printf("Introduzca una cantidad: ");
    scanf("%d",&quantity);
    quantity+=1;

    //Asignacion de memoria dinamica
    int **pointers=(int**)malloc(quantity*sizeof(int*));
    int *vector=(int *)malloc(quantity*sizeof(int));


    //Verificacion de la alocacion de memoria
    if(vector==NULL||pointers==NULL){
        printf("Hubo un problema con la asignacion de memoria");
    }
    //Se llama la funcion generate para generar los numeros aleatorios
    generate(vector,&quantity,pointers);
    printf("-------DESPUES DE GENERATE---------\n");
    for(int i=1;i<quantity;i++){
        printf("Enteros de vector: %d ,\tDirecciones de vector: %p,  Direcciones a las que apunta pointers: %p, Enteros a partir de pointers: %d\n",*(vector+i),vector+i,*(pointers+i),**(pointers+i));
    }

    //Posteriormente se ordenan los numero a partir de los apuntadores a apuntadores
    sort(pointers,&quantity);
    printf("----------RESULTADOS---------\n");
    for(int j=1;j<quantity;j++){
        printf("Enteros a partir de vector %d, \t Enteros a partir de pointers: %d \n",*(vector+j),**(pointers+j));
    }
}
