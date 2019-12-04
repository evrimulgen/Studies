#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/stat.h>

//SOCK_DGRAM pour le protocol UDP
//SOCK_STREAM pour le protocol TCP

int main(int argc,char** argv)
{
  if( argc !=4) {
    fprintf(stderr,"synatxe : ./mon_prog adresse numeroPort nomFichieràTransférer  \n");
    return -1;
  }

  int clientSocket, sendBufferSize=0,size;
  FILE* file1;
  FILE* file2;
  struct stat buf;
  struct sockaddr_in serv;
  socklen_t servLen = sizeof(struct sockaddr_in),optlen;
  char valid;
  long int fileSize;
  char* fileContent;
  char res[80];
  char* repositoryName;

  size=strlen("./emission");
  repositoryName=malloc(size*sizeof(char)+1);
  repositoryName[size]='\0';
  strcpy(repositoryName,"./emission/");
  strcat(repositoryName,argv[3]);
  
  
  clientSocket=socket(PF_INET,SOCK_STREAM,0);
  if(clientSocket == -1 )
    perror("Error ");
  else
    printf("socket createds ! \n");

  file1=fopen(argv[3],"r"); //ouverture du fichier en mode lecture
  if(file1 == NULL){
    fprintf(stderr,"opening file failed !  \n");
    return -1;
  }

  optlen = sizeof(sendBufferSize);
  getsockopt(clientSocket,SOL_SOCKET,SO_SNDBUF,&sendBufferSize,&optlen) ;
  printf("Send buffer size : %d \n",sendBufferSize);


  stat(argv[3],&buf);
  fileSize = buf.st_size;
  fileContent=malloc(fileSize*sizeof(char)+1);
  fileContent[fileSize]='\0';

  fread(fileContent,fileSize,1,file1);
  fclose(file1);
  printf("the content of the file to transfer : \n ");
  printf(" < ");
  for(int i=0;i<fileSize;i++)
    printf("%c",fileContent[i]);
  printf(" > \n");



  serv.sin_family = AF_INET;
  inet_pton(AF_INET,argv[1],&(serv.sin_addr));
  serv.sin_port=htons(atoi(argv[2]));

  printf("appuyer sur entrer pour envoyé une dmande de connexion à l'adresse %u",serv.sin_addr.s_addr);
  scanf("%c",&valid);
  if(connect(clientSocket,(struct sockaddr *)&serv,servLen) == -1 )
    perror("Error ");
  else
    printf("connection succeed ! \n");

  printf("****************************************** \n \n");

  printf("%s \n",repositoryName);
  file2=fopen(repositoryName,"w");
  if(file2 == NULL){
    fprintf(stderr,"opening file failed  in the emission repository failed !  \n");
    return -1;
  }

  fwrite(fileContent,fileSize,1,file2);
  fclose(file2);

  write(clientSocket,fileContent,fileSize);
  printf("nombre total d'octets envoyés (réel) : %lu  \n",fileSize);

  if(recv(clientSocket,res,80,0) == -1)
    perror("Error ");
  else
    printf("%s \n",res);
    
  close(clientSocket);
    
  return 0;
}
