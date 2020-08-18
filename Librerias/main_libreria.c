#include <stdio.h>
#include "libreria.h"

int main(){
printf("La suma es: %d",suma(4,3));
}
/*NOTA: Se deben compilar en main_libreria.c y libreria.c
de esta manera el compilador sabe que libreria se esta llamando.
Comando: gcc main_libreria.c libreria.c -o main_libreria*/