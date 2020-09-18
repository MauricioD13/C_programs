#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PERSONA
{   
    int ID;
    char *cedula;
    char *nombre;
    char *apellido;
    int edad;
    int size;
    int *IDs;
    
};

void introduce(struct PERSONA *persona,int cont){
    if(cont==0){
        persona->ID=cont;
        persona->nombre="David";
        persona->apellido="Cuello";
        persona->cedula="000";
        persona->edad=20;
    }else{
        persona->ID=cont;
        persona->nombre="Mauricio";
        persona->apellido="Diaz";
        persona->cedula="001";
        persona->edad=20;
    }
}
void print_persona(struct PERSONA *persona){
    printf("Persona:\t%d\nNombre:\t %s\nApellido: %s\nCedula:\t %s\nEdad:\t %d\n",persona->ID,persona->nombre,persona->apellido,persona->cedula,persona->edad);
}   

void search(char* person_list,char* person_to_append,struct PERSONA **cluster,int cont){
    
    for(int i=0;i<cont;i++){
        if(!strcmp((*(cluster+i))->cedula,person_list)){
            (*(cluster+i))->*IDs=1;
            printf("lo encontre\n");
        }
    }
    
}

int main(){
    int option=0;
    int cont=0;
    struct PERSONA **cluster=malloc(sizeof(struct PERSONA*));
    while(option!=5){
        printf("Opcion? ");
        scanf("%d",&option);
        if(option==1){
            struct PERSONA *persona=malloc(sizeof(struct PERSONA));
            introduce(persona,cont);
            *(cluster+cont)=persona;
            cont++;
        }
        if(option==2){
            for(int j=0;j<cont;j++){
                print_persona(*(cluster+j));
            }
        }
        if(option==3){
            //David amigo de daniel
            char *person_list=malloc(10*sizeof(char)); //cedula Persona a la que se va a agregar amigo a su lista de amigos
            char *person_to_append=malloc(10*sizeof(char)); //cedula Persona que se va a agregar 
            printf("Cedula de la persona a la que se le va a agregar el amigo: ");
            scanf("%s",person_list);
            printf("Person_list:%s\n",person_list);
            search(person_list,person_to_append,cluster,cont);
            //append_person(person);
        }
        printf("----------------------------\n");
    }
}