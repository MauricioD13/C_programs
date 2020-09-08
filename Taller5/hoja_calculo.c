#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(char ***matrix){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%s\t\t",*(*(matrix+j)+i));       
        }
        printf("\n");
    }
}

void generate_matrix(char ***matrix){
    for(int i=0;i<5;i++){
        char **row=malloc(5*sizeof(char*));
        *(matrix+i)=row;
    }
}

int main(){
    //char dicc[]={"A","B","C"};
    char entry[200];
    
    char *p;
    char *q;
    char *z;
    char *copy;
    
    char ***matrix=malloc(5*sizeof(entry));
    //*(*(matrix+columna)+fila)
    generate_matrix(matrix);
    **matrix="10";
    *(*matrix+1)="40";
    *(*(matrix+1))="34";
    *(*(matrix+1)+1)="17";
    *(*(matrix+2)+0)="37";
    *(*(matrix+0)+1)="40";
    *(*(matrix+2)+1)="34";
    *(*(matrix+0)+2)="=A1 + A2";
    *(*(matrix+1)+2)="=B1 + B2";
    *(*(matrix+2)+2)="=C1 + 8 + C2";
    *(*(matrix+3)+0)="=A1 + B1 + C1";
    *(*(matrix+3)+1)="=A2 + B2 + C2";
    print_matrix(matrix);
    strcpy(copy,*(*(matrix+0)+2));
    p=strtok(copy,"=");
    p=strtok(p,"+");
    printf("p: %s \n",p);
    q=strtok(NULL,"+");
    printf("q: %s \n",q);
    z=strtok(q," ");
    printf("z: %s \n",z);
    if(z-1=="A"){
        printf("SON IGUALES");
    }
    


    
}