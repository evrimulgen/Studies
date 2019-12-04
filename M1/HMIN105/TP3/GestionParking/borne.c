#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>

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

struct donneeP{
	int nombre_places_disponibles;
};

int main(int argc, char const *argv[])
{
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

	//Operation verrouillage sur l'ensemble de sémaphore
	opV.num=0;
	opV.sem_op=0;
	semop(id_sem,&opV,1);
	//Operation deverrouillage sur l'ensemble de sémaphore 
	opDV.num=0;
	opDV.sem_op=1;
	semop(id_sem,&opDV,1);

	if ((sesame_shm = ftok("key.txt",10)) == (key_t) -1) {
 		perror("ftok"); 
 		exit(1);
	} 
	
	if((id_shm=shmget(sesame_shm,sizeof(struct donneeP),IPC CREAT|0666))==-1){
		perror("shmget");
		exit(1);
	} 


	while (1){
		void* shared_mem_ptr;
		semctl();//verrouillage
		//accès au segment de mémoire
		if((shared_mem_ptr=shmat(id_shm,NULL,0))==-1){
			perror("shmat");
			exit(1);
		}	
		//si il y a assez de places 
		if((struc donneeP*)sh->nombre_places_disponibles >0){
			printf("Demande acceptée\n");
			(struc donneeP*)sh->nombre_places_disponibles--;
			printf("Impression ticket\n");
			printf("nombre de places actuellement disponibles : %d \n",(struc donneeP*)sh->nombre_places_disponibles);
		}else{
			printf("Pas de places \n");
		}
		sleep(2);
		semctl();//deverrouillage
	}
	
	return 0;
}