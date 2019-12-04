#include<stdlib.h>
#include<stdio.h>


int main(int argc,char *argv[],char *env[]){
  printf("nbdarg :%d \n arguments :\n",argc);
  for(int i=0;i<argc;i++){
    printf("%d:%s \n",i,argv[i]);}
  printf("environnements \n");
  int i=0;
  while(env[i] != NULL ){
    printf("%d:%s \n",i,env[i]);
    i++;
  }
  return 0;
}

