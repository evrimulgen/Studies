#include"noued.h"
#include<iostream>
#include"abr.h"


template<typename T>
Abr<T> :: Abr(){n.();};


template<typename T>
bool Abr<T> :: find const(const Noeud<T> &p){

  Noeud<T> *j=this;
  bool trouve=false;
  while (trouve){
    if ( *j.getval() == p.getval()) trouve = true;
    else { if (*j.getval() > p.getval()) j=*j.gauche;
      else j=*j.droit;}
}


template<typename T>
void Abr<T> :: insert(const Noeud<T> &k){
  Noeud<T>* p=this;
  Noeud<T>* r=&k;
  if (p == NULL) return;

  if (p.dorit == NULL)&&(p.gauche == NULL ){
      if (*r.getval() > *p.getval()) p.gauche=r;
      else p.droit = r;}
  else{
    if(*r.getval() > *p.getval()) return insert(p.gauche);
    else return insert(p.droit);}
}


 template<typename T>

   T  Abr<T> :: plus_petit_ele() const{
   Noeud<T> *y=this.droit;
   T min=this.getval();

   while ( y == NULL ){
     if (min > *y.getval()) { min=*y.getval();
       y=y.droit;}
   }

   return min;
 } // le plus petit ele est tout a droite 
 
template<typename T>

   T  Abr<T> :: plus_grand_ele() const{
   Noeud<T> *y=this.droit;
   T max=this.getval();

   while ( y == NULL ){
     if (max > *y.getval()) { max=*y.getval();
       y=y.droit;}
   }

   return max;
 } // le plus grand ele est tout a gauche 

 
  
      
    
     

  

