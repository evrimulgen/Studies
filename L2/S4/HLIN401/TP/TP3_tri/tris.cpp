#include<iostream>


//fonctions données
int max(int a, int b);
int moitieSuperieure(int n);
void imprimer(int n, int T[]);
void genererInverse(int n, int T[]);
void genererRandom(int n, int Max, int T[]);
void echanger(int T[], int i, int j);

//mes fonctions : 
void triPanier(int* T,int n);
void fusion(int* T,int d,int m,int f);
int* triparfusion(int* T,int d,int f);
void tri_selection(int* T,int taille);

   
int main(int argc,char** argv){

  int size;
  int maximum;
  std::cout<<"rentrez la taille de tableau sur lesquelles se feront les tris ainsi que la borne sup des tableaux" << std::endl;
  std::cin>>size>>maximum;
  

    std::cout<<"################premiers tri##################"<<std::endl;
  //tri panier,complexité O(n) dans le cas ou la borne sup du tableau est donnée

  int T[size];
  genererRandom(size,maximum,T);
  std::cout<<"new tableau"<< std::endl;
  imprimer(size,T);
  

  std::cout << "Tri_panier : " << std::endl;
  triPanier(T,size);
 
  
  imprimer(size,T);

  std::cout<<"################deuxième tri##################"<<std::endl;
  //tri fusion , complexité O(n*log(n))
  
  int R[size];
  genererRandom(size,maximum,R);
  std::cout<<"new tableau"<< std::endl;
  imprimer(size,R);


  std::cout << "Tri_fusion : " << std::endl;
  triparfusion(R,0,size-1);
  imprimer(size,R);



  
  std::cout<<"################troisième tri##################"<<std::endl;
  //tri par selection , complexité O(n*n)
  
  int S[size];
  genererRandom(size,maximum,S);
  std::cout<<"new tableau"<< std::endl;
  imprimer(size,S);


  std::cout << "Tri_parSelection : " << std::endl;
  tri_selection(S,size);
  imprimer(size,S);
  
  return 0;

}

