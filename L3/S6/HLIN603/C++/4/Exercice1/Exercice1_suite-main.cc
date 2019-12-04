#include"Exercice1_suite.h"
#include<iostream>

using namespace std;

int main()
{
  Casier6<Oeuf>* notreCasier1;
  notreCasier1 = new Casier6<Oeuf>;

  Oeuf* o1=new Oeuf();
  Oeuf* o2=new Oeuf();

  notreCasier1.ranger(0,o1);
  notreCasier1.ranger(1,o2);

  Casier6<int>* notreCasier2;
  notreCasier2 = new Casier6<int>;

  notreCasier2.ranger(0,5);
  notreCasier2.ranger(1,10);
  
}
