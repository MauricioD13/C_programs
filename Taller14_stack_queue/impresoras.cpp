#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int main(){
    queue <int> cola_impresiones;
    int option=0;
    int numero;
    while(option==0){
        cout<<"Numero para la cola:\t";
        cin>>numero;
        cola_impresiones.push(numero);
        cout<<"Otro numero?\n";
        cin>>option;
    }
}