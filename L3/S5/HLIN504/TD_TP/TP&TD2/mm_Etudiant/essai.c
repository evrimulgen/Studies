#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc,char **argv)
{
  char jeu[5];
  int res=0;
  srand((unsigned)time(NULL));
  for(int i=0;i<4;i++)
    {
      res=res+pow(10,i)*(rand()%10);
    }

  sprintf(jeu,"%d",res);
  printf("%s \n",jeu);
  char* str_jeu=(char*)malloc(sizeof(char)*(strlen(jeu)+1));
  char essai[5];
  jeu[4]='\0';
  int x;

  while ( x != 0)
    {
      strcpy(str_jeu,jeu);
      int nb_lbp=0;
      int nb_lmp=0;
      printf("Saisir une combinaison de chiffres \n");
      scanf("%s",essai);
      for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	  {
	    if ( str_jeu[j] == 'x') j++;
	    if( ((int)essai[i] == (int)str_jeu [j]) && (i == j) )
	      {
		nb_lbp++;
		str_jeu[j]='x';
		
	      }
	    else if (essai[i] == str_jeu [j]) 
	      {
		nb_lmp++;
		str_jeu[j]='x';
	      }
	  }
  
      printf("nbr_lmp = %d \t nbr_lbp = %d \n",nb_lmp,nb_lbp);
      printf("Si vous voulez arrêtez tapez 0 sinon tapez 1\n");
      scanf("%d",&x);
    }
  /*
    char* str1="ary";
    char* str2="leda";
    printf("%ld \n",strspn(str1,str2));
  */
  return 0;
}

  
