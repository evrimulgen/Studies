//AB.h

#ifndef AB_H
#define AB_H

#include <iostream>
#include <sstream>

typedef int Valeur;

class Sommet;

typedef Sommet* AB;

std::string* TikzRecursAB(int ligne,int gauche, int droite, int numeroPere, int typeFils, AB Ar);

class Sommet {
 protected:
  Valeur racine;
  AB Pere,SAG, SAD;
  bool FGP;

  int hauteur;
  // int balanceGmoinsD;

 public:
  Sommet(Valeur v);
  Sommet(Sommet& s);

  void GrefferSAG(AB g);
  void GrefferSAD(AB d);

  void SupprimerSAG();
  void SupprimerSAD();

  bool FeuilleP();

  void RemplacerPourLePerePar(AB);

  void Affichage(int);

  friend std::string* TikzRecursAB(int ligne,int gauche, int droite, int numeroPere, int typeFils, AB Ar);
};



#endif
