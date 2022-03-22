#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

typedef struct IMPRESORA{
    int estado;
    int trabajos_pendientes;
}IMPRESORA;


void mostrar_impresoras(IMPRESORA *impresoras){

    for(int i=0;i<5;i++){

        cout<<"Impresora "<<i<<"\tEstado: ";
        ((impresoras+i)->estado == 0) ? cout<<"apagado\t":cout<<"encendido";
        cout<<"\tTrabajos pendientes: "<<(impresoras+i)->trabajos_pendientes<<endl;
    }
}
int menu(){
    int option;
    cout<<"Opciones: \n";
    cout<<"\t[1] Cambiar estado de impresora\n";
    cout<<"\t[2] Agregar pedido de copias\n";
    cout<<"\t[0] Salir\n";
    cin>>option;
    return option;
}
void asignador(IMPRESORA *impresoras,queue <int> *cola_impresiones,const int limite){
    int min;
    int index;
    int copias;
    while(!cola_impresiones->empty()){
        int k=0;
        while(1){
            if((impresoras+k)->estado != 0){
                  min = (impresoras + k)->trabajos_pendientes;
                  index = k;
                   break;
            }
            k++;
        }

       for(int i=0;i<5;i++){
           if(((impresoras+i)->trabajos_pendientes == 0)&&((impresoras+i)->estado!=0)){
               index = i;
               break;
           }else if(((impresoras+i)->trabajos_pendientes <= min)&&(i!=0)&&((impresoras+i)->estado!=0))
           {
               index = i;
               min = (impresoras+i)->trabajos_pendientes;
           }

       }
        if(((impresoras+index)->trabajos_pendientes+cola_impresiones->front()) <= limite){
            (impresoras+index)->trabajos_pendientes += cola_impresiones->front();
            cola_impresiones->pop();
        }else{
            cout<<"Bloque de "<<cola_impresiones->front()<<" trabajos en cola han sido descartados"<<endl;
            cola_impresiones->pop();
        }
    }
}

void redistribucion(IMPRESORA *impresoras,const int limite){
        int cambio;
        cout<<"Cual impresora desea cambiar?"<<endl;
        cin>>cambio;
        //Funcion de distribucion
        int min,max;
        int index;
        int trabajos;
        if((impresoras+cambio)->estado!=0){
            trabajos = (impresoras+cambio)->trabajos_pendientes;
            (impresoras+cambio)->estado = 0;
            (impresoras+cambio)->trabajos_pendientes = 0;
            cout<<"[Redistribuyendo trabajos...]"<<endl;
            cout<<"----------------------------------------\n";
            while(trabajos!=0){
                int k=0;
                while(1){
                    if((impresoras+k)->estado != 0){
                        min = (impresoras + k)->trabajos_pendientes;
                        index = k;
                        break;
                    }
                    k++;
                }

                for(int i=0;i<5;i++){
                    if(((impresoras+i)->trabajos_pendientes == 0)&&(i!=cambio)&&((impresoras+i)->estado!=0)){
                        index = i;
                        break;
                    }else if(((impresoras+i)->trabajos_pendientes <= min)&&(i!=0)&&(i!=cambio)&&((impresoras+i)->estado!=0))
                    {

                        index = i;
                        min = (impresoras+i)->trabajos_pendientes;
                    }

                }
                if((((impresoras+index)->trabajos_pendientes)+1)<=limite){
                    (impresoras+index)->trabajos_pendientes +=1;
                    trabajos--;
                }else{
                    cout<<"Se han descartado "<<trabajos<<" en la redistribucion"<<endl;
                    trabajos = 0;
                }

            }
        }else{
                int k=0;
                while((impresoras+k)->estado==0){
                    min = (impresoras+k)->trabajos_pendientes;
                    index = k;
                }
                if(k==0){
                    min = (impresoras)->trabajos_pendientes;
                    index = 0;
                }
                cout<<"minimo: "<<min<<endl;

                for(int i=0;i<5;i++){
                    if(((impresoras+i)->trabajos_pendientes == 0)&&(i!=cambio)&&((impresoras+i)->estado!=0)){
                        break;
                    }else if(((impresoras+i)->trabajos_pendientes <= min)&&(i!=0)&&(i!=cambio)&&((impresoras+i)->estado!=0))
                    {
                        min = (impresoras+i)->trabajos_pendientes;
                    }

                }
                cout<<"minimo: "<<min<<endl;
                while(min>(impresoras+cambio)->trabajos_pendientes){
                    max = (impresoras)->trabajos_pendientes;
                    index = 0;
                    for(int i=0;i<5;i++){
                        if(((impresoras+i)->trabajos_pendientes == 0)&&(i!=cambio)&&((impresoras+i)->estado!=0)){
                            index = i;
                            break;
                        }else if(((impresoras+i)->trabajos_pendientes >= max)&&(i!=0)&&(i!=cambio)&&((impresoras+i)->estado!=0))
                        {
                            index = i;
                            max = (impresoras+i)->trabajos_pendientes;
                        }

                    }
                    (impresoras+index)->trabajos_pendientes -=1;
                    (impresoras+cambio)->trabajos_pendientes +=1;
                }
                (impresoras+cambio)->estado = 1;
        }
}

int main(){
    queue <int> cola_impresiones;
    int option=0;
    int numero;

    IMPRESORA *impresoras = new IMPRESORA[5];
    for(int i=0;i<5;i++){
        IMPRESORA impresora;
        impresora.trabajos_pendientes = 0;
        impresora.estado = 1;
        *(impresoras + i) = impresora;
    }
    for(int j=0;j<7;j++){
        numero = rand()%10;
        cout<<"Cola "<<j<<" :\t"<<numero<<endl;
        cola_impresiones.push(numero);
    }
    const int limite_trabajos=15;
    cout<<"----------------------------------------\n";

    asignador(impresoras,&cola_impresiones,limite_trabajos);
    cout<<"----------------------------------------"<<endl;


    mostrar_impresoras(impresoras);

    //option = menu();
    option = 1;

    while(option!=0){
    cout<<"----------------------------------------\n";
    option = menu();
    switch(option){
        case 1:
            redistribucion(impresoras,limite_trabajos);
            mostrar_impresoras(impresoras);
            break;
        case 2:
            int j=1;
            while(j==1){
                cout<<"Valor: "<<endl;
                cin>>numero;
                cola_impresiones.push(numero);
                cout<<"Desea agregar otro valor?"<<endl;
                cout<<"[1] Si [2] No"<<endl;
                cin>>j;
            }
            mostrar_impresoras(impresoras);
            asignador(impresoras,&cola_impresiones,limite_trabajos);
            cout<<"----------------------------------------\n";
            mostrar_impresoras(impresoras);




        }

    }
}
