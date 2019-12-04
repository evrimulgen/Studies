#include "cellule.h"
#include <iostream>
#include "tableau-cellule.h"

void TableauCellule ::  TriR(TableauCellule T,size_t d,size_t f){
  size_t p=d+f/2;
  size_t i=d;  size_t=f;

  while ((i<p) && (j>p)){

if ( T.at(i)>T.at(p)) && (T.at(j)<T.at(p)){echanger(T.at(i),T.at(j));}
 else if (T.at(i)>T.at(p)){echanger (T.at(i),T.at(p))}
 else if (T.at(j)<T.at(p)){echanger (T.at(j),T.at(p))}
i++; j--; p=find(T.at(p));
  }

  TriR(T,d,p-1);
  TriR(t,p+1,f);
}
