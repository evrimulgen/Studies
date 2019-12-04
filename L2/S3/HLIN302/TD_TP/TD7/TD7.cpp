#include<iostream>
#include"cellule.h"
using namespace std;



template <>
const Cellule &max3<Cellule>(const Cellule &x,const Cellule &y,const Cellule &z){
  if (x.estApresOuEquivalente(y) && x.estApresOuEquivalente(z)) return x;
  if (y.estApresOuEquivalente(x) && y.estApresOuEquivalente(z)) return y;
    return z;}




template <typename T>
    const  &max3(const T &x,const T &y,const T &z){
    if (x>=y && x>=z) return x;
    if (y>=x && y>=z) return y;
    return z;}

template <typename T,typename U,typename Z>
    const T &max3(const T &x,const U &y,const Z &z){
  std :: cerr << "erreur"<<std :: endl;
  std :: terminate();
    return x;}



int main(){

  

  std :: cout << max3(1,2,3)<<std :: endl;
  std :: cout << max3(1.5,2.5,3.5)<<std :: endl;
  std :: cout << max3<int>(4.5,2,3)<<std :: endl;
   std :: cout << max3(4.5,2,3)<<std :: endl;

  return 0;}
