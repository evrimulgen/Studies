//AB.cpp

#include "AB.h"


Sommet::Sommet(Valeur v){
  //� impl�menter

  racine=v;
  Pere=NULL;
  FGP=false;
  SAG=NULL;
  SAD=NULL;
  hauteur=0;
  
}

/*
Sommet::Sommet(Sommet& s){
  //� impl�menter
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
  //� impl�menter
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
  //� impl�menter
  return ((this->SAG == NULL) && (this->SAD == NULL)); 
}


void Sommet::SupprimerSAG(){
  //� impl�menter
  if(this->SAG == NULL);
  else{
    this->SAG->FGP=false;
    this->SAG=NULL;
  }
}


void Sommet::SupprimerSAD(){
  //� impl�menter
  if(this->SAD == NULL);
  else
    this->SAD=NULL;
     
}


void Sommet::GrefferSAG(AB g){
  //� impl�menter
  if(this->SAG == NULL){
  this->SAG=g;
  g->Pere=this;
  g->FGP=true;
  }
  
 }

void Sommet::GrefferSAD(AB d){
  //� impl�menter
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
  //� impl�menter
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
-l'�tiquette d'un sommet se trouve dans lma velur de la variable "racine"
-gr�ce aux 2 pointeurs SAG et SAD qui pointent sur un objet de type sommet

*/
