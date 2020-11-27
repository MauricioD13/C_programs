#include <iostream>
#include <string>
#include <math.h>
//Autor: Mauricio David Cuello Alzate
//Compilador: g++ en linux
using namespace std;

int first_col(int A,int temp,int *i){
    
   if(temp<A){
       
       (*i)+=1;
       return first_col(A,pow(2,*i),i);
   }
   else{
       return pow(2,(*i)-1);
   }
}

int result_col(int resultA,int resultB,int aux,int A,int B,int total){
    if(resultA==1){
        return total;
    }else{
        int t=0;
        int k=0;
        resultA = aux-resultA;
        aux = resultA;
        resultA = first_col(resultA,t,&k);
        k--;
        t=0;
        resultB =  resultA*B;
        total = total + resultB;
        cout<<resultB<<","<<resultA<<endl;
        return result_col(resultA,resultB,aux,A,B,total);
        
    }
}
int main(){
    int temp = 0;
    int i = 0;
    int A = 41;
    int B=59;
    int resultA;
    int resultB;
    int total;
    int aux = A;
    resultA = first_col(A,temp,&i);
    temp=0;
    i--;
    int j=0;
    resultB = resultA * B;
    cout<<resultA<<","<<resultB<<endl;
    total = resultB;
    total=result_col(resultA,resultB,aux,A,B,total);

    cout<<"Total:"<<total<<endl;

}