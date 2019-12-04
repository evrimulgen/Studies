#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
  int P=0; // nombre fétihce
  int N=0; // nombre de courses
  cin >> P ;
  cin >> N ;

  int borne = pow(10.0,6.0);
  std::string saisie;
  std::getline(std::cin,saisie);

  std ::string pos[7];
  pos=saisie.substr((N/2),(N+1)/2);
  int mediane=stoi(pos);

  if ( mediane < P)
    cout << "Parie !" << endl;
  else
    cout << "Jockey suivant !" << endl;

  return 0;
}
