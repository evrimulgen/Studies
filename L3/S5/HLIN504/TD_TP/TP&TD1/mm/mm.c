#include "mm.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


mm mm_creer()
{ mm jeu=(mm)malloc(sizeof(struct mm));
  for(int i=0;i<4;i++)
    {
    jeu->secret[i]=rand()%10;
    }
  jeu->nbessais = 0;
  return jeu;
}
void mm_detruire(mm jeu)
{
  free(jeu); 
}
  
int mm_test(mm jeu, char* essai)
{
  int nb_lbp=0;
  int nb_lmp=0;
  
  for(int i=0;i<TAILLE;i++)
    {
      for(int j=0;j<TAILLE;j++)
	{
	  if((essai[i] == jeu->secret[j]) && (i == j))
	    {
	      nb_lbp++;
	    }
	  else if ( essai[i] == jeu->secret[j] )
	    {
	      nb_lmp++;
	    }

	}
    }

  jeu->nbessais++;
  return (TAILLE+1)*nb_lbp+nb_lmp;
}

  

int mm_nbessais(mm jeu)
{
  return jeu->nbessais; 
}
     
