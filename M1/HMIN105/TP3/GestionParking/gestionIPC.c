#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/shm.h>
#include <math.h>
#include <fcntl.h>

typedef struct {
	int nombre_places_disponibles;
}donneeP;

int main(int argc, char const *argv[])
{
	
	donneeP data;
	key_t sesame; 
	int id_shm;
	void* shared_mem_ptr;
	
	if (argc != 2) {
		fprintf (stderr, "Syntaxe : %s fichier_clé \n", argv [0]);
		exit (1);
	}

	if ((sesame = ftok(argv[1],1)) == (key_t) -1) {
 		perror("ftok"); 
 		exit(1);
	} 

	printf("clé : %d  \n",sesame);
	printf("rentrez le nombre de places disponibles\n");
	scanf("%d",&data.nombre_places_disponibles);
	if((id_shm=shmget(sesame,sizeof(data),IPC_CREAT|0600))==-1){
		perror("shmget");
		exit(1);
	}



	while(1){
		printf("id shm %d\n",id_shm);
		if((shared_mem_ptr=shmat(id_shm,NULL,0))==NULL){
				perror("shmat");
				exit(1);
		}	
		shared_mem_ptr=&data;
		sleep(10);
		printf("nombre de places disponibles saisie par l'utilsateur : %d \n",((donneeP*)shared_mem_ptr)->nombre_places_disponibles);
	}

	return 0;
} 