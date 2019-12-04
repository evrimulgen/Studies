#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include "AB.h"

void SortieLatex(AB Ar, std::string filepath);

int main(int argc,char** argv){
  Valeur v1=6,v2=0,v3=2,v4=4;

  AB a1= new Sommet(v1);
  AB a2= new Sommet(v2);
  AB a3= new Sommet(v3);
  AB a4= new Sommet(v4);

  AB a5= new Sommet(*a2);

  a1->GrefferSAG(a2);
  a2->GrefferSAG(a3);
  a2->GrefferSAD(a4);
  a1->GrefferSAD(a5);

  SortieLatex(a1,"resultat");

  return 1;

}
