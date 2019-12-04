#include<stdio.h>
#include<stdlib.h>

int main (int argc,char * argv[],char * env[]){
  float m=0.0;
  for(int i=0;i<argc;i++){
    m+=atoi(argv[i]);
  }
  printf("%6.2f \n", m/(argc-1));
  return 0; }
