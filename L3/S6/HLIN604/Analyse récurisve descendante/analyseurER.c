#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* les macros sont des blocs : pas de ’;’ apres */
#define AVANCER {jeton=getchar();numcar++;}
#define TEST_AVANCE(prevu) {if (jeton==(prevu)) AVANCER else ERREUR_SYNTAXE}
#define ERREUR_SYNTAXE {printf("\nMot non reconnu : erreur de syntaxe \
au caractère numéro %d \n",numcar); exit(1);}

void S(void);void X(void);void E(void);void R(void);void T(void);void Y(void);void F(void);

int jeton;
int numcar=0;

void S(void){
  E();
  X();
}

void X(void){
  if (jeton=='|'){
    AVANCER
      E();
    X();
  }else ;
}

void E(void){
  T();
  R();
}

void R(void){
  T();
  R();
  if(jeton=='@');
}

void T(void){
  F();
  Y();
}
void Y(void){
  if(jeton=='*'){
    AVANCER
      Y();
  }else;
}
void F(void){
  if (jeton=='(') {
    AVANCER
      S();
    TEST_AVANCE(')')
      }
  else
    if ( (jeton>=97 && jeton<=122) || (jeton=='@') || (jeton==48))
      /* regle : F->0|1|...|9 */
      AVANCER
      else ERREUR_SYNTAXE
	     }

int main(void){
  /* Fonction principale */
  AVANCER /* initialiser jeton sur le premier car */
    S();
  /* axiome */
  if (jeton=='\n')
    /* expression reconnue et rien après */
    printf("\nMot reconnu\n");
  else ERREUR_SYNTAXE
	 /* expression reconnue mais il reste des car */
	 return 0;
}


