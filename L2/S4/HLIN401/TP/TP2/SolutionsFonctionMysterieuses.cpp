#include <iostream>
#include <cmath>
#include <stdlib.h>     /* atoi */

#include "fonctionsMysterieuses.h"

int apuissanceb(int a, int b) {
// renvoie a puissance b
  if (b==0) return 1;
  if (b % 2 == 0) return apuissanceb(a * a, b / 2);
  return a * apuissanceb(a,b-1);}

int main(int argv, char** argc){

  int numeroFonction = atoi(argc[1]),
     n =  atoi(argc[2]),
    v;

  switch (numeroFonction) {
  case 1 : v=f1(n); break; // sqrt(n) * 3
  case 2 : v=f2(n); break;  // n^5 *1/10
  case 3 : v=f3(n); break; // n² * 1/2
  case 4 : v=f4(n); break; //log (n) *2
  case 5 : v=f5(n); break; // (2^n) *10
  case 6 : v=f6(n); break; //(3^n) * 20
  }

  std::cout<<"f"<<numeroFonction<<"("<<n<<") renvoie "<<v<<"\n";

  for(int n=1; n < 20 ; n++){
    std::cout<<"f"<<numeroFonction<<"("<<n<<") renvoie "<<f1(n)<<"\n";
    float rap=(float)(f1(n)/sqrt(n));
    std :: cout << rap << std :: endl;
  }          



  
  return 0;
}

/*
ordre de compilation :  g++ SolutionsFonctionMysterieuses.cpp fonctionsMysterieuses.o -o test
Ordre d'exécution :  ./test 1 2 
*/

/* Réponses : 
f6(n)=3^n * constante   ------ constante=20
f5(n)=2^n * constante   -------constante=10
f4(n)=log(n) * constante --------constante=2
f3(n)=2^n * constante ------- constante=1/2
f2(n)=5^n *constante ------ constante=1/10
f1(n)=sqrt(n) * constante ------ constante=3
*/
