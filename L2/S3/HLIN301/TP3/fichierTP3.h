
#ifndef FicTP3_H
#define FicTP3_H


bool estTrieeLSC(ListeSC L);
  //   Res : Renvoie true si L est une ListeSC tri�e, false sinon 

bool estListeIntervalle(ListeSC L);
  //   Res : renvoie true si L est une Liste intervalle, renvoie false sinon 

ListeSC consListeIntervalle1(int l, int p);
  //     Donn�e : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier �l�ment a pour valeur p 

ListeSC consListeIntervalle2(int l, int p);
  //     Donn�e : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier �l�ment a pour valeur p 

ListeSC consListeIntervalle3(int l, int p);
  //     Donn�e : l>0 
  //     Res : renvoie une liste intervalle de longueur l et dont le premier �l�ment a pour valeur p 


void transfListeIntervalle(ListeSC L);
  // Donn�e : L est une liste tri�e non vide  
  // Res : modifie L en y inserant des �l�ments de sorte qu'elle soit une Liste Intervalle 

ListeSC intersectionListesIntervalles(ListeSC l1, ListeSC l2);
  // Donn�e : l1 et l2 2 listes intervalles
  // Res : Renvoie l'intersection de l1 et l2; les �l�ments de la liste r�sultat sont recopi�s

 
void plusLgSsLiInterv(ListeSC &L);
  // Donn�e : L liste
  // Res : L est modifiee, elle est la lus longue sous-liste intervalle de la liste en entr�e


#endif 




