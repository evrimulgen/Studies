#ifndef ARBREBINAIRERECHERCHE_H
#define ARBREBINAIRERECHERCHE_H

#include <iostream>
#include <sstream>


#include <cstdlib>
#include <fstream>


using namespace std;


typedef int Valeur;

class SommetABR;

typedef SommetABR* ABR;

class SommetABR  {
  protected:
  Valeur racine;
  ABR Pere,SAG, SAD;
  bool FGP;

 public:
  SommetABR(Valeur v);
  SommetABR(SommetABR& s);

  void GrefferSAG(ABR g);
   void GrefferSAD(ABR d);

  void SupprimerSAG();
  void SupprimerSAD();

  bool FeuilleP();

  void RemplacerPourLePerePar(ABR);

   friend std::string* TikzRecursABR(int ligne,int gauche, int droite, int numeroPere, int typeFils, ABR Ar);

// ABR

  ABR PlusPetit();
  ABR RechercherValeur(Valeur v);
  void InsererValeur(Valeur v);
  ABR SupprimerValeur(Valeur v); // notez la dissymétrie
  ABR SupMin();
};






#endif
