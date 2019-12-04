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

  int ds=socket(PF_INET,SOCK_DGRAM,0);
  struct sockaddr_in rcv;
  rcv.sin_family = AF_INET;
  rcv.sin_addr.s_addr = INADDR_ANY;
  rcv.sin_port = htons(atoi(argv[1]));
  if(bind(ds,(struct sockaddr *)&rcv,sizeof(rcv)) == -1 )
    //printf("naming socket opreation : failed \n");
    perror("Error ");
  else
    printf("naming socket opreation : success \n");

  int m;
 
  struct sockaddr_in aE;
  socklen_t lg=sizeof(struct sockaddr_in);
  if(recvfrom(ds,&m,sizeof(int),0,(struct sockaddr*)&aE,&lg) == -1)
    //printf("where is the message \n");
    perror("Error ");
  else
    printf("Integer recieved %i \n",m);
  

  close(ds);

  return 0;
}
