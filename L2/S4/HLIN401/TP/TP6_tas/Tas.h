#ifndef TAS_H
#define TAS_H

#include <iostream>
#include <sstream>

#include "AB.h"

typedef int indiceDansTableauSommet;

class ArbreParfait
{
  public:
  int IndicePremierSommetLibre;
  int taillemax; //nombre d'�l�ments maximum
  int* contenu;
  void Echanger(indiceDansTableauSommet,indiceDansTableauSommet);

  public:
  ArbreParfait(int);
// on passe la hauteur max de l'arbre, un arbre r�duit � sa racine �tant de hauteur 0


 int AjouteSommetArbreParfait(int);
// renvoie -1 si l'ajout a �chou�

bool SommetValide(indiceDansTableauSommet);

indiceDansTableauSommet Racine();
bool FeuilleP(indiceDansTableauSommet);
indiceDansTableauSommet Pere(indiceDansTableauSommet);
indiceDansTableauSommet FilsGauche(indiceDansTableauSommet);
indiceDansTableauSommet FilsDroit(indiceDansTableauSommet);

void SupprimerArbreParfait(indiceDansTableauSommet);

};


class Tas : public ArbreParfait {
  public:
  Tas(int);

  void Remonter(indiceDansTableauSommet);
  void Descendre(indiceDansTableauSommet);

  void SupprimerTas(indiceDansTableauSommet);

  void AjouterTas(int);

  int Supmin();

  void DescendreRecursive(indiceDansTableauSommet indiceDansTas, AB S);

  AB TasVersAB(indiceDansTableauSommet i);

  

};

#endif
