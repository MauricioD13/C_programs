#include <stdio.h>
#include <stdlib.h>

struct Date{
    int *day;
    int *month;
    int *year;
};
int main(){
    struct Date *first;
    first=(struct Date *)malloc(sizeof(struct Date));
    first->day=(int *)malloc(sizeof(int));
    first->month=(int *)malloc(sizeof(int));
    first->year=(int *)malloc(sizeof(int));
    *(first->day)=5;
    *(first->month)=12;
    *(first->year)=1998;
    printf("dia: %d, mes: %d, año: %d \n", *(first->day),*(first->month),*(first->year));
    printf("probando vim\n");
    free(first->day);
    free(first->month);
    free(first->year);
    free(first);
}
