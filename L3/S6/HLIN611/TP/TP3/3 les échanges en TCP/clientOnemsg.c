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
  char* msg=malloc(2000*sizeof(char)+1);
  int nombreIterations=0,nombreTotalOctets=0;
  char res[80];

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

  
  printf("appuyer sur entrer pour contacter le serveur \n");
  scanf("%c",&valid1);
   

  printf("entrez une  chaîne de caractères  qui est au plus de taille 2000 \n");
  fgets(msg,2000,stdin);
  while (strlen(msg) > 2000 ) {
    printf("PAS PLUS DE 32 OCTETS !!!  \n");
    fgets(msg,2000,stdin);
  }
  printf("longueur de la 1er chaîne de caractères : %lu \n",strlen(msg));

  printf("****************************************** \n \n");

  ssize_t len=0;
  ssize_t longueur=strlen(msg);

  while(len<longueur){
    int compteur=0;
    if((compteur=send(clientSocket,msg+len,sizeof(msg),0)) == -1)
      //printf("sending message operation : failed \n");
      perror("Error ");
    else{
      nombreIterations++;
      printf("sending message operation : success \n");
      printf("longueur du message   envoyé %i \n",compteur);
      char* avancement=malloc(compteur*sizeof(char)+1);
      strncpy(avancement,msg+len,compteur);
      printf("message sent : < %s > \n",avancement);
      len+=compteur;
      nombreTotalOctets+=compteur;
    }
  }

  printf("****************************************** \n \n");

  printf("****************************************** \n \n");
  
  printf("nombre iterations : %i \n",nombreIterations);
  printf("nombre total d'octets envoyés (send) : %i \n",nombreTotalOctets);
  printf("nombre total d'octets envoyés (réel) : %lu \n",strlen(msg));

  printf("****************************************** \n \n");
   
  if(recv(clientSocket,res,80,0) == -1)
    perror("Error ");
  else
    printf("%s \n",res);

  close(clientSocket);

  return 0;
}
