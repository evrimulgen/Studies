#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/sem.h>
#include<fcntl.h>

union semun {
	int val ; 						/* cmd = SETVAL */
	struct semid_ds *buf ;			/* cmd = IPC STAT ou IPC SET */
	unsigned short *array ;			/* cmd = GETALL ou SETALL */
	struct seminfo * buf ;			/* cmd = IPC INFO (sous Linux) */
};

struct sembuf{
	unsigned short semnum;
	int sem_op;
};


int main(int argc,char** argv){

	
	key_t sesame_sem,sesame_shm; 
	int id_sem,id_shm;
	struct sembuf opDV,opV;

	//Creation du sémaphore
	if (argc != 2) {
		fprintf (stderr, "Syntaxe : %s fichier_clé \n", argv [0]);
		exit (1);
	}

	if ((sesame_sem = ftok("key.txt",10)) == (key_t) -1) {
 		perror("ftok"); 
 		exit(1);
	} 
	
	if((id_sem=semget(sesame_sem,1,IPC_CREAT | 0600))==-1){
		perror("semget");
		exit(1);
	} 



	return 0;
}