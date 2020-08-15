void sort(int **pointers,int *quantity){
    int *aux=NULL;
    printf("%d",*quantity);
    for(int i=0;i<(*quantity)-1;i++){
        for(int j=0;j<(*quantity-1);j++){
            if(*(*pointers+j)>*(*pointers+j+1)){
                aux=(*pointers+j);
                *(pointers+j)=*(pointers+j+1);
                *(pointers+j+1)=aux;
            }
        }
    }
}

void sort(int *pointers,int *quantity){
    int *aux=NULL;
    printf("--------------\n");
    for(int i=0;i<*quantity;i++){
        printf("valores del vector %d, su apuntador %p\n",*pointers+i,pointers+i);
    }
       
}


Intento numero 2


void sort(int *pointers,int *quantity){
    int *aux=NULL;
    printf("%d",*quantity);
    for(int i=0;i<(*quantity)-1;i++){
        for(int j=0;j<(*quantity-1);j++){
            if((*pointers+j)>(*pointers+j+1)){
                aux=(pointers+j);
                pointers+j=pointers+j+1;
                pointers+j+1=aux;
            }
        }
    }
}
int *pointers=(int *)malloc(*quantity);
    for(int i=0;i<*quantity;i++){
        *(pointers+i)=vector+i;
    }