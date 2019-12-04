#include <iostream>
#include <cstdlib>


/************************
Generaux
****************************/
int max(int a, int b) {if (a > b) return a; return b;}

int moitieSuperieure(int n){
  if (n % 2 == 0) return n / 2; return (n+1) / 2;}

void imprimer(int n, int T[]){
  for (int i=0; i<n; i++) std::cout<<T[i]<<" ";
  std::cout<< std::endl;}

void genererInverse(int n, int T[]){
  for  (int i=0; i<n; i++) T[i]=n-i;
}


void genererRandom(int n, int Max, int T[]){//rempli le tableau T de n nombres aléatoires, tous enttre 0 et Max
  for  (int i=0; i<n; i++) T[i]=rand() % (Max + 1);
}


void echanger(int T[], int i, int j){
  int temp=T[i]; T[i]=T[j]; T[j]=temp;
}

//**************************************fonctions de tris************************//
void triPanier(int* T,int n){
  int maxi=T[0];
  
  for(int i=0;i<n;i++)
    maxi=max(maxi,T[i]);

  int taille_p=maxi+1;
  int P[taille_p]={0};


  
  for(int j=0;j<n;j++){
    P[T[j]]++;
  }

  int s=0;
  
  for(int j=0;j<taille_p;j++){
    if ( P[j] !=0 ) {
      for(int k=0;k<P[j];k++){
	T[s]=j;
	s++;
      }
    }
  }

}

void fusion(int* T,int d,int m,int f){
  int n1=m-d+1;
  int n2=f-m;

  int *L=(int*)malloc((n1+2)*sizeof(int));
  int *R=(int*)malloc((n2+2)*sizeof(int));

  for(int i=1;i<=n1;i++) L[i]=T[i+d-1];
  for(int j=1;j<=n2;j++) R[j]=T[j+m];

  L[n1+1]=150000; //valeur sentinelle
  R[n2+1]=150000;// valeur sentinelle 
  
  int s=1;
  int p=1;
       
  for(int k=d;k<=f;k++){
    if(L[s] < R[p]){
      T[k]=L[s];
      s++;}
    else{
      T[k]=R[p];
      p++;}
  }

}



 int* triparfusion(int* T,int d,int f){
   if (d < f) {
     int q=(d+f)/2;
     triparfusion(T,d,q); 
     triparfusion(T,q+1,f);
     fusion(T,d,q,f);
     }

 }



void tri_selection(int* T,int taille){

  for(int i=0;i<taille;i++){
    int min=i;
    for(int j=i+1;j<taille;j++){
      if (T[min] > T[j]) echanger(T,min,j);
    }
  }
}
