#include<stdio.h>
#include<unistd.h> //fork(), getpid(),
#include<sys/types.h> //toutes
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdbool.h>



int  partage=0;

struct args_matrice{
  int** matrice;
  int rows;
  int res;
  bool (*method)(int);
} typedef args_matrice;

bool isPair(int i) {
  return ((i & 1) == 0);
}

bool isImpair(int i) {
  return ((i & 1) == 1);
}

void* threading(void* arg) {
  args_matrice* o = (args_matrice*)arg;
  int res = 0;
  int n = o->rows;

  for(int i=0;i<n;i++)
    if(o->method(i)) res++;

  o->res = res;
  printf("je suis le thread %lu \n",pthread_self());
  exit(0);
  partage+=50;
  return NULL;
}

int main(int argc,char** argv){

  int n = 5;
  int** matrice = malloc(n * sizeof(int));

  for(int i=0;i<n;++i){
    matrice[i]=malloc(n*sizeof(int));
    for (int j = 0; j < n; ++j) {
      matrice[i][j] = 1;
    }
  }

  pthread_t idpth1,idpth2;
  struct args_matrice* args1 = malloc(sizeof(args_matrice));
  args1->matrice = matrice;
  args1->rows=5;
  args1->method = isPair;

  struct args_matrice* args2 = malloc(sizeof(args_matrice));
  args2->matrice = matrice;
  args2->rows=5;
  args2->method = isImpair;

  pthread_create(&idpth1,NULL,threading,(void *)args1);
  pthread_create(&idpth2,NULL,threading,(void *)args2);
  pthread_join(idpth1,NULL);
  pthread_join(idpth2,NULL);

  printf("nombre de lignes pair : %d \t nombre de lignes impair %d \t partage %d \n",args1->res,args2->res,partage);

  return 0;
}
