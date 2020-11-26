#include <iostream>
#include <string>
#include <cstdlib>
#include "listas.cpp"

typedef struct JUGADOR
{
    char *nombre;
    int ubicacion_tablero;
}JUGADOR;
typedef struct CASILLA{

    Lista<JUGADOR> *jugadores;
    Nodo<CASILLA> *cambio;
    int tipo;

}CASILLA;

void generar(Lista <CASILLA> *tablero){
    
    for(int i=0;i<25;i++){
        CASILLA casilla;
        Lista <JUGADOR> *jugadores;
        jugadores = crearLista<JUGADOR>();
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
        /*if(iterador->info.cambio==NULL){
            cout<<"-\t";
        }
        else{
            
            cout<<iterador->info.tipo<<"\t";
        }*/
        if(iterador->info.jugadores->cab==NULL){
            cout<<"-\t";
        }
        else{
            Nodo <JUGADOR> *iterador_jugadores;
            iterador_jugadores = iterador->info.jugadores->cab;
            while(iterador_jugadores!=NULL){
                cout<<iterador_jugadores->info.nombre;
                iterador_jugadores = iterador_jugadores->sig;
            }
            cout<<"\t";
        }
        if(i%5==0){
            cout<<"\n\n";
        }
        iterador = iterador -> sig;
        i++;
    }
    cout<<"\n\n";
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


void agregar_jugadores(Lista<JUGADOR> *jugadores_global){
    int option=1;
    char *temp;
    JUGADOR *jugador;
    int i=0;
    while(option==1){
        jugador = new JUGADOR;
        temp = new char[2];
        if(i==4){
            cout<<"A llegado al maximo de jugadores"<<endl;
            break;
        }
        cout<<"Agregar una letra para el jugador"<<endl;
        cin>>*temp;
        jugador->nombre = temp;
        insertar(jugadores_global,*jugador);
        
        cout<<"¿Agregar otro jugador?"<<endl;
        cout<<"[1] Si\t[2] No"<<endl;
        cin>>option;
        i++;
        cout<<"-----------------------------------------------\n";
        
    
    }
    
}
void posicionar_jugadores(Lista<CASILLA> *tablero, Lista<JUGADOR> *jugadores_global,int *turnos){
    char *jugador = new char[2];
    Nodo <JUGADOR> *iterador;
    
    iterador = jugadores_global->cab;
    
    if(*turnos == 0){
        int i=0;
        while(iterador!=NULL){
            JUGADOR *temp = new JUGADOR;
            *temp = obtenerDato(jugadores_global,i);
            temp->ubicacion_tablero = i;
            insertar(tablero->cab->info.jugadores,*temp);
            iterador = iterador->sig;
            i++;
        }
    }
}
/*void mecanica_juego(Lista <CASILLA> *tablero){
    
}*/



int main(){
    //Inicializar srand con el tiempo para que los numero sean aletorios
    int turnos=0;
    srand(time(NULL));
    Lista <CASILLA> *tablero;
    tablero = crearLista<CASILLA>();
    generar(tablero);
    escaleras_serpientes(tablero);
    imprimir_tablero(tablero);
    cout<<"-----------------------------------------------\n";
    Lista <JUGADOR> *jugadores_global= crearLista<JUGADOR>();
    agregar_jugadores(jugadores_global);
    posicionar_jugadores(tablero,jugadores_global,&turnos);
    imprimir_tablero(tablero);
    //mecanica_juego(tablero); 
}