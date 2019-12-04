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
  int m,somme=0,cpt=0,ds;
  struct sockaddr_in rcv,sourceAddr;
  socklen_t lenAddr=sizeof(struct sockaddr_in);
  
  if( argc !=2) {
    fprintf(stderr,"synatxe : ./mon_prog numeroPort \n");
    return -1;
  }

  ds=socket(PF_INET,SOCK_DGRAM,0);
  rcv.sin_family = AF_INET;
  rcv.sin_addr.s_addr = INADDR_ANY;
  rcv.sin_port = htons(atoi(argv[1]));

  if(bind(ds,(struct sockaddr *)&rcv,sizeof(rcv)) == -1 )
    perror("Error ");
  else
    printf("naming socket opreation : success \n");

  
  if(recvfrom(ds,&m,sizeof(int),0,(struct sockaddr*)&sourceAddr,&lenAddr) == -1)
    //printf("where is the message \n");
    perror("Error ");
  else
    printf("message recieved ! \n");

  for(int i=1;i<=m;i++){
    if(recvfrom(ds,&cpt,sizeof(int),0,(struct sockaddr*)&sourceAddr,&lenAddr) == -1){
      //printf("where is the message \n");
      perror("Error ");
    }else{
      somme+=cpt;
      printf("Current Integer recieved %i Current sum : %i \n",cpt,somme);

    }
  }

  printf("la somme est  : %i \n",somme);
  close(ds);

  return 0;
}
