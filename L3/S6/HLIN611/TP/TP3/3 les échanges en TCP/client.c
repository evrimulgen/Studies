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
  char* msg1=malloc(32*sizeof(char));
  char* msg2=malloc(32*sizeof(char));
  int nombreIterations=0;
  int nombreTotalOctets=0;
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
  
  printf("entrez la 1er  chaîne de caractères  qui est au plus de taille 32 \n");
  fgets(msg1,100,stdin);
  while (strlen(msg1) > 32 ) {
    printf("PAS PLUS DE 32 OCTETS !!!  \n");
    fgets(msg1,100,stdin);
  }
  printf("longueur de la 1er chaîne de caractères : %lu \n",strlen(msg1));

  printf("****************************************** \n \n");

  
  printf("entrez la 2éme chaîne de caractères  qui est au plus de taille 32 \n");
  fgets(msg2,100,stdin);
  while (strlen(msg2) > 32 ) {
    printf("PAS PLUS DE 32 OCTETS !!!  \n");
    fgets(msg2,100,stdin);
  }
  printf("longueur de la 2éme chaîne de caractères : %lu \n",strlen(msg2));

    
  printf("****************************************** \n \n");
  
  ssize_t len1=0;
  ssize_t longueur1=strlen(msg1);

  while(len1<longueur1){
    int compteur1=0;
    if((compteur1=send(clientSocket,msg1+len1,sizeof(msg1),0)) == -1)
      //printf("sending message operation : failed \n");
      perror("Error ");
    else{
      nombreIterations++;
      printf("sending message operation : success \n");
      printf("longueur du message 1  envoyé %i \n",compteur1);
      char* avancement1=malloc(compteur1*sizeof(char)+1);
      strncpy(avancement1,msg1+len1,compteur1);
      printf("message sent : < %s > \n",avancement1);
      len1+=compteur1;
      nombreTotalOctets+=compteur1;
    }
  }

  printf("****************************************** \n \n");
  
  ssize_t len2=0;
  ssize_t longueur2=strlen(msg2);
  
  while(len2<longueur2){
    int compteur2=0;
    if((compteur2=send(clientSocket,msg2+len2,sizeof(msg2),0)) == -1)
      perror("Error ");
    else{
      nombreIterations++;
      printf("sending message operation : success \n");
      printf("longueur du message 2 envoyé %i \n",compteur2);
      char* avancement2=malloc(compteur2*sizeof(char)+1);
      strncpy(avancement2,msg2+len2,compteur2);
      printf("message sent : < %s > \n",avancement2);
      len2+=compteur2;
      nombreTotalOctets+=compteur2;
    }
  }

  printf("****************************************** \n \n");
  
  printf("nombre iterations : %i \n",nombreIterations);
  printf("nombre total d'octets envoyés (send) : %i \n",nombreTotalOctets);
  printf("nombre total d'octets envoyés (réel) : %lu \n",strlen(msg1)+strlen(msg2));


  if(recv(clientSocket,res,80,0) == -1)
    perror("Error ");
  else
    printf("%s \n",res);

  close(clientSocket);

  return 0;
}
