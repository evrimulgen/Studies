#include<iostream>
#include<ostream>

using namespace std;

template<typename TypeElement> 
void echange(TypeElement& e1, TypeElement& e2)
{TypeElement aux=e1; e1=e2; e2=aux;}

template<typename TypeElement>
void triBulles(TypeElement T[], int tailleT)
{
  int i=tailleT-2,j; bool ech=true;
  while (i>=0 && ech)
    {
      ech=false;
      for (j=0; j<=i; j++)
	if (T[j]>T[j+1])
	  {echange(T[j],T[j+1]); ech=true;}
      i--;
    }
}
