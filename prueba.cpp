#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
void agregar_valor(int *A,int *B,int *resultado){
    *resultado=*A+*B;
}
int main(){
    int datoA=4;
    int datoB=5;
    int res;
    int *apuntadorA=&datoA;
    int *apuntadorB=&datoB;
    int *resultado=&res;
    agregar_valor(apuntadorA,apuntadorB,resultado);
    cout<<"Resultado: "<<*resultado; 
    /*for(int i=0;i<5;i++){
        apuntador=&datos[i];
        cout<<"Apuntador: "<<apuntador<<"\t Valor: "<<*apuntador<<endl;
    }*/
}