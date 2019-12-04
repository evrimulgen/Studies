#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[]){
  float prob[256]={0.0};
  int occ[256]={0};
  char c;
  int t=0;
 FILE* f= fopen(argv[1],"r");

 if (f == NULL) {printf("impossible d'ouvrir le fichier %s",argv[1]);
   return -1;}
 

 while (EOF != (c=fgetc(f))){
    occ[c]++;
    t++;
  }

  fclose(f);

  for(int i=0;i<256;i++){
    prob[i]=(float)occ[i]/t;
    printf("prob[%i]=%f \n",i,prob[i]);
  }

  printf("taille = %i \n",t); 

  return 0;}
