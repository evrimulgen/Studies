#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>

//SOCK_DGRAM pour le protocol UDP
//SOCK_STREAM pour le protocol TCP

int main(int argc,char** argv)
{

  if( argc !=3) {
    fprintf(stderr,"synatxe : ./mon_prog adresse numeroPort \n");
    return -1;
  }

  
  int clientSocket;
  char* msg=malloc(100*sizeof(char));
  int compteur=0,len=0;
  struct sockaddr_in serv;
  socklen_t servLen = sizeof(struct sockaddr_in);
  char valid,valid1;

  clientSocket=socket(PF_INET,SOCK_STREAM,0);
    
  if(clientSocket == -1 )
    perror("Error ");
  else
    printf("socket created ! \n");


  serv.sin_family = AF_INET;
  inet_pton(AF_INET,argv[1],&(serv.sin_addr));
  serv.sin_port=htons(atoi(argv[2]));
  

  printf("appuyer sur entrer pour envoyé une dmande de connexion à l'adresse %u",serv.sin_addr.s_addr);
  scanf("%c",&valid);
  if(connect(clientSocket,(struct sockaddr *)&serv,servLen) == -1 )
    perror("Error ");
  else
    printf("connection succeed ! \n");

  
  while(1){
  
    printf("appuyer sur 1 pour contacter le serveur sinon appuyer sur 0\n");
    scanf("%c",&valid1);
  
    if(valid1 == '1'){
      printf("saisissez le message \n");
      scanf("%s",msg);
      printf("longueur chaîne de caractères : %lu \n",strlen(msg));
      while(compteur < strlen(msg)){
	if((len=(send(clientSocket,msg+compteur,strlen(msg+compteur),0))) != -1){
	  compteur += len;
	}
	else{
	  perror("Error ");
	}

      }
      printf("sending message operation success \n");
      printf("nombre total d'octets envoyés (réel) : %lu \n",strlen(msg));
    }
    else if(valid1 == '0'){
      printf("vous êtes en mode reception \n");
      char res[strlen(msg)];

      if(recv(clientSocket,&res,sizeof(res),0) == -1)
	perror("Error ");
      else
	printf("%s \n",res);
    }
  }
  
  
  close(clientSocket);

  return 0;
}
