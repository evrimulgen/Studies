//AB.cpp

#include "AB.h"


Sommet::Sommet(Valeur v){
  //à implémenter

  racine=v;
  Pere=NULL;
  FGP=false;
  SAG=NULL;
  SAD=NULL;
  hauteur=0;
  
}

/*
Sommet::Sommet(Sommet& s){
  //à implémenter
  if( &s == NULL);
  else if ((&s.SAG == NULL ) && (&s.SAD == NULL)) {
    this = new Sommet(s.racine);
  } else {
    this = new Sommet(s.racine);
    this->SAG = new Sommet(*s.SAG);
     = new Sommet(*s.SAD);
  }

}
*/

Sommet::Sommet(Sommet& s){
  //à implémenter
  racine = s.racine;
  FGP=s.FGP;

  if( s.SAG != NULL ){
    SAG = new Sommet(*s.SAG);
    SAG->FGP = true ;
    SAG->Pere = this;
  }

  
  if( s.SAD != NULL ){
    SAD = new Sommet(*s.SAD);
    SAD->FGP = false ;
    SAD->Pere = this;
  }

}



bool Sommet::FeuilleP(){
  //à implémenter
  return ((this->SAG == NULL) && (this->SAD == NULL)); 
}


void Sommet::SupprimerSAG(){
  //à implémenter
  if(this->SAG == NULL);
  else{
    this->SAG->FGP=false;
    this->SAG=NULL;
  }
}


void Sommet::SupprimerSAD(){
  //à implémenter
  if(this->SAD == NULL);
  else
    this->SAD=NULL;
     
}


void Sommet::GrefferSAG(AB g){
  //à implémenter
  if(this->SAG == NULL){
  this->SAG=g;
  g->Pere=this;
  g->FGP=true;
  }
  
 }

void Sommet::GrefferSAD(AB d){
  //à implémenter
  if(this->SAD == NULL){
  this->SAD=d;
  d->Pere=this;
  d->FGP=false;
  }

}

/* a faire :
tester la suppression
*/ 
void Sommet::RemplacerPourLePerePar(AB Ar){
  //le pere existe
  //à implémenter
  if ( !this->FGP ){
    Ar->Pere=this->Pere;
    this->Pere->SAD=Ar;
    this->Pere=NULL;
  }else{
    Ar->Pere=this->Pere;
    this->Pere->SAG=Ar;
    this->Pere=NULL;
  }

}




void Sommet::Affichage(int h) {
  if (this != NULL){
    for(int i = 0; i < h; i++) std::cout << "  ";
    std::cout << this->racine << std::endl;
    this->SAG->Affichage(h+1);
    this->SAD->Affichage(h+1);
  }
}





/*
-l'étiquette d'un sommet se trouve dans lma velur de la variable "racine"
-grâce aux 2 pointeurs SAG et SAD qui pointent sur un objet de type sommet

*/
