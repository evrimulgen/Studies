#include "itv.h"
#include <iostream>

using namespace std;

Itv::Itv():bi(0.0), bs(0.0) { }

Itv::Itv(double binf, double bsup) :bi(binf), bs(bsup) {
  if (binf > bsup) {
    cout << "Avertissement: les valeurs fournies (bi=" << bi << ", bs = " << bs
	 << ") pour la création de l'intervalle ont été inversées." << endl;
    bi = bsup;
    bs = binf;
  }
}
double  Itv::getBorneInf() const { return bi; }
double  Itv::getBorneSup() const { return bs; }

void  Itv::setBorneInf(double v) {
  if (v > bs) {
    cerr << "Avertissement: la valeur de la borne inférieure (bi = " << bi
	 << ") n'a pas été mise à jour car > borne sup"
	 << endl;
  }
  else {
    bi = v;
  }
}
void  Itv::setBorneSup(double v) {
  if (v < bi) {
    cerr << "Avertissement: la valeur de la borne supérieure (bs = " << bs
	 << ") n'a pas été mise à jour car < borne inf"
	 << endl;
  }
  else {
    bs = v;
  }
}

void  Itv::Afficher() const { cout << "[" << bi << ", " << bs << "]"; }

double  Itv::Longueur() const { return bs - bi; }

bool  Itv::Appartient(double v) const { return (v >= bi) && (v <= bs); }

// Nouvelles Méthodes
bool Itv::estEgal(const Itv &I) const {
  return (bi == I.bi) && (bs == I.bs);
}

bool Itv::estInclusStrictement(const Itv &I) const {
  return ((bi > I.bi) && (bs <= I.bs)) || ((bi == I.bi) && (bs < I.bs));
}

bool Itv::estDisjoint(const Itv &I) const {
  return (bi > I.bs) || (bs < I.bi);
}

bool Itv::estAccole(const Itv &I) const {
  return (bi == I.bs) || (bs == I.bi);
}

bool Itv::estImbrique(const Itv &I) const {
  return (!estEgal(I) && !estInclusStrictement(I)
	  && !estDisjoint(I) && !estAccole(I));
}

Itv&  Itv::operator+=(double v) {
  bi += v;
  bs += v;
  return *this;
}

void Translate(Itv &I, double v){
  I+=v; bg
}

ostream& operator<<(ostream &os,const Itv &I){
  os << "[" << I.getBorneInf() << ", " << I.getBorneSup() << "]"; 
return os;     }

istream& operator>>(istream &is ,Itv &I)
{
  double bi,bs;
   is >> bi >> bs  ;
   I.setBorneSup(bs);
   I.setBorneInf(bi);
   return is;
 
}

bool Itv :: operator==(const Itv &I)const{
  return (bi==I.bi) && (bs==I.bs);}

bool Itv :: operator!=(const Itv &I)const{
  return !(*this==I);}


bool Itv :: operaxtor<(const Itv &I)const{
  return (bi <I.bi) && (bs<I.bs);}



bool Itv :: operator>(const Itv &I)const{
  return (bi <I.bi) && (bs<I.bs);}    




bool Itv :: operator<=(const Itv &I)const{
  return !(*this>I);}




bool Itv :: operator>=(const Itv &I)const{
  return !(*this<I);}

Itv  Itv::operator+(double v)const{
  Itv I(*this);
  return I +=v;}

