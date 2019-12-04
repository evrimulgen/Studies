#include<stdio.h>
#include<stdlib.h>

string strsplit(string * ch[]){
  int i=0;j=0;
  int T[];

  while(ch[i]!=NULL){
    if(ch[i]!=":"){T[j]=ch[i];
      printf("T[%d]=%s",&j,&ch[i])
      else T[j+1]=ch[i];
      printf("T[%d]=%s",&j,&ch[i]);}
  }
    
      
    return T;}

int main (int argc,char * argv[],char * env[]){
  string ch1[];

  scanf("%s",&ch1);
  strsplit(ch1);
  return 0; }
