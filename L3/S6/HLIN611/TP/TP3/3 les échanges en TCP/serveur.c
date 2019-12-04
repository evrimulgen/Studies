#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>


int main(int argc,char** argv)
{


  if( argc != 4) {
    fprintf(stderr,"synatxe : ./mon_prog numeroPort  nombreIétrations tailleMessage \n");
    return -1;
  }

 
  struct sockaddr_in rcv,sourceAddr;
  char* msg = "Serveur : Bonjour à toi client" ;
  socklen_t lenAddr=sizeof(struct sockaddr_in);
  char valid,valid1,valid2,valid3;
  ssize_t len=0;
  int clientSocket,nbIterations=0,compteur=0,tailleMsg=atoi(argv[3]),serveurSocket;
  char* msgRecieved=malloc(tailleMsg*sizeof(char)+1);
  
    
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
  if(listen(serveurSocket,10) == -1)
    perror("Error ");
  else
    printf("listen mode succeed \n");
  
  printf("appuyer sur entrer pour accepter une connexion \n");
  scanf("%c",&valid1);


  clientSocket= accept(serveurSocket,(struct sockaddr *)&sourceAddr,&lenAddr);
  if(clientSocket == -1 )
    perror("Error ");
  else
    printf("connection request accepted ! \n");

  printf("appuyer sur entrer pour recevoir (mode reception) \n");
  scanf("%c",&valid2);

  while (  nbIterations < atoi(argv[2])  ){
    if((len=recv(clientSocket,msgRecieved+compteur,sizeof(msgRecieved),0)) != -1 ){
      compteur += len;
      nbIterations++;
    }else{
      perror("Error ");;
    }
  }

  printf("message received :  \n |  ");
  for(int i=0;i<tailleMsg;i++)
    printf("%c",msgRecieved[i]);
  printf(" |  \n ");

  printf("nombre total d'octets reçus (recv) : %i \n",compteur);

  printf("appuyer sur entrer pour répondre au client \n");
  scanf("%c",&valid3);
  if(send(clientSocket,msg,80,0) == -1)
    perror("Error ");
  else
    printf("sending message operation : success \n");

  close(serveurSocket);

  return 0;
}
