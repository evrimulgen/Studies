#include<stdio.h>
#include<unistd.h> //fork(), getpid(),
#include<sys/types.h> //toutes
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>
#include<time.h>

int res=0;
int current_index=-1;

struct args_mult{
  int x;
  int y;
}typedef args_mult;


struct args_vecteur{
  int* vecteur;
  int size;
  int index;
  args_mult* mult;
}typedef args_vecteur;




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

pthread_mutex_t verrou=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condi=PTHREAD_COND_INITIALIZER;



void* threadMult(void* arg) {

  args_vecteur* o = (args_vecteur*)arg;
 

  pthread_mutex_lock(&verrou);
  current_index=o->index;
  int f1=o->mult[current_index].x;
  int f2=o->mult[current_index].y;
  o->vecteur[current_index]=f1*f2;
  if(current_index>=0 && current_index< o->size)
    pthread_cond_signal(&condi);
  pthread_mutex_unlock(&verrou) ;
  printf("threadNum : %lu   index : %d    vecteur1 : %d  * vecteur2 : %d  = %d  \n",pthread_self(),current_index,f1,f2,f1*f2);
} 


void* threadAdd(void* arg) {
 
  pthread_mutex_lock(&verrou) ;
        
  while(current_index == -1){
    pthread_cond_wait(&condi,&verrou);
  }
  args_vecteur* o = (args_vecteur*)arg;
  res += o->vecteur[current_index];
  pthread_mutex_unlock(&verrou);
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

 
  struct args_vecteur* args = malloc(sizeof(args_vecteur));
  args->mult=(args_mult*)malloc(taille*sizeof(args_mult));

  args->vecteur=malloc(taille*sizeof(int)); 
  args->size=taille;
 

  pthread_t idpth2[taille];

  pthread_t idpth1;
 
   

  for(int i=0;i<taille;i++){
    args->index=i;
    args->mult[i].x=vect1[i];
    args->mult[i].y=vect2[i];
      //thread Multiplication
    //printf("index = %d \t x= %d \t y=%d \n",args->index, args->mult[i].x, args->mult[i].y);
  	pthread_create(&idpth2[i],NULL,threadMult,(void *)args);

  }
   pthread_create(&idpth1,NULL,threadAdd,(void *)args);

    /* for(int i=0;i<taille;i++)
      pthread_join(idpth2[i],NULL);
      */

    pthread_join(idpth1,NULL);
  
   printf("Somme : %d\n",res); 

  return 0;
}
