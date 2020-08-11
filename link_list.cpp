#include <stdio.h>
#include <iostream>

using namespace std;
struct Dato{
    int num;
    struct Dato *link;
};
Dato *createNODE(int number){
    Dato *start;
    start=(Dato *)malloc(sizeof(Dato));
    start->link=NULL;
    start->num=number;
    return start;
}

int main(){
    Dato *start=NULL;
    int repeat=1;
    while(repeat){
        int number=0;
        cout<<"Nuevo numero?: ";
        cin>>number;
        if(!start && number){
            
        }
        cout<<"Desea otro numero";
        cin>>repeat;
    }
    
    
    
}