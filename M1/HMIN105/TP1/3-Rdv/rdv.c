#include<stdio.h>
#include<unistd.h> //fork(), getpid(),
#include<sys/types.h> //toutes
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>
#include"calcul.h"

int condition=0;

struct taille
{
	int counter;
	int size;
}typedef taille;

pthread_mutex_t verrou=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condi=PTHREAD_COND_INITIALIZER;


void* thread(void* arg) {
	taille* o = (taille *) arg;	
	printf("debut du calcul avec le thread %lu \n",pthread_self());
	calcul(o->counter+10 );
	

	pthread_mutex_lock(&verrou);
	condition++;
	taille* n=(taille*)arg;
	while(condition < o->size/2){
		
		pthread_cond_wait(&condi,&verrou);
	}
	printf("le thread  %lu est arrivé au point de rdv\n",pthread_self());
	pthread_mutex_unlock(&verrou);

	pthread_mutex_lock(&verrou);	 
	if(condition == o->size/2)
		pthread_cond_broadcast(&condi);
	pthread_mutex_unlock(&verrou);
	printf("Fin du calcul avec le thread %lu \n",pthread_self());	
	pthread_exit(NULL);
	}

int main(int argc,char** argv){


	if(argc != 2 ){
		fprintf(stderr,"usage: ./rdv integer\n");
		return -1;
	}

	int n=atoi(argv[1]);
	struct taille mysize;
	mysize.size=n;
	pthread_t idpth[n];

	for(int i=0;i<n;++i){
		 mysize.counter=i;
		 pthread_create(&idpth[i],NULL,thread,&mysize);
	}


	for(int i=0;i<n;i++)
			pthread_join(idpth[i],NULL);

	return EXIT_SUCCESS; 
}
