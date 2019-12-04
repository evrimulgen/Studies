#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "progListeSC.h"
#include "fichierTP3.h"
using namespace std;



bool estTrieeLSC(ListeSC L){
  //   Res : Renvoie true si L est une ListeSC tri�e, false sinon 

  if (estVideLSC(L) || estVideLSC(L->succ))
    return true;
  else
    return (L->info < (L->succ)->info) &&  estTrieeLSC(L->succ);
}



bool estListeIntervalle(ListeSC L){
  //   Res : renvoie true si L est une Liste intervalle, renvoie false sinon 
  // A COMPLETER
  if (L == NULL ) return true ;else {
  if ((L->succ) == NULL) return true ;
  else if (L->info < (L->succ)->info ) return estListeIntervalle(L->succ);

  return false ; }
}

ListeSC consListeIntervalle1(int l, int p){
  //     Donn�e : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier �l�ment a pour valeur p 
  //     Complexit� : O(n^2)  
  assert(l>0);
  
  int i; ListeSC L;
  L=NULL;
  for(i=0;i<l;i++)    
    insererFinLSC(L,p+i);
  return L;
}

ListeSC consListeIntervalle2(int l, int p){
  //     Donn�e : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier �l�ment a pour valeur p 
  //     Complexit� : O(n)
  assert(l>0);
  // A COMPLETER
  ListeSC L=NULL;
  while (l!=0){
     
       
       insererDebutLSC(L,p+l-1);
       l--;
}
  return L;}

ListeSC consListeIntervalle3(int l, int p){
  //     Donn�e : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier �l�ment a pour valeur p 
  //     Complexit� : ???  
  // Version r�cursive
  assert(l>0);
  // A COMPLETER
  ListeSC L=NULL;
  if (l == 0)return L;
  else {
    insererDebutLSC(L,p+l-1);
    return  consListeIntervalle3(l--,p);   
  }

  return NULL;
}

void transfListeIntervalle(ListeSC L){
  // Donn�e : L est une liste tri�e non vide  
  // Res : modifie L en y inserant des �l�ments de sorte qu'elle soit une Liste Intervalle 
  assert((L!=NULL));
  assert(estTrieeLSC(L));
  // A COMPLETER

  ListeSC p=L,q=L->succ;
  
  while (q != NULL ){
    if ((q->info - p->info) != 0 ){
      p->succ=consListeIntervalle2(q->info - p->info,p->info +1);
      predecesseurLSC(ListeSC L, ListeSC Q)
      
      
  return;
}

ListeSC intersectionListesIntervalles(ListeSC l1, ListeSC l2){
  // Donn�e : l1 et l2 2 listes intervalles
  // Res : Renvoie l'intersection de l1 et l2; les �l�ments de la liste r�sultat sont recopi�s
  // Complexit� : ????
  // A COMPLETER
  assert(estListeIntervalle(l1));
  assert(estListeIntervalle(l2));

  return NULL  ;
}
  
void plusLgSsLiInterv(ListeSC &L){
  // Donn�e : L liste
  // Res : L est modifiee, elle est la lus longue sous-liste intervalle de la liste en entr�e
  // A COMPLETER

}





