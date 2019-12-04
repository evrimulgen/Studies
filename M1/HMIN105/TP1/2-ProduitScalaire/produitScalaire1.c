#include<stdio.h>
#include<unistd.h> //fork(), getpid(),
#include<sys/types.h> //toutes
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>
#include<time.h>





struct args_vecteur{
  int* vecteur1;
  int* vecteur2;
  int index;
} typedef args_vecteur;


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

int vecteuRes[10];

void* threadMult(void* arg) {

  args_vecteur* o = (args_vecteur*)arg;
  int* v1 = o->vecteur1;
  int* v2 = o->vecteur2;
  int ind= o->index;
  vecteuRes[ind]=v1[ind]*v2[ind];
  printf("threadNum : %lu   index : %d    vecteur1 : %d  * vecteur2 : %d  = %d  \n",pthread_self(),ind,v1[ind],v2[ind],v1[ind]*v2[ind]);
  
}

int main(int argc,char** argv){


  if(argc != 2 ){
    fprintf(stderr,"usage: ./produitScalaire1 integer\n");
    return -1;
  }

  int sum=0;	
  int taille=atoi(argv[1]);	
  int vect1[taille],vect2[taille];
  srand(time(NULL));

  fillVector(vect1,taille);
  fillVector(vect2,taille);
  displayVector(vect1,taille);
  displayVector(vect2,taille);

 

  pthread_t idpth[taille];

  //thread Multiplication
  for(int i=0;i<taille;i++){
  	
  	struct args_vecteur* args = malloc(sizeof(args_vecteur));
	  args->vecteur1 = vect1;
  	args->vecteur2 = vect2;
  	args->index = i;
    pthread_create(&idpth[i],NULL,threadMult,(void *)args);
  
  }

   for(int i=0;i<taille;i++)
   		pthread_join(idpth[i],NULL);


 //thread Addition

    for(int i=0;i<taille;i++){
  		sum += vecteuRes[i];
  	}

  	printf("resultat : %d \n",sum);

  return 0;
}
