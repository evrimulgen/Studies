#include<iostream>
#include<stdlib.h>

using namespace std;


void f1(int n){

  int s=0;

  for(int i=1;i<=n;i++) s+=i;

  cout << s << endl;
} // f1(n)=n*(n+1)/2 


void f3(int n){
  int s=0;
  
  for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
      for(int k=i;k<=n;k++) s++;

  cout << s << endl;

} // f3 C O(n^3)


int mg2(int n){
  
  if (n == 0 ) return 1;
  if (n == 1 ) return 2 ;
  else return mg2(n-1)+mg2(n-1);
}


void g2(int n){

  cout << mg2(n) << endl;
}// calcul 2^n par l'intermédiare de mg3 ---- >  mg2(n)=2^n


int mg3(int n){

  if ( n == 0 ) return 1;
  if ( n == 1 ) return 3 ;
  else return mg3(n-1)+mg3(n-1)+mg3(n-1);
}



void g3(int n){

  cout << mg3(n) << endl;
} // calcul 3^n par l'intermédiare de mg3 ---- >  mg3(n)=3^n





int main(int argc,char** argv){

  int a=atoi(argv[1]);

  cout << "f1("<< argv[1] << ")=" ;
  f1(a);  
  cout << "f3("<< argv[1] << ")=" ;
  f3(a);
  cout << "g2("<< argv[1] << ")=" ;
  g2(a);
  cout << "g3("<< argv[1] << ")=" ;
  g3(a);

  return 0;
}

/*Reponse : y a-t-il une valeur de n pour laquelle vous sentez une différence entre :
 -l’exécution du programme f3 (n)
 et l’exécution successive des programmes f1 (n) et f3 (n): NON
 
 -l’exécution du programme g2 (n)
et l’exécution successive des programmes f3 (n) et g2 (n) : NON

— l’exécution du programme g3 (n)
et l’exécution successive des programmes g2 (n) et g3 (n) : NON

Reponse : A partir de quelle valeur de n sentez vous la différence entre l’exécution des programmes : 
 
f1(n) et f3(n) : pour n=
f3(n) et g2(n) : pour n=
g2(n) et g3(n) : pour n=20
*/
