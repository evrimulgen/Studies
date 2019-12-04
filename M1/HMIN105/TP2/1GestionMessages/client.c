#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>

struct operation{
	int operand1;
	int operand2;
	char signO;
}typedef opreation;

struct requete{
	long label;
	operation myOp;
}typedef requete;



int main(int argc, char const *argv[])
{	
	int x,y;
	char op;

	key_t sesame;

	if ((sesame = ftok("key.txt", '1')) == (key_t) -1) {
 		perror("IPC error: ftok"); exit(1);
	} 
	 
	int   idIPC=msgget(sesame,IPC_CREAT);
	printf("idIPC : %d\n",idIPC);

	printf("on va procedé à 4 opréation arithmétiques \n")

	for(int i=0;i<4;i++){
		requete* myMsg =malloc(sizeof(structmsg));
		printf("1 er operande : %d");
		scanf("%d",&x);
		printf("2 eme operande : %d");
		scanf("%d",&y);
		printf("choissisez l'un des carctères suivants : '+' '-' '*' '/' \n");
		scanf("%c",&op);
		myMsg->label=i;
		myMsg->myOp->operand1=x;
		myMsg->myOp->operand2=y;
		myMsg->myOp->signO=op;
		if(msgsnd(idIPC,&myMsg,sizeof(struct requete),msgflg)==-1){
			perror(" ");
			return -1;
		}else{
			printf("message sent !\n");	
		}
	}
	
	return 0;
}