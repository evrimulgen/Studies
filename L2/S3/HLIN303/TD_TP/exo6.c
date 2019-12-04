#include<stdio.h>

int main(int agrc,char * argv[],char * env[]){
  printf("saisir 5 nbrs \n");
  float m=0.0,nb;
  for(int i=0;i<5;i++){
    scanf("%f",&nb);
    m+=nb;}
  printf("\n resultat: %f \n",m/5);
  return
    0; }
