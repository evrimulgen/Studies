#include "pair.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char * argv[]){
  int n=atoi(argv[1]);
  if (pair(n))
    printf("afficher : %i est pair \n",n);
  else
    printf("afficher : %i est impair \n",n);
    
  return 0;}
