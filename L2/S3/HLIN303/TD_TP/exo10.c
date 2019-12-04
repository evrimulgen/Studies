#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int atoiperso(char *c[]){
  int i=0,s=0;
  
  while((c[i]<='9') && (c[i]>='0')){
    s=s*10+(*c[i]-'0');
    i++;  }
  
  return s;
}

int main(int argc,char *argv[]){
  if(argc!=2){
    fprintf(stderr,"saisir un arg SVP ! \n");
    return 1;
  }
  printf("maconversion : %d \n",atoiperso(*argv[1]));
  printf("atoi: %d \n",atoiperso(*argv[1]));
  return 0;
}

