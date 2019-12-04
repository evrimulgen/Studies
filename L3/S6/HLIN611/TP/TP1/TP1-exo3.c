
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 500

int main(int argc, char *argv[])
{
  struct addrinfo *result; //struct contenant les informations et adresse IP de le machine passée en parmètre via son nom d'hôte  passée en parmètre dans la fonction getaddrinfo(..)
  
  struct addrinfo hints;  // restrictions(format de adresses,type de protocles ....) sur les résultats fournis dans la struct result 

  int s;  //vérifier si getaddrinfo fonctionne 

  //exemples de restrictions sur les résultats 
  hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
  hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */

  if (argc != 2) {
    fprintf(stderr, "Usage: %s adresseIP ou nom d'hôte de \n", argv[0]);
    exit(EXIT_FAILURE);
  }

    
  s = getaddrinfo(argv[1],NULL,NULL, &result);
  //hints = NULL (résulats sans restrictions)
  if (s != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
    exit(EXIT_FAILURE);
  }

  struct addrinfo *p;
  char host[256]; //nom d'hôte des @IP obtenus
  char hostAdress[256]; // adresse IP

  //inet_ntop

  printf("**************	************** \n");	
  for(p = result; p != NULL; p = p->ai_next) {

	getnameinfo(p->ai_addr, p->ai_addrlen, host, sizeof(host), NULL, 0,NI_NUMERICSERV);
	getnameinfo(p->ai_addr, p->ai_addrlen, hostAdress, sizeof(hostAdress), NULL, 0,NI_NUMERICHOST);
	// on peut ultilise le flag NUMERICHOST Pour afficher @IP de l'hote
	printf("Hostname  : %s \n",host);
	printf("socktype  : %i \n",p->ai_socktype);
	printf("protocol  : %i \n",p->ai_protocol);
	printf("IP adress : %s \n",hostAdress);
	if (p->ai_next)
	printf("\n -------------------------------------------------------------  \n");			 
	// inet_ntop(p->ai_addr->sa_family,&p->ai_addr,hostAdress,32) donne des adresses différentes
	// inet_ntop(AF_INET,&p->ai_addr,hostAdress,32) donne des adresses différentes
  }

  printf("**************	************** \n");
  return 0;
}
