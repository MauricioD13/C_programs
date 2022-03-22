#include <stack>
#include <queue>
#include <iostream>

using namespace std;



void evaluador(char prueba[]){
    char inicio[4]="([{";
    char final[4]=")]}";
    stack <int> pila;
    int i=0;
    while(prueba[i]!='\0'){
       
        for(int j=0;j<3;j++){
            if (prueba[i]==inicio[j]){
                pila.push(prueba[i]);
            }
            else if((prueba[i] == final[j]) ){
                if(!pila.empty()){
                    if(pila.top()==inicio[j]){
                        pila.pop();
                    }
                    else{
                        pila.push(prueba[i]);
                    }
                }
                else{
                    pila.push(prueba[i]);
                }
            }
        }
        i++;
    }
    if(pila.empty()){
        printf("Ecuacion balanceda\n");
    }
    else
    {
        printf("No esta balanceda\n");
    }
}


int main(){
    
    int opcion=0;
    char *prueba = new char[20];
    while(opcion!=3){
        cout<<"\tPrueba de ecuaciones"<<endl;
        cout<<"Opciones:"<<endl;
        cout<<"\t[1] Leer archivo de texto y evaluar ecuaciones"<<endl;
        cout<<"\t[2] Introducir ecuacion mediante terminal"<<endl;
        cout<<"\t[3] Salir"<<endl;
        cin>>opcion;
        if(opcion == 1){
            FILE *ecuaciones;
            ecuaciones = fopen("ecuaciones.txt","r");
            while(feof(ecuaciones)==0){
                
                fgets(prueba,100,ecuaciones);
                cout<<"La ecuacion es: "<<prueba<<endl;;
                evaluador(prueba);
            }
        }
        else if(opcion == 2){
            cout<<"Escribir ecuacion: ";
            cin>>prueba;
            evaluador(prueba);
        }
        cout<<"------------------------------------------------------------"<<endl;
    }

}