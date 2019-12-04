#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include "etape.h"


int nbCurrentThreads=0;
int nbMaxThreads=0;

struct sNverrou{
 	pthread_mutex_t verrou;
 	pthread_cond_t condi;
  // à compléter 
};

typedef struct sNverrou n_verrou;

struct sParams {
   n_verrou* nvTab;
   int indice;
  // à compléter
};

typedef struct sParams params;

// LE VERROU SUIVANT EST UTILISE UNIQUEMENT POUR LA SORTIE STANDARD. 
// NE PAS LE REUTILISER POUR AUTRE FONCTION QUE L'AFFICHAGE. VOIR UTILISATION PLUS LOIN.
pthread_mutex_t vStdOut= PTHREAD_MUTEX_INITIALIZER;

// initialisation des champs de la structure n_verrou
int n_verrou_init(n_verrou * v,int k){
		v->condi = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
		return pthread_mutex_init(&v->verrou,NULL);
  // à compléter
}

// bloque si le nombre maximum de threads autorisés à passer en section
// critique est atteint, sinon, permet l'accès à la section critique
int n_verrou_lock(n_verrou * v){
	pthread_mutex_lock(&v->verrou) ; 
	while(nbCurrentThreads == nbMaxThreads){
		pthread_cond_wait(&v->condi,&v->verrou);
	}
	return pthread_mutex_unlock(&v->verrou);
	// à compléter
}

// décrémente le nombre de thread en section critique et reveille
// éventuellement un thread en attente d'entrer en section critique
int n_verrou_unlock(n_verrou * v){
	pthread_mutex_lock(&v->verrou);
	nbCurrentThreads--;
	pthread_cond_signal(&v->condi);
	return pthread_mutex_unlock(&v->verrou);
  // à compléter
}

int n_verrou_destroy(n_verrou * v){
		return pthread_mutex_destroy(&v->verrou);
  // à compléter
}


// Fonction exécutée par chaque thread (joueur). NE PAS MODIFIER CETTE FONCTION !
void * jouer(void * p){

  params * param = (params*)p;
  
  // LE VERROU vStdOut EST UTILISE UNIQUEMENT POUR L'AFFICHAGE (ACCES A LA SORTIE STANDARD).
  pthread_mutex_lock(&vStdOut); printf("Joueur %d: je suis pret\n", param -> indice);  pthread_mutex_unlock(&vStdOut);
  
  // Etape 1 :
  
  // je demande à passer : je passe s'il y a moins de
  // maxNbJoueursEtape1 joueurs présents dans cette étape, sinon
  // j'attends que ça soit le cas.
  if(n_verrou_lock(&(param -> nvTab[0])) != 0) {
    perror("probleme n_verrou lock");
    free(param);
    pthread_exit(NULL);
  }
  
  // rappel : vStdOut n'est utilisé que pour les affichages et n'affecte en rien le déroulement du jeu.
  pthread_mutex_lock(&vStdOut); printf("Joueur %d: debut etape 1\n", param -> indice); pthread_mutex_unlock(&vStdOut);
  
  etape();
  
  pthread_mutex_lock(&vStdOut); printf("Joueur %d: fin etape 1\n", param -> indice); pthread_mutex_unlock(&vStdOut);
  
  // je viens de finir une étape, je dois le signaler.
  if(n_verrou_unlock(&(param->nvTab[0])) != 0) {
    perror("probleme n_verrou unlock");
    free(param);
    pthread_exit(NULL); 
  }

  
  // Etape 2 :
  
  // je demande à passer : je passe s'il y a moins de
  // maxNbJoueursEtape2 joueurs présents dans cette étape, sinon
  // j'attends que ça soit le cas.
  if(n_verrou_lock(&(param->nvTab[1]))!= 0) {
    perror("probleme n_verrou lock");
    free(param);
    pthread_exit(NULL);
  }

  pthread_mutex_lock(&vStdOut); printf("Joueur %d: debut etape 2\n", param -> indice); pthread_mutex_unlock(&vStdOut);
  
  etape();
  
  pthread_mutex_lock(&vStdOut); printf("Joueur %d: fin etape 2\n", param -> indice); pthread_mutex_unlock(&vStdOut);
  
  // je viens de finir une étape, je dois le signaler.
  if(n_verrou_unlock(&(param->nvTab[1])) != 0) {
    perror("probleme n_verrou unlock");
    free(param);
    pthread_exit(NULL); 
  }
  
  // Etape 3 :
  
  // je demande à passer : je passe s'il y a moins de
  // maxNbJoueursEtape1 joueurs présents dans cette étape, sinon
  // j'attends que ça soit le cas.
  if(n_verrou_lock(&(param->nvTab[2])) != 0) {
    perror("probleme n_verrou lock");
    free(param);
    pthread_exit(NULL);
  }
  
  pthread_mutex_lock(&vStdOut); printf("Joueur %d: debut etape 3\n", param -> indice);; pthread_mutex_unlock(&vStdOut);

  etape();
  
  pthread_mutex_lock(&vStdOut); printf("Joueur %d: fin etape 3, je termine\n", param -> indice); pthread_mutex_unlock(&vStdOut);
  
  // je viens de finir une étape, je dois le signaler.
  if(n_verrou_unlock(&(param->nvTab[2])) != 0) {
    perror("probleme n_verrou unlock");
    free(param);
    pthread_exit(NULL); 
  }

  free(param);
  pthread_exit(NULL);
}

int main(int argc, char * argv[]){
  
  if(argc != 5){
    printf ("lancement : ./bin/jeu NbJoueurs maxNbJoueursEtape1 maxNbJoueursEtape2 maxNbJoueursEtape3 \n");
    exit(1);
  }
  
  srand(time(0)); // garder cette ligne sans la modifier.

 
  // à compléter. Rappel : chaque thread joueur exécutera la fonction jouer(...) 
  int NbJoueurs=atoi(argv[1]);
  pthread_t idths[NbJoueurs];
  for(int i=0;i<NbJoueurs;i++){
  	params* args= malloc(sizeof(params));
  	args->nvTab =(n_verrou*)malloc(3*sizeof(n_verrou));
  	args->indice =i;
  	n_verrou_init(args->nvTab,NbJoueurs);
  	pthread_create(&idths[i],NULL,jouer,&args);
  }


  for(int i=0;i<NbJoueurs;i++)
      pthread_join(idths[i],NULL);
    

  return 0;
}

  



  
