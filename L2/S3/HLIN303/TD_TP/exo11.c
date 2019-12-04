#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char iota(unsigned int i,char *s){
  if (i<10){
    s[0]=i+'0';
    s[1]='\0';
  }else{
    char u=i%10+'0';
    int l=strlen(iota((i/10),s));
    s[l]=u;
    s[l+1]='\0';
  }
  return *s;
}

int main(int argc,char *argv[]){
  char s[256];
  
  for(int i=0;i<3000;i=+485){
    printf("%d est convertie en %c\n",i,iota(i,s));}
  return 0;}
