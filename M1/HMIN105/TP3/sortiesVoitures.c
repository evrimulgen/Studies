#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>


union semun {
	int val ; 						/* cmd = SETVAL */
	struct semid_ds*buf ;			/* cmd = IPC STAT ou IPC SET */
	unsigned short *array ;			/* cmd = GETALL ou SETALL */
	struct seminfo* buf ;			/* cmd = IPC INFO (sous Linux) */
};
 

int main(int argc, char const *argv[])
{

	key_t sesame; 
	int id_sem;
	struct sembuf opV,opDv;

	if (argc != 2) {
		fprintf (stderr, "Syntaxe : %s fichier_clé \n", argv [0]);
		exit (1);
	}

	if ((sesame = ftok("key.txt",10)) == (key_t) -1) {
 		perror("ftok"); 
 		exit(1);
	} 
	
	if((id_sem=semget(sesame,1,IPC_CREAT | 0600))==-1){
		perror("semget");
		exit(1);
	} 

	//Operation verrouillage de verrou
	opV.num=0;
	opV.sem_op=0;
	semop(id_sem,&opV,1);
	//Operation deverrouillage de verrou
	opDV.num=0;
	opDV.sem_op=1;
	semop(id_sem,&opDV,1);
	
	while (1){
		void* shared_mem_ptr;
		semctl();//verrouillage
		//accès au segment de mémoire
		if((shared_mem_ptr=shmat(id_shm,NULL,0))==-1){
			perror("shmat");
			exit(1);
		}
		sleep(1);	
		//on incrémante le nombre de place disponibles 
		if((struc donneeP*)sh->nombre_places_disponibles<10){
			printf("Et un véhicule de moins\n");
			(struc donneeP*)sh->nombre_places_disponibles++;
			printf("Impression ticket\n");
			printf("nombre de places actuellement disponibles : %d \n",(struc donneeP*)sh->nombre_places_disponibles);
		}
		semctl();//deverrouillage	
	return 0;
}