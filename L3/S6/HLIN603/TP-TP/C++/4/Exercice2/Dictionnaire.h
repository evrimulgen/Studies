#ifndef __DICTIONNAIRE__H
#define __DICTIONNAIRE__H


template<typename TypeCle,typename TypeValeur>
  class Dictionnaire{
private:
Assoc<TypeCle,TypeValeur> * assosiations;
public:
Dictionnaire();
void put(TypeCle cle,TypeValeur valeur);
TypeValeur get(TypeCle cle);
bool estVide(); 
int taille();
bool contient(TypeCle cle);
ostream affiche();
};
