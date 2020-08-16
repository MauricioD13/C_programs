#include <stdio.h>
#include <iostream>

using namespace std;
struct info{    
    int edad;
    char *nombre;
};   
void print_vector(info registro[5]){
        cout<<"-------IMPRIMIR REGISTRO------"<<endl;
        for(int i=0;i<5;i++){
            cout<<"Nombre:"<<registro[i].nombre<<endl;
            cout<<"Edad:"<<registro[i].edad<<endl;
        }
}
int main(){
    int cont=2;
    struct info registro[5];
    for(int i=0;i<2;i++){
        // Tener en cuenta que no se puede referenciar un variable dentro de la estructura directamente dentro de cin
        char *nombre;
        int edad;
        cout<<"Nombre de la persona a agregar:";
        cin>>nombre;
        cout<<"Edad de la persona:";
        cin>>edad;
        registro[i].nombre=nombre;
        registro[i].edad=edad; 
    }
    print_vector(registro);

}