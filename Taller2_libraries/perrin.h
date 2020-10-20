#ifndef PERRIN_H
#define PERRIN_H

int *perrin_series(int number); 
int **perrin_primes(int *perrin_array,int number,int *cont);
void deleter(int **perrin_pointers, int number,int *cont);

#include "perrin.c"
#endif