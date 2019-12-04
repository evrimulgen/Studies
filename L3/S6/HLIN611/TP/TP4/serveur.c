#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char** argv)
{


  if( argc != 3) {
    fprintf(stderr,"synatxe : ./mon_prog numeroPort nomduFichier  \n");
    return -1;
  }

  int serveurSocket,recvBufferSize=0,clientSocket,len=0,iterations=0,compteur=0,realBytesCount=0,size;
  struct sockaddr_in rcv,sourceAddr;
  char valid,valid1,valid2,valid3;
  struct stat  buf;
  long int fileSize;
  char* msgRecieved;
  socklen_t lenAddr=sizeof(struct sockaddr_in),optlen;
  char* msg = "Serveur :file transfered !" ;
  long int nbIterations=0;
  char* repositoryName;

  size=strlen("./reception");
  repositoryName=malloc(size*sizeof(char)+1);
  repositoryName[size]='\0';
  strcpy(repositoryName,"./reception/");
  strcat(repositoryName,argv[2]);
  
  serveurSocket=socket(PF_INET,SOCK_STREAM,0);
  rcv.sin_family = AF_INET;
  rcv.sin_addr.s_addr = INADDR_ANY;
  rcv.sin_port = htons(atoi(argv[1]));
  if(bind(serveurSocket,(struct sockaddr *)&rcv,sizeof(rcv)) == -1 )
    perror("Error ");
  else
    printf("naming socket opreation : success \n");

  
  printf("appuyer sur entrer pour mettre la socket en mode écoute \n");
  scanf("%c",&valid);
  if(listen(serveurSocket,10) == -1)
    perror("Error ");
  else
    printf("listen mode succeed \n");

  optlen = sizeof(recvBufferSize);
  getsockopt(serveurSocket, SOL_SOCKET, SO_RCVBUF, &recvBufferSize,&optlen);
  printf("Send buffer size : %d \n",recvBufferSize);

  
  stat(argv[2],&buf);
  fileSize = buf.st_size;
  msgRecieved=malloc(fileSize*sizeof(char)+1) ;

  printf("appuyer sur entrer pour accepter une connexion \n");
  scanf("%c",&valid1);
 	

  clientSocket= accept(serveurSocket,(struct sockaddr *)&sourceAddr,&lenAddr);
  if(clientSocket == -1 )
    perror("Error ");
  else
    printf("connection request accepted ! \n");

  
  printf("appuyer sur entrer pour recevoir (mode reception) \n");
  scanf("%c",&valid2);

 
  printf("%s \n",repositoryName);
  FILE* file=fopen(repositoryName,"w");
  if(file == NULL){
    fprintf(stderr,"opening file failed  in teh emission repository failed !  \n");
    return -1;
  }

  
  printf("saissisez le nombre d'itérations de sent pour le fichier envoyé : \n");
 
  scanf("%d",&iterations);

  while (  nbIterations < iterations  ){
    if((len=recv(clientSocket,msgRecieved+compteur,sizeof(msgRecieved),0)) != -1 ){
      realBytesCount += strlen(msgRecieved+compteur);
      fwrite(msgRecieved+compteur,strlen(msgRecieved+compteur),1,file);
      printf("bytes recieved : %d \n",len);
      printf("real number of bytes recieved : %lu \n",strlen(msgRecieved+compteur));
      compteur += len;
      nbIterations++;
    }else{
      perror("Error ");;
    }
  }

  
  printf("file Content received :  \n |  ");
  for(int i=0;i<realBytesCount;i++)
    printf("%c",msgRecieved[i]);

    
  printf("real number of bytes recieved : %d \n",realBytesCount);  
  printf("nombre total d'octets reçus (recv) : %d \n",compteur);
  fclose(file);
  printf("file tranfert operation success ! \n");  


  printf("appuyer sur entrer pour répondre au client \n");
  scanf("%c",&valid3);
  if(send(clientSocket,msg,80,0) == -1)
    perror("Error ");
  else
    printf("sending message operation : success \n");

  close(serveurSocket);

  return 0;
}
