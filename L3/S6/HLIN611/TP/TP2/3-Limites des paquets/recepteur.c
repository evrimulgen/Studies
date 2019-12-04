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

  if( argc !=3) {
    fprintf(stderr,"synatxe : ./mon_prog numeroPort nbrOctets \n");
    return -1;
  }

  int ds=socket(PF_INET,SOCK_DGRAM,0);
  struct sockaddr_in rcv,sourceAddr;
  int m=0,nbrOctets;
  socklen_t lenAddr=sizeof(struct sockaddr_in);
  
  rcv.sin_family = AF_INET;
  rcv.sin_addr.s_addr = INADDR_ANY;
  rcv.sin_port = htons(atoi(argv[1]));
  if(bind(ds,(struct sockaddr *)&rcv,sizeof(rcv)) == -1 )
    perror("Error ");
  else
    printf("naming socket opreation : success \n");

    printf("pause de 20 sec \n");
  sleep(20);
  printf("resume \n");
  if((nbrOctets=recvfrom(ds,&m,atoi(argv[2]),0,(struct sockaddr*)&sourceAddr,&lenAddr)) == -1)
    perror("Error ");
  else
    printf("Bytes number recieved %i ; m = %i \n",nbrOctets,m);
  
  close(ds);

  return 0;
}
