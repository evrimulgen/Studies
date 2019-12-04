%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  double yylval;  
#define AVANCER {jeton=yylex();numcar++;}
#define TEST_AVANCE(prevu) {if (jeton==(prevu)) AVANCER else ERREUR_SYNTAXE}
#define ERREUR_SYNTAXE {printf("\nMot non reconnu : erreur de syntaxe \
au caractère numéro %d \n",numcar); exit(1);}
#define LITDOUBLE 300
#define PUISS 301  
double E(void);double R(double);double T(void);double S(double);double F(void); /* déclars */

int jeton;
int numcar=0;
/* caractère courant du flot d’entrée */
/* numero du caractère courant (jeton) */

%} 
%option noyywrap

%%

([0-9]+\.[0-9]*|\.[0-9]+)([eEdD][+-]?[0-9]+)?|[0-9]+ {yylval=strtod(yytext,NULL);return LITDOUBLE;}
"**" {return PUISS;}
.|\n {return yytext[0];}	       

%%

double E(void){
   return   R(T());
  /* regle : E->TR */
}
double R(double g){
  if (jeton=='+') {
    /* regle : R->+TR */
    AVANCER
    return   R(g+T());
  }
  else return g;
  /* regle : R->epsilon */
}
double T(void){
  return S(F());
  /* regle : T->FS */
}
double S(double g){
  if (jeton=='*') {
    /* regle : S->*FS */
    AVANCER
      return(S(g*F()));
  }
  else return g;
  /* regle : S->epsilon */
}


double F(void){
  if (jeton=='(') {
    /* regle : F->(E) */
    AVANCER;
    E();
    TEST_AVANCE(')');
  }
  else if (jeton==LITDOUBLE){
    double d=yylval;
    /* regle : F->0|1|...|9 */
    AVANCER;
    return d;
  }  else
    ERREUR_SYNTAXE
}
int main(){
  /* Fonction principale */
  AVANCER /* initialiser jeton sur le premier car */
    double d=E();
  /* axiome */
  if (jeton=='\n')
    /* expression reconnue et rien après */
    printf("\nMot reconnu : %f \n",d);
  else ERREUR_SYNTAXE
	 /* expression reconnue mais il reste des car */
	 return 0;
}


