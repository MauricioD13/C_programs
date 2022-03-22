#include <stdio.h>
#include <stdlib.h>
template <typename tipo1>
tipo1 suma(tipo1 a[5],int cont){
    cont--;
    if(cont<=0):
        return a[0];
    return a[cont]+suma(a);
}

int main(){

    int a[5]={1,2,3,4,5};
    int cont=6;
    printf("Suma:%d\n",suma(a,cont));
    


}