#include "ArbreBinaireRecherche.h"

SommetABR::SommetABR(Valeur v){
  racine=v; SAG=NULL; SAD=NULL;Pere=NULL;
}

SommetABR::SommetABR(SommetABR& s){
  racine=s.racine; SAG=NULL; SAD=NULL;
  if (s.SAG) GrefferSAG(new SommetABR(*(s.SAG)));
  if (s.SAD) GrefferSAD(new SommetABR(*(s.SAD)));
}

void SommetABR::GrefferSAG(ABR g){
  //à implémenter
  if((SAG == NULL) && (g->racine <= racine)){
  this->SAG=g;
  g->Pere=this;
  g->FGP=true;
  }
}


void SommetABR::GrefferSAD(ABR d){
  //à implémenter
  if((SAD == NULL) && (d->racine > racine)){
  this->SAD=d;
  d->Pere=this;
  d->FGP=false;
  }

}


void SommetABR::RemplacerPourLePerePar(ABR x){
  x->Pere=Pere;
  if(FGP){
    Pere->SAG=x;
    Pere=NULL;
    x->FGP=true;
  }else{
    Pere->SAG=x;
    Pere=NULL;
    x->FGP=false;
  }
}

  
 
void SommetABR::SupprimerSAG(){
    if(this->SAG == NULL);
  else{
    this->SAG->FGP=false;
    this->SAG=NULL;
  }
}

void SommetABR::SupprimerSAD(){
   if(this->SAD == NULL);
  else
    this->SAD=NULL;
}

bool SommetABR::FeuilleP(){
  return ( (!SAD) && (!SAG) ) ;
}


ABR SommetABR::PlusPetit(){
  //implémenter
  if(!this) return NULL;
  if (!SAG) 
    return this;
  else return SAG->PlusPetit();
}



ABR SommetABR::RechercherValeur(Valeur v){
  //implémenter
  if (this == NULL) return NULL;
  if (this->racine == v ) return this;
  if ( v <= this->racine ){
    if (SAG) return SAG->RechercherValeur(v);
    else return NULL;
  }else{
    if (SAD) return SAD->RechercherValeur(v);
    else return NULL;
  }
}

void SommetABR::InsererValeur(Valeur v){
  //implémenter
  if(racine >= v){
    if (SAG) SAG->InsererValeur(v);
    else GrefferSAG(new SommetABR(v));
  }else{
    if (SAD) SAD->InsererValeur(v);
    else GrefferSAD(new SommetABR(v));
  }
}

ABR SommetABR::SupMin(){
  //implémenter
  if (!SAG){if (Pere) RemplacerPourLePerePar(SAD);
    return SAD;
  }else {
    ABR min=PlusPetit();
    min->RemplacerPourLePerePar(min->SAD);
    return min;
  }
}


ABR SommetABR::SupprimerValeur(Valeur v){
  //implémenter
  ABR cible = RechercherValeur(v);
  if(!cible) return this;
  if(cible->FeuilleP() ) { if(!cible->Pere) return NULL ;
    cible->RemplacerPourLePerePar(NULL) ; return this ; }
  if (!cible->SAG){
    if (cible->Pere)
      {cible->RemplacerPourLePerePar(cible->SAD);
	return this ;
      }else {
      cible->SAD->Pere=NULL;
      return cible->SAD;
    }
  }
  if (!cible->SAD) {
    if (cible->Pere){
      cible->RemplacerPourLePerePar(cible->SAG) ;
      return this ;
    } else {
      cible->SAG->Pere=NULL ;
      return cible->SAG ;}
  }

  cible->racine= cible->SAD->PlusPetit()->racine ;
  cible->SAD->SupMin() ;
  return this ;
}


void SortieLatex(ABR Ar,std::string filepath);


int main() {
  ABR A1=new SommetABR(11);

  
  //Insertions;
  A1->InsererValeur(5);
  A1->InsererValeur(15);
  A1->InsererValeur(3);
  A1->InsererValeur(9);
  A1->InsererValeur(7);
  A1->InsererValeur(8);
  A1->InsererValeur(10);

  SortieLatex(A1,"résultat");

  A1->SupprimerValeur(5);

   SortieLatex(A1,"résultat2");
  
  
  return 0;
}

/* compiler avec g++  ArbreBinaireRecherche.cpp SortieLatex.cpp  */

