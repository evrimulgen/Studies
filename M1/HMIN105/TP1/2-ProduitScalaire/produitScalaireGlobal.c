#include<stdio.h>
#include<unistd.h> //fork(), getpid(),
#include<sys/types.h> //toutes
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>
#include<time.h>

struct args_mult{
  int x;
  int y;
}typedef args_mult;


struct args_vecteur{
  int size;
  int index;
  args_mult* mult;
}typedef args_vecteur;


int additionRes=0;

void fillVector(int* T,int n){
	for(int i=0;i<n;i++)
		T[i]=rand()%10;
}

void displayVector(int* T,int n){
	printf("Vector : ");
	for(int i=0;i<n;i++)
		printf("%d \t",T[i]);
	printf("\n");
}


void* threadMult(void* arg) {

  args_vecteur* o = (args_vecteur*)arg;
  int ind= o->index;
  int f1=o->mult[ind].x;
  int f2=o->mult[ind].y;
  additionRes += f1*f2;
  printf("threadNum : %lu   index : %d    vecteur1 : %d  * vecteur2 : %d  = %d || additionRes = %d \n",pthread_self(),ind,f1,f2,f1*f2,additionRes);
} 


int main(int argc,char** argv){

  int sum=0;	
  int taille=atoi(argv[1]);	
  int vect1[taille],vect2[taille];
  srand(time(NULL));

  fillVector(vect1,taille);
  fillVector(vect2,taille);
  displayVector(vect1,taille);
  displayVector(vect2,taille);

 

  

  struct args_vecteur* args = malloc(sizeof(args_vecteur));
  args->mult=(args_mult*)malloc(taille*sizeof(args_mult));
  args->size=taille;


  for(int i=0;i<taille;i++){
  	args->index=i;
    args->mult[i].x=vect1[i];
    args->mult[i].y=vect2[i];
    //thread Multiplication
    pthread_t idpth2;
  	pthread_create(&idpth2,NULL,threadMult,(void *)args);
    pthread_join(idpth2,NULL);
  }
  
 
  return 0;
}
