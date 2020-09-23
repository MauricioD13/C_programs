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




int main(){
	
	int option=0;
	struct INBOX **inboxes=malloc(10*sizeof(struct INBOX*));//Maximo 10 inboxes
	if(option==0){//Crear INBOX
		char *address="mauricio@pc.com";
		struct INBOX *inbox=malloc(sizeof(struct INBOX));
		inbox->address=address;
		print_inbox(inbox);
		
	}
	if(option==1){//Enviar correo
		struct MAIL *mail=malloc(sizeof(struct MAIL));
		char *message="Hola Mundo mucho gusto";
		char *from="mauricio@pc.com"
		char *to="mariana@pc.com"
		mail->message=message;
		mail->from=from;
		mail->to=to;

		
		
	}
	
	


}	
