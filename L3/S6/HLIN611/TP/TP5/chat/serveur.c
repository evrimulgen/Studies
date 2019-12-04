#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#define Max_client 10

int main(int argc,char** argv)
{
  struct sockaddr_in rcv;
  char valid,valid1;
  fd_set set, settmp ;
  int max,serveurSocket,clientSocket,sizeMsg;
  int clients[Max_client];
  int clientCompteur=0;
    
  if( argc != 2) {
    fprintf(stderr,"synatxe : ./mon_prog numeroPort  \n");
    return -1;
  }

  serveurSocket=socket(PF_INET,SOCK_STREAM,0);
  rcv.sin_family = AF_INET;
  rcv.sin_addr.s_addr = INADDR_ANY;
  rcv.sin_port = htons(atoi(argv[1]));

  if(bind(serveurSocket,(struct sockaddr *)&rcv,sizeof(rcv)) == -1 )
    //printf("naming socket opreation : failed \n");
    perror("Error ");
  else
    printf("naming socket opreation : success \n");

  printf("appuyer sur entrer pour mettre la socket en mode écoute \n");
  scanf("%c",&valid);

  if(listen(serveurSocket,5) == -1)
    perror("Error ");
  else
    printf("listen mode succeed \n");

  FD_ZERO(&set) ;  //creation de la table des descripteurs
  FD_SET(serveurSocket,&set); //ajout du descripteur de la socket mais l'indice corespondant à 1 prêt 
  max=serveurSocket;

  printf("attente des connexions clientes (max 10 clients) \n");
  scanf("%c",&valid1);
  
  while(1){

    settmp = set ;
    select(max+1, &settmp, NULL, NULL, NULL) ;

    for(int df= 2 ; df <= max ; df++){

      if ( !FD_ISSET(df, &settmp)) continue ;

      if (df == serveurSocket) {
        clientSocket= accept(serveurSocket, NULL, NULL) ;
	clients[clientCompteur]=clientSocket;
	clientCompteur++;
	FD_SET(clientSocket, &set) ;
	if (max < clientSocket) max = clientSocket;
	continue ;
      }

      printf("nombre de client : %d \n",clientCompteur);
      printf("saissisze le nombre d'octets envoyés par le dernier client ! \n");

      scanf("%d",&sizeMsg);
      char msgRcv[sizeMsg];
      if (recv(df,&msgRcv,sizeof(msgRcv),0) <= 0) {
	FD_CLR(df, &set) ;                          
	close(df) ; continue ;
      }

      for(int i=0;i<clientCompteur;i++){
	char msgSend[sizeMsg];
	strcpy(msgSend,msgRcv);
	printf("le message à envoyer %s \n",msgSend);
	if(send(clients[i],&msgSend,sizeof(msgSend),0) != -1)
	  printf("message sent to client %d  \n",i);
	else
	  perror("Error ");
      }      
    }
  }

  return 0;
}
