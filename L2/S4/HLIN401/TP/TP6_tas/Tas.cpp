#include <iostream>
#include <sstream>
#include <math.h>

#include "AB.h"
#include "Tas.h"

void ArbreParfait::Echanger(indiceDansTableauSommet a,indiceDansTableauSommet b){
  int x;
  x=contenu[a];
  contenu[a]=contenu[b];
  contenu[b]=x;
  
}


//n = Taille maximum de l'arbre parfait(nombre d'éléments)
//tableau indexé a prtir de 0  
ArbreParfait::ArbreParfait(int n){
  taillemax = n;
  contenu = new int [taillemax];
  for(int i=0 ; i< taillemax ; i++) contenu[i]=-1;
  IndicePremierSommetLibre=0;

}

int  ArbreParfait::AjouteSommetArbreParfait(int x){
  if ( IndicePremierSommetLibre < taillemax ){
    contenu[IndicePremierSommetLibre]=x;
    IndicePremierSommetLibre++;
    return 0;
  }else{
    return -1;
  }
}

bool  ArbreParfait::SommetValide(indiceDansTableauSommet i){
  return (contenu[i] != -1);
}

indiceDansTableauSommet ArbreParfait::Racine(){
  return 0;
}

bool ArbreParfait::FeuilleP(indiceDansTableauSommet i){
  return (i >= (IndicePremierSommetLibre/2));
}

indiceDansTableauSommet ArbreParfait::Pere(indiceDansTableauSommet i){
  if ( SommetValide(i) && (i < IndicePremierSommetLibre ) )
    return (i-1)/2;
  else return -1;
}

indiceDansTableauSommet ArbreParfait::FilsGauche(indiceDansTableauSommet i){
  if  ( SommetValide(i) && (i < IndicePremierSommetLibre ) )
    return 2*i+1;
  else
    return -1;
}

indiceDansTableauSommet ArbreParfait::FilsDroit(indiceDansTableauSommet i){
  if  ( (SommetValide(i)) && (i < IndicePremierSommetLibre) )
    return 2*i+2;
  else
    return -1;
  
}
  
void ArbreParfait::SupprimerArbreParfait(indiceDansTableauSommet i){
  if ( (SommetValide(i)) && (i < IndicePremierSommetLibre )){
    Echanger(i,(IndicePremierSommetLibre-1));
    --IndicePremierSommetLibre;
  }
}


Tas::Tas(int s):
  ArbreParfait(s){}

void  Tas::Remonter(indiceDansTableauSommet i){
  if ( (i < IndicePremierSommetLibre) && (i != Racine() ) )
    if(contenu[Pere(i)] > contenu[i]) {
      Echanger(i,Pere(i));
      Remonter(Pere(i));
    }
  
}

void Tas::Descendre(indiceDansTableauSommet i){
  if((i != -1) && ( !FeuilleP(i) ) ) {
    if ( (FilsDroit(i) != -1) && (contenu[FilsGauche(i)] > contenu[FilsDroit(i)]) ) {
      Echanger(FilsDroit(i),i);
      Descendre(FilsDroit(i));
    }else if ( (FilsGauche(i) != -1) && (contenu[FilsGauche(i)] < contenu[FilsDroit(i)]) ) {
      Echanger(FilsGauche(i),i);
      Descendre(FilsGauche(i));
    }
  }
}

void Tas::SupprimerTas(indiceDansTableauSommet i){
  if ( i < IndicePremierSommetLibre ){
    this->SupprimerArbreParfait(i);
    if( contenu[i] < contenu[Pere(i)] ) Remonter(i); 
    if( ( contenu[i] > contenu[FilsGauche(i)] ) ||  ( contenu[i] > contenu[FilsDroit(i)] ) )
      Descendre(i);
  }
}

void Tas::AjouterTas(int e){
  AjouteSommetArbreParfait(e);
  if((contenu[IndicePremierSommetLibre-1]) < (contenu[Pere(IndicePremierSommetLibre-1)] ) )
    Remonter(IndicePremierSommetLibre-1);
}

int Tas::Supmin(){
  int s=contenu[Racine()];
  SupprimerTas(Racine());
  return s;
}

//ne marche pas :(

AB Tas::TasVersAB(indiceDansTableauSommet i){

  if(SommetValide(i))
    {
      AB A0= new Sommet(this->contenu[i]);
      std::cout<<"filsGauche"<<FilsGauche(i)<<std::endl;
      std::cout<<"filsDroit"<<FilsDroit(i)<<std::endl;
      if ( FilsGauche(i) < IndicePremierSommetLibre )
	A0->GrefferSAG(TasVersAB(FilsGauche(i)));
      if ( FilsDroit(i)  < IndicePremierSommetLibre )
	A0->GrefferSAD(TasVersAB(FilsDroit(i)));
    }else{
    return NULL;
  }
 
}
      
	
	







