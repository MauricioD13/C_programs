#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct MAIL{
	char *message;
	char *from;
	char *to;
};

struct INBOX{
	char *address;
	int received;
	int sended;
	struct MAIL *sended_mails;
	struct MAIL *received_mails;	
};	


void print_inbox(struct INBOX *inbox){
	printf(" Address: %s\n received: %d\n sended: %d\n",inbox->address,inbox->received,inbox->sended);	
}

int search(struct INBOX **inboxes,char *to){
	int i=0;
	while((*(inboxes+i))!=NULL){
		if(!strcmp((*(inboxes+i))->address,to)){
			printf("LO ENCONTRE\n");
			return i;
		}
	i++;
	}

}

int new_inbox(struct INBOX **inboxes,char *address,int cont){
	struct INBOX *inbox=malloc(sizeof(struct INBOX));
	inbox->address=address;
	print_inbox(inbox);
	*(inboxes+cont)=inbox;	
	cont++;
	return cont;
}

void mail_search(struct INBOX **inboxes,char* word){
	int i=0;
	printf("inboxes+i: %s\n",(*(inboxes+1))->address);
	while((*(inboxes+i))!=NULL){
		printf("Dentro del primer while\n");
		for(int j=0;j<(*(inboxes+i))->sended;j++){
			printf("Message: %s\n",(((*(inboxes+i))->sended_mails)+j)->message);
		
		}
	i++;
	}
}
void onemail(struct MAIL *mail){
	printf("message: %s\n",mail->message);
}

int main(){
	
	int option;
	int cont=0;
	int position=0;
	struct INBOX **inboxes=malloc(10*sizeof(struct INBOX*));//Maximo 10 inboxes
	while(option!=5){
		printf("Opcion?: \n");
		scanf("%d",&option);
		if(option==1){//Crear INBOX
			char *address="mauricio@pc.com";
			cont=new_inbox(inboxes,address,cont);
			char*address1="mariana@pc.com";
			cont=new_inbox(inboxes,address1,cont);
	}
		if(option==2){//Enviar correo
			struct MAIL *mail=malloc(sizeof(struct MAIL));
			char *message="Hola Mundo mucho gusto";
			char *from="mauricio@pc.com";
			char *to="mariana@pc.com";
			mail->message=message;
			mail->from=from;
			mail->to=to;
			position=search(inboxes,to);
			
				(*(inboxes+position))->sended_mails=mail;
				//printf("message:%s\n",((*(inboxes+position))->sended_mails)->message);
				(*(inboxes+position))->sended+=1;
				print_inbox(*(inboxes+position));
				position=search(inboxes,from);
				((*(inboxes+position))->received_mails)=mail;
				(*(inboxes+position))->received+=1;
				print_inbox(*(inboxes+position));
		}
		if(option==3){//Buscar en los mensajes
			char *word="Hola";
			
			mail_search(inboxes,word);

		}

		
		
	}
	
	
	}
	
