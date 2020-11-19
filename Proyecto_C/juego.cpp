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
        casilla.tipo = 0;
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

void buscador(Lista <CASILLA> *tablero,int target,Nodo <CASILLA> *objetivo){
    Nodo <CASILLA> *iterador;
    iterador = tablero ->cab;
    int j;
    while(iterador!=NULL){
        if(target==j){
            objetivo = iterador ;
        }
        iterador = iterador -> sig;
        j++;
    }
    
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
                
                buscador(tablero,target,objetivo);
                
                iterador->info.cambio = objetivo;
                iterador->info.tipo = tipo;
                
            }
            iterador = iterador->sig;
            j++;
        
         }
    }
    
}


void agregar_jugadores(Lista<char> *jugadores_global){
    int option=1;
    char temp;
    
    while(option==1){
        cout<<"Agregar una letra para el jugador"<<endl;
        cin>>temp;
        insertar(jugadores_global,temp);
        cout<<"¿Agregar otro jugador?"<<endl;
        cout<<"[1] Si\t[2] No"<<endl;
        cin>>option;
    }
    
}

/*void mecanica_juego(Lista <CASILLA> *tablero){
    
}*/



int main(){
    srand(time(NULL));
    Lista <CASILLA> *tablero;
    tablero = crearLista<CASILLA>();
    generar(tablero);
    escaleras_serpientes(tablero);
    imprimir_tablero(tablero);
    Lista <char> *jugadores_global= crearLista<char>();
    agregar_jugadores(jugadores_global);
    //mecanica_juego(tablero);

}