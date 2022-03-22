#include <iostream>
#include <string>
#include <cstdlib>
#include "listas.cpp"
#include <math.h>

using namespace std;
/*  AUTOR: Mauricio David Cuello Alzate
    Compilador: g++ en linux*/
typedef struct JUGADOR
{
    char *nombre;
    int ubicacion_tablero;
    int contador;
    int recta_final;
    int penitencia;
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
        if(iterador->info.jugadores->cab==NULL && iterador->info.cambio == 0){
            cout<<"("<<i<<")\t";
        }
        else if(iterador->info.jugadores!=NULL && iterador->info.cambio == 0){
            Nodo <JUGADOR> *iterador_jugadores;
            iterador_jugadores = iterador->info.jugadores->cab;
            while(iterador_jugadores!=NULL){
                cout<<iterador_jugadores->info.nombre;
                iterador_jugadores = iterador_jugadores->sig;
            }
            cout<<"\t";
        }
        else{
            if(iterador->info.tipo>0){
                cout<<"$"<<"\t";
            }else{
                cout<<"@"<<"\t";
            }
        }
        if(i%(int)(sqrt((double)tamaño))==0){
            cout<<"\n\n";
        }
        iterador = iterador -> sig;
        i++;
    }
    cout<<"\n\n";
}

void escaleras_serpientes(Lista <CASILLA> *tablero,int tamaño,int cantidad){
    
    for(int i=0;i<cantidad;i++){
        int casilla = 0;
        int target;
        while(casilla == 0 || target == 24 || casilla == 24){
            casilla = rand()%tamaño;
            target = rand()%tamaño;
        }
        Nodo <CASILLA> *iterador;
        iterador = tablero->cab;
        int j=0;
        int tipo;
        int bandera;
        if(casilla>target){
            tipo = -1;
        }
        else{
            tipo = 1;
        }
        
        Nodo <CASILLA> *objetivo;
        while(iterador!=NULL){

            if(j==casilla){
                if(iterador->info.cambio!=0){
                    casilla = 0;
                    while(casilla == 0 || target == 24 || casilla == 24){
                        casilla = rand()%tamaño;
                        target = rand()%tamaño;
                    }
                    iterador = tablero->cab;
                    j = 0;
                    continue;
                }
                iterador->info.cambio = target;
                iterador->info.tipo = tipo;
                //cout<<"casilla:"<<casilla<<" target:"<<target<<" tipo:"<<iterador->info.tipo<<endl;
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
        if(i==4){
            cout<<"-----------------------------------------------\n";
            cout<<"A llegado al maximo de jugadores"<<endl;
            break;
        }
        temp = new char[2];
        cout<<"-----------------------------------------------\n";
        cout<<"Agregar una letra para el jugador"<<endl;
        cin>>*temp;
        jugador->nombre = temp;
        jugador->contador = 0;
        jugador->recta_final = 0;
        jugador->ubicacion_tablero = 0;
        jugador->penitencia = 0;
        insertar(jugadores_global,*jugador);
        
        if(i>0){
            cout<<"-----------------------------------------------\n";
            cout<<"¿Agregar otro jugador?"<<endl;
            cout<<"[1] Si\t[2] No"<<endl;
            cin>>option;
        }
        
        i++;
        
        
        
    
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
        imprimir_tablero(tablero,tamaño);
        //Numero aleatorio de 1 a 6 para el dado
        int dado = 0;
        char *temp_nombre = jugador->info.nombre;
        cout<<"JUGADOR: "<<*temp_nombre<<endl;
        cout<<"[1] Lanzar dado"<<endl;
        cout<<"[0] Salir"<<endl;
        cin>>opcion;
        if(opcion == 0){
            *flag = 1;
            break;
        }
        while(dado==0){
            dado = rand()%7;
        }
        
        
        
        cout<<"Sacaste "<<dado<<" en el dado"<<endl;

        //Condicion de penitencia: Mirar si el jugador tiene penitencia por sacar 3 veces 6 en el dado
        if(jugador->info.penitencia == 1 && dado!=6){
            cout<<"Jugador "<<jugador->info.nombre<<" no ha sacado 6 para poder comenzar a avanzar"<<endl;
            jugador = jugador->sig;
            x++;
            continue;
        }else if (dado == 6 || jugador->info.penitencia == 1){
            jugador->info.penitencia = 0;
        }
        
        /*Condicion de finalizacion: Cuando el jugador este en las ultimas casillas la variable recta_final pasa a uno y despues entra a
        este condicional*/
        if(jugador->info.recta_final==1){
            int valor_exacto = tamaño - jugador->info.ubicacion_tablero - 1;
            if(valor_exacto != dado){
                cout<<"Nos has sacado el valor exacto para ganar"<<endl;
                jugador = jugador->sig;
                x++;
                continue;
            }else{
                cout<<"JUGADOR "<<jugador->info.nombre<<" es el GANADOR del juego"<<endl;
                *flag = 1;
                break;
            }
        }
        
        int posicion_nueva = jugador->info.ubicacion_tablero + dado;
        //Excepcion de sacar 6 tres veces
        
        if(posicion_nueva == tamaño){
            *flag = 1;
        }
        iterador_casilla = tablero->cab;
        //Encontrar la casilla donde esta el jugador
        for(int i=0;i<jugador->info.ubicacion_tablero;i++){
            iterador_casilla = iterador_casilla->sig;
        }
        
        
        //cout<<"temp_nombre "<<temp_nombre<<"\tnombre: "<<iterador_casilla->info.jugadores->cab->info.nombre<<"\t ubicacion: "<<jugador->info.ubicacion_tablero<<"\tposicion nueva: "<<posicion_nueva<<endl;
        //Comparar nombres 
        
        if(temp_nombre==iterador_casilla->info.jugadores->cab->info.nombre){
            //Eliminar el jugador de la lista de jugadores de la casilla
            
            eliminar(iterador_casilla->info.jugadores,0); //? cout<<"Eliminacion exitosa\n": cout<<"Problemas en eliminacio\n";
            if(dado == 6){
                jugador->info.contador++;
                if(jugador->info.contador==3){
                    posicion_nueva = 0;
                    jugador->info.penitencia = 1;
                    jugador->info.recta_final = 0;
                }
            }
            jugador->info.ubicacion_tablero = posicion_nueva;
            
            iterador_casilla = tablero->cab;
            //Encontrar la nueva casilla donde va a estar el jugador
            for(int j=0;j<posicion_nueva;j++){
                iterador_casilla = iterador_casilla->sig;
            }
            //Verificar serpierte o escalera en la casilla que cayo el jugador
            if(iterador_casilla->info.cambio!=0){
                iterador_casilla->info.tipo>0 ? cout<<"Aqui hay una escalera a "<<iterador_casilla->info.cambio+1<<endl : cout<<"Aqui hay una serpiente a "<<iterador_casilla->info.cambio<<endl;
                jugador->info.ubicacion_tablero = iterador_casilla->info.cambio;
                int temp = iterador_casilla->info.cambio;
                iterador_casilla = tablero->cab;
                for(int k=0;k<temp;k++){
                    iterador_casilla = iterador_casilla->sig;
                }
                
                
                //cout<<"Ubicacion con cambio: "<<jugador->info.ubicacion_tablero<<endl;
            }
            
            //Obtener el nombre para agregar a la nueva casilla
            JUGADOR temp_jugador;
            temp_jugador = obtenerDato(jugadores_global,x);
            //cout<<"temp_jugador: "<<temp_jugador.nombre<<" x:"<<x<<endl;
            
            insertar(iterador_casilla->info.jugadores,temp_jugador);
        }
        //Condicion para bandera de recta final
        if(jugador->info.ubicacion_tablero>=(tamaño-7)){
            jugador->info.recta_final = 1;
        }
        //Solo cambiar el jugador cuando no sea 6 o la penitencia sea 1
        if(dado!=6 || jugador->info.penitencia == 1){
            x++;
            jugador = jugador->sig;
        }
        
    }
}



int main(){
    //Inicializar srand con el tiempo para que los numero sean aletorios
    srand(time(NULL));
    int option=1;
    int flag=0;
    int tamaño = 25;
    int cantidad = 6;
    cout<<"\t\tESCALERAS Y SERPIENTES\n"<<endl;
    cout<<"Autor:Mauricio David Cuello Alzate\n\n"<<endl;
    while(option!=0){
        cout<<"[1] Iniciar el juego\n";
        cout<<"[2] Configuraciones\n";
        cout<<"[3] Instrucciones\n";
        cout<<"[0] Salir\n";
        cout<<"-----------------------------------------------\n";
        cin>>option;
        
        if(option == 0){
            cout<<"Adios , gracias por jugar :)"<<endl;
            cout<<"-----------------------------------------------\n";
            }   
        else if(option == 1){
            cout<<"Instrucciones basicas:\n \tSe debe elegir una letra para cada jugador (preferible mayuscula), esta letra \n\n";
            cout<<"\tsera el equivalente a la ficha con la que va a jugar el tablero cada jugador. El simbolo '@' representara una serpiente\n";
            cout<<"\ty el simbolo '$' representara una escalera\n";
            flag = 0;
            Lista <CASILLA> *tablero;
            tablero = crearLista<CASILLA>();
            generar(tablero,tamaño);
            escaleras_serpientes(tablero,tamaño,cantidad);
            imprimir_tablero(tablero,tamaño);
            Lista <JUGADOR> *jugadores_global= crearLista<JUGADOR>();
            agregar_jugadores(jugadores_global);
            posicionar_jugadores(tablero,jugadores_global);
            imprimir_tablero(tablero,tamaño);
            while(flag==0){
                mecanica_juego(tablero,jugadores_global,&flag,tamaño); 
                
            }
            delete(tablero);
            delete(jugadores_global);
            cout<<"-----------------------------------------------\n";
        }
        else if (option == 2){
            int config = 0;
            cout<<"[1] Cambiar tamaño de tablero\n";
            cout<<"[2] Cambiar cantidad de cambios(escaleras o serpientes)\n";
            cout<<"[3] Instrucciones completas\n";
            cout<<"[0] Salir\n";
            cout<<"-----------------------------------------------\n";
            cin>>config;
            if(config == 1){
                cout<<"Para que el juego se desarrolle de manera optima lo mejor\nes usar un tamaño cuya raiz sea entera para que el \ntablero sea cuadrado\n";
                cout<<"Nuevo tamaño: "<<endl;
                cin>>tamaño;
            }
            else if(config == 2){
                cout<<"El programa acomodará los cambios de manera aleatoria, asi como la proporcion de escaleras y serpientes sera aleatoria.\n";
                cout<<"El numero ingresado solo cambiara la cantidad de escaleras y serpientes que hay. \n";
                cout<<"Cantidad: ";
                cin>>cantidad;
            }
            cout<<"-----------------------------------------------\n";
            
        }
        else if (option == 3){
            cout<<"INSTRUCCIONES:\n";
            cout<<"Los jugadores comienzan con una ficha que representa a cada uno de ellos (letra) \nen el casillero inicial y se turnan para lanzar el dado. Las fichas se mueven según \nla numeración del tablero, en sentido ascendente. Si al finalizar un movimiento un\njugador cae en un casillero en donde comienza una escalera representado por el simbolo '$', sube por\nella hasta el casillero donde ésta termina. Si, por el contrario, cae en uno en donde comienza la \ncola de una serpiente representado por el simbolo '@', desciende por ésta hasta el casillero\ndonde finaliza su cabeza.";
            cout<<"Si un jugador obtiene un 6 podrá mover dos veces en un solo turno. Si un jugador \nobtiene tres 6 consecutivos, deberá regresar al casillero inicial y no podrá mover su \nficha hasta obtener nuevamente un 6. El jugador que logra llegar al casillero final\n es el ganador.\n";
            cout<<"Existe una condicion en la que el jugador, estando a seis o menos casilleros del \nfinal, debe obtener exactamente el número que le falta para llegar a éste, de otro modo \nseguira el siguiente jugador.\n\n";
            
        }
    }
}