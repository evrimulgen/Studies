#include "mm.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

mm mm_creer()
{ mm jeu=(mm)malloc(sizeof(struct mm));
  int res=0;
  srand((unsigned)time(NULL));
  for(int i=0;i<4;i++)
    {
    res=res+pow(10,i)*(rand()%10);  
    
    }
  sprintf(jeu->secret,"%d",res);
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
  char* str_jeu=(char*)malloc(sizeof(char)*(strlen(jeu->secret)+1));
  strcpy(str_jeu,jeu);
  for(int i=0;i<TAILLE;i++)
    {
      for(int j=0;j<TAILLE;j++)
	{
	  if ( str_jeu[j] == 'x') j++;
	  if( ((int)essai[i] == (int)str_jeu [j]) && (i == j) )
	    {
	      nb_lbp++;
	      str_jeu [j]='x';
		
	    }
	  else if (essai[i] == str_jeu [j]) 
	    {
	      nb_lmp++;
	      str_jeu [j]='x';
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
     
