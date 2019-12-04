#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> //fork(), getpid(),
#include <fcntl.h>

int main(){
  /*int fichier=open("test",O_WRONLY);
  if( fichier == -1) //si on ouvre le ficheir avant de faire le fork on a dans le fichier "enfantparent"
    {
      fprintf(stderr,"Ecriture impossible \n");
      return -1;
    }
  */
  pid_t pid;
  /*if( (pid = fork()) == 0 )
    write(fichier,"enfant",6);
  else
    write(fichier,"parent",6);
  */

  if( (pid = fork()) == 0 )
    {
      int fichier1=open("test",O_WRONLY);
      write(fichier1,"enfant",6);
      
    }
  else
    {
      int fichier2=open("test",O_WRONLY);
      write(fichier2,"parent",6);
    }
  return 0;
}
  
 
