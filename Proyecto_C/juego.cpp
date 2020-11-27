#include <iostream>
#include <string>
#include <cstdlib>
#include "listas.cpp"
#include <math.h>

using namespace std;

typedef struct JUGADOR
{
    char *nombre;
    int ubicacion_tablero;
    int contador;
    int recta_final;
}JUGADOR;
typedef struct CASILLA{

    Lista<JUGADOR> *jugadores;
    int cambio;
    int tipo;

}CASILLA;

void generar(Lista <CASILLA> *tablero,int tamaño){
    
    for(int i=0;i<tamaño;i++){
        CASILLA casilla;
        Lista <JUGADOR> *jugadores;
        jugadores = crearLista<JUGADOR>();
        casilla.jugadores = jugadores;
        casilla.cambio = 0;
        casilla.tipo = 0;
        insertar(tablero,casilla);
    }

    
    
}

void imprimir_tablero(Lista <CASILLA> *tablero,int tamaño){

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
        if(i%(int)(sqrt((double)tamaño))==0){
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


void escaleras_serpientes(Lista <CASILLA> *tablero,int tamaño){
    
    for(int i=0;i<6;i++){
        int casilla = rand()%tamaño;
        int target = rand()%tamaño;
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
                
                iterador->info.cambio = target;
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
        jugador->contador = 0;
        jugador->recta_final = 0;
        jugador->ubicacion_tablero = 0;
        insertar(jugadores_global,*jugador);
        
        cout<<"¿Agregar otro jugador?"<<endl;
        cout<<"[1] Si\t[2] No"<<endl;
        cin>>option;
        i++;
        cout<<"-----------------------------------------------\n";
        
    
    }
    
}
void posicionar_jugadores(Lista<CASILLA> *tablero, Lista<JUGADOR> *jugadores_global){
    char *jugador = new char[2];
    Nodo <JUGADOR> *iterador;
    
    iterador = jugadores_global->cab;
    
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
void mecanica_juego(Lista <CASILLA> *tablero, Lista <JUGADOR> *jugadores_global,int *flag,int tamaño){
    Nodo <JUGADOR> *jugador;
    Nodo <CASILLA> *iterador_casilla;

    jugador = jugadores_global->cab;

    int x=0;
    int opcion=0;
    while(jugador!=NULL){
        iterador_casilla = tablero->cab;
        int dado = 0;
        while(dado==0){
            dado = rand()%7;
        }
        cout<<"[1] Lanzar dado"<<endl;
        cin>>opcion;
        char *temp_nombre = jugador->info.nombre;
        cout<<"JUGADOR: "<<*temp_nombre<<endl;
        cout<<"Sacaste "<<dado<<" en el dado"<<endl;
        int posicion_nueva = jugador->info.ubicacion_tablero + dado;
        //Excepcion de sacar 6 tres veces
        if(dado == 6){
            jugador->info.contador++;
            if(jugador->info.contador==3){
                posicion_nueva = 0;
            }
        }
        if(posicion_nueva == tamaño){
            *flag = 1;
        }
        
        //Encontrar la casilla donde esta el jugador
        for(int i=0;i<jugador->info.ubicacion_tablero;i++){
            iterador_casilla = iterador_casilla->sig;
        }
        //Comparar nombres 
        if(vacia(iterador_casilla->info.jugadores)){
            cout<<"Encontre el error: "<<"ubicacion "<<jugador->info.ubicacion_tablero<<endl;
            
        }
        cout<<"temp_nombre "<<temp_nombre<<"\tnombre: "<<iterador_casilla->info.jugadores->cab->info.nombre<<"\t ubicacion: "<<jugador->info.ubicacion_tablero<<"\tposicion nueva: "<<posicion_nueva<<endl;
        if(vacia(iterador_casilla->info.jugadores)){
            cout<<"Encontre el error\n";
            
        }
        
        if(temp_nombre==iterador_casilla->info.jugadores->cab->info.nombre){
            //Eliminar el jugador de la lista de jugadores de la casilla
            
            eliminar(iterador_casilla->info.jugadores,0) ? cout<<"Eliminacion exitosa\n": cout<<"Problemas en eliminacio\n";
            jugador->info.ubicacion_tablero = posicion_nueva;
            Nodo <JUGADOR> *aux;
            aux = iterador_casilla->info.jugadores->cab;
            while(aux!=NULL){
                cout<<"Informacion: "<<aux->info.nombre<<endl;
                aux = aux->sig;
            }    


            iterador_casilla = tablero->cab;
            //Encontrar la nueva casilla donde va a estar el jugador
            for(int j=0;j<posicion_nueva;j++){
                iterador_casilla = iterador_casilla->sig;
            }
            //Verificar serpierte o escalera en la casilla que cayo el jugador
            if(iterador_casilla->info.cambio!=0){
                iterador_casilla->info.tipo>0 ? cout<<"Aqui hay una escalera a "<<iterador_casilla->info.cambio<<endl : cout<<"Aqui hay una serpiente a "<<iterador_casilla->info.cambio<<endl;
                jugador->info.ubicacion_tablero = iterador_casilla->info.cambio;
                int temp = iterador_casilla->info.cambio;
                iterador_casilla = tablero->cab;
                for(int k=0;k<temp;k++){
                    iterador_casilla = iterador_casilla->sig;
                }
                
                
                cout<<"Ubicacion con cambio: "<<jugador->info.ubicacion_tablero<<endl;
            }
            
            JUGADOR temp_jugador;
            temp_jugador = obtenerDato(jugadores_global,x);
            cout<<"temp_jugador: "<<temp_jugador.nombre<<endl;
            
            insertar(iterador_casilla->info.jugadores,temp_jugador);
        }
        
        x++;
       
        jugador = jugador->sig;
        imprimir_tablero(tablero,tamaño);
    }
}



int main(){
    //Inicializar srand con el tiempo para que los numero sean aletorios
    srand(time(NULL));
    int option=1;
    int flag=0;
    int tamaño = 25;
    while(option!=0){
        cout<<"[1] Iniciar el juego\n";
        cout<<"[2] Configuraciones\n";
        cout<<"[0] Salir\n";
        cin>>option;
        switch (option){
        case 0:
            cout<<"Adios :)"<<endl;
            break;
        case 1:
            Lista <CASILLA> *tablero;
            tablero = crearLista<CASILLA>();
            generar(tablero,tamaño);
            escaleras_serpientes(tablero,tamaño);
            imprimir_tablero(tablero,tamaño);
            Lista <JUGADOR> *jugadores_global= crearLista<JUGADOR>();
            agregar_jugadores(jugadores_global);
            posicionar_jugadores(tablero,jugadores_global);
            imprimir_tablero(tablero,tamaño);
            while(flag==0){
                mecanica_juego(tablero,jugadores_global,&flag,tamaño); 
                
            }

            cout<<"-----------------------------------------------\n";
            break;
        }
        
    }
}