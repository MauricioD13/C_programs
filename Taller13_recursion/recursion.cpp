#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*  Autor: Mauricio David Cuello Alzate
    Carrera: Ing. Electronica
    Compilador: gcc en terminal
*/

int suma(int numbers[5],int cont){
    cont--;
    if(cont<0){
        return 0;
    }
    printf("numbers[cont]: %d \n",numbers[cont]);
    return numbers[cont] + suma(numbers,cont);
}

char* conversor(int decimal,int conversion,int cont){
    //char *letras[6]={"A","B","C","E","D","F"};
    char *result;
    if(conversion==16 && decimal>16){
        int power = pow(conversion,cont);
    }
    if(conversion==8 && decimal>8){
        int power = pow(conversion,cont);

    }

    return strcat(conversor(decimal,conversion,cont),result);
}

char verificador(int number,int digits,int cont1,int cont2){
    int power = pow(10,cont1);
    int result = number/power;
    //printf("numero:%d ,result:%d, cont1:%d, cont2:%d\n",number,result,cont1,cont2);
    if(cont1==0){
        if(number%cont2==0){
            return 'T';
        }
        else{
            return 'F';
        }
    }
    
    
    if(result%cont2==0){
        cont2++;
        cont1--;
        
        return verificador(number,digits,cont1,cont2);
    }
    else{
        return 'F';
    }
    
}
int main(){
    int option;
    printf("¿Opcion?\n");
    scanf("%d",&option);
    if(option==1){
        int numbers[5]={1,2,3,4,5};
        int cont=5;
        int result;
        printf("Suma:%d\n",suma(numbers,cont));
    }
    else if(option==2){
        int decimal = 16;
        int cont = 0;

    }
    else if(option==3){
        printf("Número a verificar:");
        int number;
        scanf("%d",&number);
        printf("Cantidad de digitos:");
        int digits;
        scanf("%d",&digits);
        int cont1 = digits-1;
        int cont2 = 1;
        char result=verificador(number,digits,cont1,cont2);
        result=='T'? printf("El numero cumple con la condicion\n") : printf("El numero no cumple con la condicion\n");
    }
}