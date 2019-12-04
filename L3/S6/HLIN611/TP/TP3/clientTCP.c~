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

  int ds=socket(PF_INET,SOCK_DGRAM,0);
  struct sockaddr_in dest;


  if( argc !=4) {
    fprintf(stderr,"synatxe : ./mon_prog entier adresse numeroPort \n");
    return -1;
  }

  dest.sin_family = AF_INET;
  inet_pton(AF_INET,argv[2],&(dest.sin_addr));
  dest.sin_port=htons(atoi(argv[3]));
  int m = atoi(argv[1]);
  if(sendto(ds,&m,sizeof(int),0,(struct sockaddr*)&dest,sizeof(struct sockaddr_in)) == -1)
    //printf("sending message operation : failed \n");
    perror("Error ");
  else
    printf("sending message operation : success \n");

  close(ds);

  return 0;
}
