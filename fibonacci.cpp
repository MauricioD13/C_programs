#include <iostream>
using namespace std;



int main(){
    int cantidad;
    cout<<"Cuantos numeros de fibonacci quiere?: ";
    cin>>cantidad;
    cout<<endl;
    int start=0;
    int current_number=1;
    int previus_number=0;
    int aux;
    int fibonacci[cantidad];
    for(int i=0;i<cantidad;i++){
        if(!i){
            cout<<previus_number<<"-> "<<i+1<<" numero de la serie de fibonacci"<<endl;
            fibonacci[i]=previus_number;
        }
        else if(i==1){
            cout<<current_number<<"->"<<i+1<<" numero de la serie de fibonacci"<<endl;
            fibonacci[i]=current_number;
        }
        else{
        aux=current_number;
        current_number+=previus_number;
        previus_number=aux;
        cout<<current_number<<"->"<<i+1<<" numero de la serie de fibonacci"<<endl;
        fibonacci[i]=current_number;
        }
    }
    for(int i=0;i<cantidad;i++){
        cout<<fibonacci[i]<<"/";
    }
}