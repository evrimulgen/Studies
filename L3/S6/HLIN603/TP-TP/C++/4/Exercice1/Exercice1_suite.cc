#include"Exercice1_suite.h"
#include<iostream>

using namespace std;

template<typename T>
Casier6<T>::Casier6(){for(int i=0;i<6;i++) cases[i]=NULL;}

template<typename T>
Casier6<T>::~Casier6(){}

template<typename T>
void Casier6<T>::range(T* produit,int numeroCase){
  cases[numeroCase]=produit;
}  


  
