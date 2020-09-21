#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PERSON
{   
    int ID;
    char *cedula;
    char *nombre;
    char *apellido;
    int edad;
    int size;
    int *IDs;
    
};

void introduce(struct PERSON *person,int cont){
    
    person->ID=cont;	
    char *nombre=malloc(10*sizeof(char));
    char *apellido=malloc(10*sizeof(char));
    char *cedula=malloc(10*sizeof(char));
    int edad;
    printf("Nombre: ");
    scanf("%s",nombre);
    printf("Apellido: ");
    scanf("%s",apellido);
    printf("Cedula: ");
    scanf("%s",cedula);
    printf("Edad: ");
    scanf("%d",&edad);
    person->nombre=nombre;
    person->apellido=apellido;
    person->cedula=cedula;
    person->edad=edad;

	/*if(cont==0){
        person->ID=cont;
        person->nombre="David";
        person->apellido="Cuello";
        person->cedula="000";
        person->edad=20;
    }else if(cont==1){
        person->ID=cont;
        person->nombre="Mauricio";
        person->apellido="Diaz";
        person->cedula="001";
        person->edad=20;
    }else{
    	
        person->ID=cont;
        person->nombre="Camila";
        person->apellido="Navarro";
        person->cedula="002";
        person->edad=19;
    } */ 
}
void print_person(struct PERSON *person){
	printf("-----------------------------\n");
	printf("\tPersona:\t%d\n\tNombre:\t %s\n\tApellido: %s\n\tCedula:\t %s\n\tEdad:\t %d\n",person->ID,person->nombre,person->apellido,person->cedula,person->edad);
}   

void append_friend(char* person_list,char* person_to_append,struct PERSON **cluster,int cont){
    for(int i=0;i<cont;i++){
    	int value=i;
        if(!strcmp((*(cluster+i))->cedula,person_list)){
		for(int j=0;j<cont;j++){
        		if(!strcmp((*(cluster+j))->cedula,person_to_append)){
				*(((*(cluster+i))->IDs)+(*(cluster+i))->size)=(*(cluster+j))->ID;
				(*(cluster+i))->size=((*(cluster+i))->size)+1;
			}	
		}
	}
    }
}
    
void print_friends(struct PERSON **cluster,int cont,char *person){
	for(int i=0;i<cont;i++){
        	if(!strcmp((*(cluster+i))->cedula,person)){
			printf("Lista de amigos de %s: \n",(*(cluster+i))->nombre);
			for(int j=0;j<(*(cluster+i))->size;j++){
				int number;
				number=*(((*(cluster+i))->IDs)+j);
				print_person(*(cluster+number));
			}

		}
	}
}
int main(){
    int option=0;
    int cont=0;
    struct PERSON **cluster=malloc(sizeof(struct PERSON*));
    while(option!=5){
	printf(" [1] Agregar una persona\n [2] Imprimir lista de personas \n [3] Agregar persona a una lista de amigos \n [4] Imprimir lista de amigos\n [5] Salir\n");
        printf("Opcion? ");
        scanf("%d",&option);
        if(option==1){
            struct PERSON *person=malloc(sizeof(struct PERSON));
            person->IDs=malloc(10*sizeof(int));
	    person->size=0;
	    introduce(person,cont);
            *(cluster+cont)=person;
            cont++;
        }
        if(option==2){
            for(int j=0;j<cont;j++){
                print_person(*(cluster+j));
            }
        }
        if(option==3){
            //David amigo de daniel
            char *person_list=malloc(10*sizeof(char)); //cedula Persona a la que se va a agregar amigo a su lista de amigos
            char *person_to_append=malloc(10*sizeof(char)); //cedula Persona que se va a agregar 
	    printf("Cedula de la persona a la que se le va a agregar el amigo: ");
            scanf("%s",person_list);
	    printf("Cedula del amigo que va a ser agregado: ");
	    scanf("%s",person_to_append);
            printf("Person_list:%s\n",person_list);
            append_friend(person_list,person_to_append,cluster,cont);
            printf("Amigo:%d,size:%d\n",*((*(cluster))->IDs),(*(cluster))->size);

        }
	if(option==4){
		char *person=malloc(10*sizeof(char));
		printf("Cedula de la persona de la que desea ver su lista de amigos: ");
		scanf("%s",person);
		print_friends(cluster,cont,person);
	}

        printf("----------------------------\n");
    }
}
