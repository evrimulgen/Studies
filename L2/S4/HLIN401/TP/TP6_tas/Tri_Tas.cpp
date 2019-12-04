#include <iostream>
#include <sstream>
#include <cmath>

#include "AB.h"
#include "Tas.h"

void SortieLatex(AB Ar, std::string filepath);

void afficher(int* T,int taille){
  for(int i=0;i<taille;i++)
    std::cout<<"T["<<i<<"]= "<<T[i]<<std::endl;
}


void TrisTas(int* T,int taille){
  Tas t(taille);
  std::cout<<"mon tas min "<<std::endl;
  
  //Création du tas
  
  for(int i=0;i<taille;i++){
    t.AjouterTas(T[i]);
  }
  
  // AB A=t.TasVersAB(0);
  // SortieLatex(A,"tasMin");
  afficher(t.contenu,t.IndicePremierSommetLibre);
  std::cout<<"IPSL = "<<t.IndicePremierSommetLibre<<std::endl;

  /*TRIS PAR TAS
    Supression du plus petit element du tas 
    tout en conservant le minimum supprimé du tas 
    on l'insère dans notre tableau à trier
  */
  
  for(int i=0;i<taille;i++){
    T[i]=t.Supmin();
  }

}
    




int main(int argc,char** argv){

  int T[10];
  int s=10;

  //tableau décroissant valeurs comprises entre 1 et 10
  std::cout<<"tableau décroissant"<<std::endl;
  for(int i=0;i<10;i++){
    T[i]=s;
    s--;
  }

  afficher(T,10);

  TrisTas(T,10);

  std::cout<<"résultat du tris par TAS : "<<std::endl;
  afficher(T,10);
    
  


  
  return 0;
}

  
//revoir descendre()
