#include "Arbo.h"

/******* Liste chainee Début *******/

Cellule::Cellule (ContCellule A){
  fils=A;
  Apres=NULL;
}




ListeCellules Cellule::EstDansListeP(ContCellule A){
  if (fils==A) return this;
  if (Apres==NULL) return NULL;
  return Apres->EstDansListeP(A);
}



ListeCellules Cellule::AjouterSuccesseur(ContCellule A){
  if (!EstDansListeP(A)) {
    ListeCellules ptCell=new Cellule(A);
    ptCell->Apres=this;
    return ptCell;
    }
  return this;
}



ListeCellules Cellule::RetirerSuccesseur(ContCellule A){
  if (fils==A) return Apres;
  if (!Apres) return this;
  Apres=Apres->RetirerSuccesseur(A); return this;
}




/******* Liste chainee Fin *******/


/************Arborescence Debut*************/


Sommet::Sommet(Valeur v){
  racine=v;
  ListeSuccesseurs=NULL;  // à completer et decommenter
}





ListeCellules Sommet::EstSuccesseurP(Arbo A){
  if (ListeSuccesseurs) return ListeSuccesseurs->EstDansListeP(A);  // à completer et decommenter
  return NULL;
}



void Sommet::AjouterSuccesseur(Arbo A){
  if (!ListeSuccesseurs){
    ListeSuccesseurs=new Cellule(A);
    return;
  }
  if (! ListeSuccesseurs->EstDansListeP(A)) {
    ListeSuccesseurs= ListeSuccesseurs->AjouterSuccesseur(A);  // à completer et decommenter
  }
  return;
}



void Sommet::RetirerSuccesseur(Arbo A){
  if (ListeSuccesseurs &&  ListeSuccesseurs->EstDansListeP(A)) {
    ListeSuccesseurs= ListeSuccesseurs->RetirerSuccesseur(A);  // à completer et decommenter
  }
  return;
}

ostream& operator<<(ostream& os, Sommet& S){
  os<<S.racine<<" ";
  return os;
}

/************Arborescence Fin*************/

/************Traversee recursive Debut*************/

void TraverseePrefixeRec(Arbo A){
  if (!A) {cout<<endl; return;};
  cout<< *A<<" ";
  for (ListeCellules L=A->ListeSuccesseurs;L!=NULL;L=L->Apres){
      TraverseePrefixeRec(L->fils);
  }// à completer et decommenter
  return;
}

/************Traversee recursive Fin*************/

/**********Pile Début*********/

Pile::Pile(){
  Sommet=NULL;
}


bool Pile::VideP(){
  return Sommet==NULL;
}


void Pile::Empiler(ContCellule A){
  Cellule* ptCellule=new Cellule(A);
  ptCellule->Apres=Sommet;
  Sommet=ptCellule;
  return;
}


ContCellule Pile::Depiler(){
  Cellule* ptCellule=Sommet;
  Sommet=Sommet->Apres;
  return ptCellule->fils;
}

/**********Pile Fin*********/

/************Traversee  prefixe iterative Debut*************/

void TraverseePrefixeIt(Arbo A){
  Pile* P=new Pile;
  P->Empiler(A);
  while(! P->VideP() ){
    Arbo res=P->Depiler();
    cout<<res->racine<<"  ";
    Pile* FilsRes = new Pile;
    for(ListeCellules L=res->ListeSuccesseurs;L!=NULL;L=L->Apres){
      FilsRes->Empiler(L->fils);
    }
    while(! FilsRes->VideP() ){
      P->Empiler( FilsRes->Depiler());
    }
  }// à completer et decommenter
}


/************Traversee  prefixe iterative Fin*************/


/**********File Début*********/

File::File(){
  Sortie=NULL; Entree=NULL;
}


bool File::VideP(){
  return Sortie==NULL;
}


void File::Enfiler(ContCellule A){
  Cellule* ptCellule=new Cellule(A);
  if (Entree) Entree->Apres=ptCellule;
  Entree=ptCellule;
  if (! Sortie) Sortie=ptCellule;
  return;
}


ContCellule File::Defiler(){
  Cellule* ptCellule=Sortie;
  Sortie=Sortie->Apres;
  return ptCellule->fils;
}

/**********File Fin*********/

/************Traversee Largeur Debut*************/

void TraverseeLargeur(Arbo A){
  File F;
  F.Enfiler(A);
  while(! F.VideP() ){
   Arbo res=F.Defiler();
    cout<<res->racine<<"  ";
    for(ListeCellules L=res->ListeSuccesseurs;L!=NULL;L=L->Apres)
      F.Enfiler(L->fils);
    
  }// à completer et decommenter
   
}  // à completer

/************Traversee Largeur Fin*************/


int main(){

  
  Arbo A0 = new Sommet(0);
  Arbo A1 = new Sommet(1);
  Arbo A2 = new Sommet(2);
  Arbo A3 = new Sommet(3);
  Arbo A4 = new Sommet(4);
  Arbo A5 = new Sommet(5);
  Arbo A6 = new Sommet(6);

  A3->AjouterSuccesseur(A6);
  A1->AjouterSuccesseur(A5);
  A3->AjouterSuccesseur(A4);
  A2->AjouterSuccesseur(A3);
  A0->AjouterSuccesseur(A2);
  A0->AjouterSuccesseur(A1);

cout<<" rec A0  ";
TraverseePrefixeRec(A0);
cout<< endl;

cout<<" iter A0  ";
TraverseePrefixeIt(A0);
cout<< endl;

cout<<" largeur  ";
TraverseeLargeur(A0);
cout<< endl;


  A3->RetirerSuccesseur(A4);
  A3->RetirerSuccesseur(A6);

 cout<<"rec A0  apres retrait   ";
TraverseePrefixeRec(A0);
cout<< endl;
cout<<" iter A0  ";
TraverseePrefixeIt(A0);
cout<< endl;

 return 1;
}

