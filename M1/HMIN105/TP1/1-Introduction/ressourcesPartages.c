#include<stdio.h>
#include<unistd.h> //fork(), getpid(),
#include<sys/types.h> //toutes
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>

void *T1 (void * par){
  int * cp = (int*)(par);
  for(int i=0; i < 1500; i++) ++(*cp);
  pthread_exit(NULL);
}

void *T2 (void * par){
  int * cp = (int*)(par);
  for(int i=0; i < 3000; i++) ++(*cp);
  pthread_exit(NULL);
}

int main(){
  pthread_t idT1, idT2;
  int counter = 0;         //donnée en mémoir partagée
  if (pthread_create(&idT1, NULL, T1, &counter) != 0)
      printf("erreur creation \n");
  if (pthread_create(&idT2, NULL, T2, &counter) != 0)
      printf("erreur creation \n");

  int res = pthread_join(idT1, NULL);
  res = pthread_join(idT2, NULL);
  printf("Total : %d \n",counter);

  return 0;
}
