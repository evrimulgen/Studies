#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int calculproba(char* chemain,float proba[256]){

  FILE* f= fopen(chemain,"r");

 if (f == NULL) {printf("impossible d'ouvrir le fichier %s",chemain);
   return -1;}
 int occ[256]={0};
 int t=0,c;

 while (EOF != (c=fgetc(f))){
    occ[c]++;
    t++;
  }

  fclose(f);

  for(int i=0;i<256;i++){
    proba[i]=(float)occ[i]/t;
    printf("proba[%i]=%f \n",i,proba[i]);
  }

  return t;}

  

int main(int argc,char* argv[]){
  float proba[256]={0.0};

  if (argc != 2) {fprintf(stderr,"syntaxe : %s fichier \n ",argv[0]);
   return -1;}

  if(0>calculproba(argv[1],proba)){
    fprintf(stderr,"calcul prob impossible \n");
    return 2;}
  int n=0;

  for(int i=0;i<256;i++){
    if (proba[i] != 0.0){
      n++;
      printf("car: %c de code %x de proba: %f \n",i,i,proba[i]);
  }

  }
  printf("%i \n",n);

  int conv[256]={-1};
  int nbn=2*n-2;

  float prob[nbn];
  int rconv[nbn];
  int j=0;

  for(int i=0;i<256;i++){
    if(proba[i] != 0.0 ){
      prob[j]=proba[i];
      conv[i]=j;
      rconv[j]=i;
      j++;
      printf("prob[%i]= %f conv[%i]= %i  rconv[%i]= %i proba[%i]= %f \n",j,prob[j],i,j,j,i,i,proba[i]);
    }}

  int fg[]={-1};
  int fd[]={-1};
  int parent[]={-1};

  
  for(int nvnoe=n ;nvnoe < nbn ; nvnoe++){
    int i=-1;
    int j=-1;
   for( n=0;n<nvnoe;n++){
      if (parent[n]==-1){
	if (i==-1) i=n;
	  else if (j==-1) j=n;
	  else if (prob[n]<prob[i]) {j=i; i=n;}
        else if (prob[n]<prob[j]) j=n;
      }}

	parent[i]=parent[j]=nvnoe;
	fg[nvnoe]=i;
	fd[nvnoe]=j;
	prob[nvnoe]=prob[i]+prob[j];
	printf("%d : filsgauche= %d filsdroit= %d prob[%i] = %f \n", nvnoe,fg[nvnoe],fd[nvnoe],nvnoe,prob[nvnoe]);
      }

  
  return 0; }

