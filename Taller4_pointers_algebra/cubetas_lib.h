#ifndef CUBETAS_LIB_H
#define CUBETAS_LIB_H

void sort(int **columns,int *numbers,int number,int N);

void print_matrix(int **matrix,int N);

void organized(int *numbers,int N,int **matrix);

void generate(int *vector,int N,int quantity);

#include "cubetas_lib.c"
#endif