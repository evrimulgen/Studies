#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>

struct reponse{
	long label;
	int resultat;
}typedef reponse;

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
	key_t sesame;

	if ((sesame = ftok("key.txt", '1')) == (key_t) -1) {
 		perror("IPC error: ftok"); exit(1);
	} 
	int   idIPC=msgget(sesame,IPC_CREAT);
	printf("idIPC : %d\n",idIPC);


	for(int i=0;i<4;i++){
		requete operation;
		msgrcv(idIPC,&operation,(size_t)sizeof(operation.myOp),(long)0,0);
		switch(operation.myOp.signO){
			case '+' :  
			case '-' :
			case '*' :
			case '/' :
		}
	}



	return 0;
}