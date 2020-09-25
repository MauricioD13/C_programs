#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Autor:Mauricio David Cuello Alzate
  Carrera: Ingenieria Electronica
Compilador: gcc*/
struct VALIDACION{
	char *palabra;
	char *flag;
};

void print_vals(struct VALIDACION **storage,int cont){
	for(int j=0;j<cont;j++){
		printf("Palabra: %s\t Validacion: %s\n",(*(storage+j))->palabra,(*(storage+j))->flag);
	}
}
void finder(struct VALIDACION **storage,int cont,int *list){
	for(int i=0;i<cont;i++){
		char *temp=(*(storage+i))->palabra;
		for(int j=0;j<cont;j++){
		if(!strcmp(temp,(*(storage+j))->palabra)){
			*(list+j)=j;	
		}
		
	}
}
}
int main(){
	char *frase=malloc(120*sizeof(char));
	printf("FRASE?");
	gets(frase);
	printf("FRASE:%s\n",frase);
	char **diccionario=malloc(120*sizeof(char));
	char *token=malloc(sizeof(frase));
	char *copy=malloc(sizeof(frase));
	*(diccionario+0)="EN";
	*(diccionario+1)="CASA";
	*(diccionario+2)="LOLA";
	*(diccionario+3)="LOS";
	int len_diccionario=4;
	strcpy(copy,frase);
	//printf("COPIA:%s\n",copy);
	token=strtok(copy," ");
	struct VALIDACION **storage=malloc(sizeof(struct VALIDACION*));
	int cont=0;
	while(token!=NULL){
		int mark=0;
		struct VALIDACION *val=malloc(sizeof(struct VALIDACION));
		

		for(int i=0;i<len_diccionario;i++){
			if(!strcmp(token,*(diccionario+i))){
				
				
					//printf("Esta: %s\n",token);
					char *temp=malloc(sizeof(token));
					strcpy(temp,token);
					val->palabra=temp;
					val->flag="ESTA";
					*(storage+cont)=val;	
					mark=1;
				
			}
		}
		if(mark==0){
			//printf("No esta: %s\n",token);
			val->palabra=token;
			val->flag="NOESTA";
			*(storage+cont)=val;	
		}
		token=strtok(NULL," ");
		cont+=1;
	}
	print_vals(storage,cont);
	int *list=malloc(cont*sizeof(int));
	finder(storage,cont,list);
	printf("PALABRAS:\t");
	for(int p=0;p<cont;p++){
		printf("%s\t",(*(storage+p))->palabra);
	}
	printf("\nCANTIDAD:\t");
	for(int k=0;k<cont;k++){
		printf("%d\t",*(list+k));	
	}
	printf("\n");
	/*Profe al final me di cuenta que no era la cantidad de veces que estaba la palabra sino la posicion y no me dio tiempo de cambiarlo :( */
}
