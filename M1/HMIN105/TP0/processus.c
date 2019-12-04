#include<stdio.h>
#include<unistd.h> //fork(), getpid(),
#include<sys/types.h> //toutes
#include<sys/wait.h>
#include<stdlib.h>

void fork_hauteur(int n){
  if (n==0) return ;
  else if(fork() == 0 ){
	printf("un nouveau descendant %d de parent %d ! \n",getpid(), getppid());
	fork_hauteur(n-1);
      }
}


  
void fork_largeur(int n) {
  for(int i=0 ; i<n ; i++){
    switch (fork()){
    case 0:{
      printf("un nouveau descendant %d de parent %d ! i=%d\n",getpid(), getppid(),i);
      int status;
      exit(status);
    }
    case -1 : printf("erreur\n"); 
    }
  }
}

void fork_tree(int n){
  if(n==1) return;
  else if (fork()==0) {
    printf("un nouveau descendant %d de parent %d !\n",getpid(), getppid());
    fork_tree(n-1);
  }else if(fork()==0) {
    printf("un nouveau descendant %d de parent %d !\n",getpid(), getppid());
    fork_tree(n-1);
  }
}

int main(int argc,char** argv){

  //fork_largeur(atoi(argv[1]));
  //fork_hauteur(atoi(argv[1]));
  fork_tree(atoi(argv[1]));
  sleep(30);
  
return 0;
}
