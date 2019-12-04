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
  int serveurSocket,i=0,recvBufferSize=0;
  struct sockaddr_in rcv,client;
  char valid;
  char* repositoryName;
  char* msgRecieved;
  struct stat  buf;
  long int fileSize=0;
  socklen_t lenAddr,optlen;
  
  
  if( argc != 2) {
    fprintf(stderr,"synatxe : ./mon_prog numeroPort  \n");
    return -1;
  }

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

  if(listen(serveurSocket,5) == -1)
    perror("Error ");
  else
    printf("listen mode succeed \n");


  optlen = sizeof(recvBufferSize);
  getsockopt(serveurSocket, SOL_SOCKET, SO_RCVBUF, &recvBufferSize,&optlen);
  printf("Send buffer size : %d \n",recvBufferSize);

  
  stat(argv[2],&buf);
  fileSize = buf.st_size;
  msgRecieved=malloc(fileSize*sizeof(char)+1) ;
    
  
  lenAddr=sizeof(struct sockaddr_in);

  
  repositoryName=malloc(strlen("./reception")*sizeof(char)+1);
  repositoryName[strlen("./reception")+1]='\0';
  strcpy(repositoryName,"./reception/");

    
  while(1){

    printf("le serveur est en attente ! \n");    
    //int clientSocket=accept(serveurSocket,(struct sockaddr *)&client,&lenAddr);
    int tube[2];
    int clientSocket;
    //int r=pipe(tube);
    char* msg = "Serveur : file transfered \n" ;
    char* name="fichier";
    FILE* file=NULL;
    int len=0,octets=0;
    //int clientSocketChlid=0;
    //write(tube[1],&clientSocketParent,sizeof(int));
    /*if(clientSocket == -1 )
      perror(" Error ");
      else
      printf("connection request accepted form port %i , adress %s ! \n",ntohs(client.sin_port),inet_ntoa(client.sin_addr));
    */
    sleep(5);
    switch(fork()){

    case 0 :{
      printf("serveurSocket %d \n",serveurSocket);
      clientSocket=accept(serveurSocket,(struct sockaddr *)&client,&lenAddr);
      if(clientSocket == -1 )
	perror(" Error ");
      else
	printf("connection request accepted form port %i , adress %s ! \n",ntohs(client.sin_port),inet_ntoa(client.sin_addr));

      printf("clientSocket %d \n",clientSocket);
      close(serveurSocket);
      strcat(repositoryName,name);
      file=fopen(repositoryName,"w");
      if(file == NULL){
	fprintf(stderr,"opening file failed  in the reception repository failed !  \n");
	return -1;
      }
     
     
      msgRecieved=malloc(512*sizeof(char)+1);
      msgRecieved[512]='\0';

      if (recv(clientSocket,&msgRecieved,512,0) != -1){
	printf("Content recieved : \n %s \n",msgRecieved);
      }else{
	printf("failed reading the content on the client socket \n");
      }
      
      fwrite(msgRecieved,octets,1,file);
      if(send(clientSocket,&msg,80,0) == -1)
	perror("Error ");
      else
	printf("sending message operation : success \n");

      close(clientSocket);
      exit(0);
    }
    case -1 : printf("duplication ratée \n");
    default : close(clientSocket);  
    }
    
    close(serveurSocket);
    i++;
  }
  
  

  return 0;
}
