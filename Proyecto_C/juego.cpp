#include <iostream>
#include <string>
#include <cstdlib>
#include "listas.cpp"

typedef struct CASILLA{

    Lista<char> *jugadores;
    Nodo<CASILLA> *cambio;
    int tipo;

}CASILLA;

void generar(Lista <CASILLA> *tablero){
    
    for(int i=0;i<25;i++){
        CASILLA casilla;
        Lista <char> *jugadores;
        jugadores = crearLista<char>();
        casilla.jugadores = jugadores;
        casilla.cambio = NULL;
        insertar(tablero,casilla);
    }
    
    
}

void imprimir_tablero(Lista <CASILLA> *tablero){
    Nodo <CASILLA> *iterador;
    iterador = tablero ->cab;
    int i=1;
    cout<<"------------------------------------------\n";
    while(iterador!=NULL){
        if(iterador->info.cambio==NULL){
            cout<<"-\t";
        }
        else{
            cout<<iterador->info.tipo<<"\t";
        }
        if(i%5==0){
            cout<<"\n";
        }
        iterador = iterador -> sig;
        i++;
    }
    cout<<"\n";
}

Nodo <CASILLA> *buscador(Lista <CASILLA> *tablero,int target){
    Nodo <CASILLA> *iterador;
    iterador = tablero ->cab;
    Nodo <CASILLA> *objetivo;
    int j;
    while(iterador!=NULL){
        if(target==j){
            return iterador;
        }
        iterador = iterador -> sig;
        j++;
    }
    return iterador;
}


void escaleras_serpientes(Lista <CASILLA> *tablero){
    for(int i=0;i<6;i++){
        int casilla = rand()%25;
        int target = rand()%25;
        Nodo <CASILLA> *iterador;
        iterador = tablero->cab;
        int j=0;
        int tipo;
        if(casilla>target){
            tipo = -1;
        }
        else{
            tipo = 1;
        }
        Nodo <CASILLA> *objetivo;
        while(iterador!=NULL){
            if(j==casilla){
                objetivo = buscador(tablero,target);
                cout<<"";
                iterador->info.cambio = objetivo;
                iterador->info.tipo = tipo;
            }
            iterador = iterador->sig;
            j++;
        
         }
    }
}
/*void mover(CASILLA **tablero,JUGADOR jugadores){
    
}


*/
int main(){
    srand(time(NULL));
    Lista <CASILLA> *tablero;
    tablero = crearLista<CASILLA>();
    generar(tablero);
    escaleras_serpientes(tablero);
    imprimir_tablero(tablero);

}