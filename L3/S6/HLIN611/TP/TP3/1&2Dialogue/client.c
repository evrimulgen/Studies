#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

//SOCK_DGRAM pour le protocol UDP
//SOCK_STREAM pour le protocol TCP

int main(int argc,char** argv)
{

  if( argc !=3) {
    fprintf(stderr,"synatxe : ./mon_prog adresse numeroPort \n");
    return -1;
  }
  
  int clientSocket=socket(PF_INET,SOCK_STREAM,0);
  struct sockaddr_in serv;
  socklen_t servLen = sizeof(struct sockaddr_in);
  char valid,valid1;
  char* msg = "client : Bonjour serveur" ;
  char res[80];
  
  if(clientSocket == -1)
    perror("Error ");
  else
    printf("socket createds ! \n");
  

  serv.sin_family = AF_INET;
  inet_pton(AF_INET,argv[1],&(serv.sin_addr));
  serv.sin_port=htons(atoi(argv[2]));

 
  printf("appuyer sur entrer pour envoyé une dmande de connexion à l'adresse %u",serv.sin_addr.s_addr);
  scanf("%c",&valid);
  if(connect(clientSocket,(struct sockaddr *)&serv,servLen) == -1 )
    perror("Error ");
    else
    printf("connection succeed ! \n");

 
  printf("appuyer sur entrer pour contacter le serveur \n");
  scanf("%c",&valid1);

  
  if(send(clientSocket,msg,50,0) == -1)
    perror("Error ");
  else
    printf("sending message operation : success \n");


  if(recv(clientSocket,res,80,0) == -1)
    perror("Error ");
  else
    printf("%s \n",res);

  close(clientSocket);

  return 0;
}
