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
    fprintf(stderr,"synatxe : ./mon_prog adresse numeroPort  \n");
    return -1;
  }

  int ds=socket(PF_INET,SOCK_DGRAM,0);
  struct sockaddr_in dest;
  int i=0,j=0;

  dest.sin_family = AF_INET;
  inet_pton(AF_INET,argv[1],&(dest.sin_addr));
  dest.sin_port=htons(atoi(argv[2]));
  printf("saississez 2 entiers  : \n");
  printf("integer 1 : ");
  scanf("%d",&i);
  printf("integer 2 : ");
  scanf("%d",&j);

  if(sendto(ds,&i,sizeof(int),0,(struct sockaddr*)&dest,sizeof(struct sockaddr_in)) == -1)
    perror("Error ");
  else
    printf("sending message operation : success \n");

  if(sendto(ds,&j,sizeof(int),0,(struct sockaddr*)&dest,sizeof(struct sockaddr_in)) == -1)
    perror("Error ");
  else
    printf("sending message operation : success \n");

  close(ds);

  return 0;
}
