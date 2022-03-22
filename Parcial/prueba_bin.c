#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Autor:Mauricio David Cuello Alzate
 *   Carrera: Ingenieria Electronica
 *   Compilador: gcc*/
void convertbinary(int **numbers,int cont){
		int total=0;
			for(int i=0;i<cont-1;i++){
						int decimal=(pow(2,i))* (*(*(numbers+i)));
								printf("Numero en la posicion %d convertido a decimal: %d\n",i,decimal);
										total+=decimal;
											}
				printf("Resultado:%d\n",total);

}

int main(){
		
		int cont=0;
			int number=0;
				
				int **numbers=malloc(sizeof(int*));
					while(number!=9){
								printf("Numero:");
										scanf("%d",&number);	
												int *x=malloc(sizeof(int));
														*x=number;
																*(numbers+cont)=x;
																		cont++;
																				
																			}

						convertbinary(numbers,cont);
}	
