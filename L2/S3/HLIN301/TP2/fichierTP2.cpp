#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
using namespace std;

//  DERNIERLSC ET ESTTRIEELSC 
// Res : Renvoie l'adresse de la derniere cellule de la liste non vide L 
ListeSC dernierLSC(ListeSC L){
  if(L == NULL) return NULL;
  if(L->succ == NULL)return L;
  else dernierLSC(L->succ);
}

//   Res : Renvoie 1 si L est une ListeSC triee, 0 sinon 
int estTrieeLSC(ListeSC L){
  if(L == NULL) return -1;
  if(L->succ == NULL) return 1;
  if(L->info <= (L->succ)->info ) return estTrieeLSC(L->succ);
  else return 0;
}


//  OTERREPETITION 
//    Res : Supprime de la ListeSC L tous les elements consecutifs egaux 
//          Opere en modifiant le chainage de la ListeSC L 
// version iterative 
void oterRepetitionLSC(ListeSC L){
  ListeSC p=NULL,q=NULL;
        
  p=L; q=L->succ;
  while ( q!=NULL ){
    if (p->info == q->info){
      q=q->succ;
      p->succ=q;}else{
      p=p->succ;
      q=q->succ;}
  }
    return;
  }

//    Res : Supprime de la ListeSC L tous les elements consecutifs egaux 
//          Opere en modifiant le chainage de la ListeSC L 
//    version recursive 
void oterRepetitionLSCR(ListeSC L){
  
    if (L->succ == NULL) {return ;}
    else if  (L->info == (L->succ)->info) {
      L->succ=(L->succ)->succ;
      oterRepetitionLSCR(L);
    }else{oterRepetitionLSCR(L->succ);
      }
}


//   CONCATENATION DE 2 LISTES  
//   Res : Modifie la liste L1 en la concatenant avec la liste l2 
//         Opere en modifiant le chainage de la listeSC L1 
//   Version utilisant la fonction dernierLSC 
void concatLSC(ListeSC& L1,ListeSC L2){
  (dernierLSC(L1))->succ=L2;
  return;
}

//   Res : Renvoie la ListeSC obtenue par concatenation des ListeSC L1 et L2 
//         Opere en recopiant les elements des 2 listeSC L1 et L2 
//   complexite : O(n^2) 
ListeSC concatLSCCopie(ListeSC L1,ListeSC L2){
  ListeSC L=NULL;  
  while ( L1 != NULL){
    insererFinLSC(L,L1->info);
    L1=L1->succ;
  }
  while ( L2 != NULL){
    insererFinLSC(L,L2->info);
    L2=L2->succ;
  }
  

  return L;
}


int main(int argc, char *argv[]){
  ListeSC l1,l2,l3;
  int q;
  
  cout << "Numero de la question traitee (1/2/3/4/5) ? ";
  cin >> q;
  switch (q){
  case 1 :  // Test des operations de base sur les listes 
    l1 = lireLSC();
    
    // insertion d'un element de valeur 11 en derniere position de la liste l1 
    // en utilisant insererFinLSC 
    // Completez

    
    insererFinLSC(l1,11);


    
    cout << "Insertion de 11 en derniere position "; afficherLSC(l1);
    
    // insertion d'un element de valeur 22 en 2eme position de la liste l1 
    // en utilisant insererApresLSC 
    // Completez

   //    insererApresLSC(l1,l1,22);
    //  sinon 


   l1->succ=creerLSC(22,l1->succ);
    
    

    
    cout << "Insertion de 22 en 2eme position ";afficherLSC(l1);
    
    // insertion d'un element de valeur 33 en 2eme position de la liste l1 
    // sans utiliser insererApresLSC 
    // Completez 


    
    cout << "Insertion de 33 en 2eme position ";afficherLSC(l1);
    
    // Suppression du 2eme element de la liste en utilisant supprimerLSC
    // Completez 

    supprimerLSC(l1,l1->succ);

    cout << "Suppression du 2eme element "; afficherLSC(l1);
    
    // Suppression du 2eme element de la liste sans utiliser supprimerLSC
    // Completez

    l1->succ=(l1->succ)->succ;



    cout << "Suppression du 2eme element "; afficherLSC(l1);
    
    // Inversion des valeurs des 2 premiers elements 
    // en modifiant les champs info (sans modifier le chainage)
    // Completez
    int x;
    x=l1->info;
    l1->info=(l1->succ)->info;
    (l1->succ)->info=x;


 
    cout << "Inversion des valeurs des 2 premiers elements " ; afficherLSC(l1);
    
    // Inversion des 2 premiers elements 
    // en modifiant les champs succ (le chainage)
    // Completez

    ListeSC p;
    p=(l1->succ);
    l1->succ=(l1->succ)->succ;
    p->succ=l1;
    l1=p;
    
   
    


    cout << "Inversion des 2 premiers elements "; afficherLSC(l1);
    break;
    
  case 2 : // Test des fonctions  estTrieeLSC et dernierLSC 
    l1 = lireLSC();
    if (estTrieeLSC(l1))  cout << "Cette liste est triee\n";
    else cout << "Cette liste n'est pas triee\n";
    if (l1 != NULL)
      cout << "La valeur de son dernier element est " << dernierLSC(l1)->info << endl;
    break;
    
  case 3: // Test des fonctions oterRepetitionLSC 
    l1 = lireLSC();
    oterRepetitionLSC(l1);
    cout << "Liste sans repetition (version iterative) :\n";
    afficherLSC(l1);
    l1 = lireLSC();
    oterRepetitionLSCR(l1);
    cout << "Liste sans repetition (version recursive) :\n";
    afficherLSC(l1);
    break;
    
  case 4 :  // Test de la premiere fonction  de concatenation de listes 
    l1 = lireLSC();
    l2 = lireLSC();
    concatLSC(l1,l2);
    cout << "Concatenation des 2 listes (en modifiant le chainage) :\n"; afficherLSC(l1);
    if ((l1 != NULL) && (l2 != NULL) )
      cout << "Adresse derniere cellule de l1 : " << (void *) dernierLSC(l1) << ", de l2 : "<< (void *) dernierLSC(l2) << endl;
    cout << " Ajout de 44 en fin de la liste l1\n";
    insererFinLSC(l1,44);
    cout << "Nouvelle valeur de l1:"; afficherLSC(l1); cout << endl;
    cout << "Nouvelle valeur de l2: "; afficherLSC(l2); cout << endl;
    break;
    
  case 5 :  // Test des fonctions  de concatenation de listes 
    l1 = lireLSC();
    l2 = lireLSC();
    l3 = concatLSCCopie(l1,l2);
    cout << "Concatenation des 2 listes (par recopie des listes) : "; afficherLSC(l3); cout << endl;
    if ((l1 != NULL) && (l2 != NULL) )
      cout << "Adresse derniere cellule de l1 : " << (void *) dernierLSC(l1) << " , de l2 : "  << (void *) dernierLSC(l2) << ", de l3 : " << (void *) dernierLSC(l3) << endl;
    cout << " Ajout de 55 en fin de la liste l1\n";
    insererFinLSC(l1,55);
    cout << "Nouvelle valeur de l1: "; afficherLSC(l1);  cout << endl;
    cout << "Nouvelle valeur de l2: "; afficherLSC(l2); cout << endl;
    cout << "Nouvelle valeur de l3: "; afficherLSC(l3); cout << endl;
    break;
  }
  return 0;
}
