#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(int argc,char* argv[]){
  
  if (argc !=2){fprintf(stderr,"syntaxe : %s <nom fichier> \n",argv[0]);}
  
  int f=open(argv[1],O_RDONLY); //f descipteur de fichier

  if(f == -1){ fprintf(stderr,"impossibe d'ouvrir le fichier ! \n");
    return 2;}
  
  char c; int i=0;
  while (0 < read(f,&c,1)){
    i++;}

  printf("%i \n",i);
    return 0;
     }
