#include <iostream>
#include "myvector.h"

template <typename T>
MyVector<T>::MyVector() : _data(NULL), _n(0), _alloc(0) {}

template <typename T>
MyVectort<T>::MyVector(size_t n) : _data(new T[n]), _n(n), _alloc(n) {}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& A) : _data(new T[A._n]), _n(A._n), _alloc(_n)
{
  for(size_t i=0;i<_n;i++){
    _data[i]=A._data[i];
  }
}

template <typename T>
MyVector<T>::~MyVector(){ delete[] _data;}
  
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& A)
{
  if (this!=&T){
    delete[] _data;
    _data=new MyVector[A._n];
    _n=A._n;
    _alloc=_n;
    for(size_t i=0;i<_n;i++){
      _data[i]=A._data[i];
    }    
  }
  return *this;
}

template <typename T>
<T>& MyVector<T>::at(size_t i)      {return _data[i];}


template <typename T>
const <T>& MyVector<T>::at(size_t i) const  {return _data[i];}

template <typename T>
size_t MyVector<T>::size()const {return _n;}


template <typename T>
void MyVector<T>::extend(){
  if (_n<_alloc) return;
  _alloc=2*_n;
  T* tmp=new T[_alloc];
  for(size_t i=0;i<_n;i++){tmp[i]=_data[i];}
  delete[] _data;
  _data=tmp;
}


template <typename T>
void MyVector<T>::push_back(const Extensible& C){
  extend();
  _data[_n]=C;
  _n++;
}



template <typename T>
void MyVector<T>::erase(int idx){
  if (idx>=0 && idx<(int)_n){
    for(size_t i=idx;i<_n-1;i++)
      _data[i]=_data[i+1];
    _n--;
  }  
}

template <typename T>
bool identique(const <T>& C1,const <T>& C2){
   return (C1.getX()==C2.getX()) && (C1.getY()==C2.getY()) && (C1.getVivante()==C2.getVivante()); 
 }
int



template <typename T>
int MyVector<T>::find(const T& C) const{
  for (size_t i=0;i<_n;i++)    
    if (identique(C,_data[i])) return i;		
  return -1;
}


