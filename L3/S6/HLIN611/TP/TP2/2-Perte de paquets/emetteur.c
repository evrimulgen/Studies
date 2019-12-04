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

  if( argc !=4) {
    fprintf(stderr,"synatxe : ./mon_prog entier adresse numeroPort \n");
    return -1;
  }

  
  int ds=socket(PF_INET,SOCK_DGRAM,0);
  int somme=0;
  struct sockaddr_in dest;
  int integerToSend = atoi(argv[1]);

  dest.sin_family = AF_INET;
  inet_pton(AF_INET,argv[2],&(dest.sin_addr));
  dest.sin_port=htons(atoi(argv[3]));

  if(sendto(ds,&integerToSend,sizeof(int),0,(struct sockaddr*)&dest,sizeof(struct sockaddr_in)) == -1)
    //printf("sending message operation : failed \n");
    perror("Error ");
  else
    printf("sending message operation : success \n");

  for(int i=1;i<=integerToSend;i++){
    if(sendto(ds,&i,sizeof(int),0,(struct sockaddr*)&dest,sizeof(struct sockaddr_in)) == -1)
      //printf("sending integer ' %i ' : failed \n",i);
      perror("Error ");
    else{
      somme +=i;
      printf("Current Integer sent : %i &  Current sum ' %i ' : success \n",i,somme);
    }
  }

  close(ds);

  return 0;
}
