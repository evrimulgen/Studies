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


  if( argc !=2) {
    fprintf(stderr,"synatxe : ./mon_prog numeroPort \n");
    return -1;
  }

  int serveurSocket=socket(PF_INET,SOCK_STREAM,0);
  struct sockaddr_in rcv,sourceAddr;
  char valid,valid1,valid2;
  char messageRecieved[50];
  char* msg = "Serveur : Bonjour à toi client" ;
  socklen_t lenAddr=sizeof(struct sockaddr_in);
  int clientSocket;

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

  if(recv(clientSocket,messageRecieved,50,0) == -1)
    perror("Error ");
  else
    printf("%s \n",messageRecieved);

  printf("appuyer sur entrer pour répondre au client \n");
  scanf("%c",&valid2);
  if(send(clientSocket,msg,80,0) == -1)
    perror("Error ");
  else
    printf("sending message operation : success \n");

  close(serveurSocket);

  return 0;
}
