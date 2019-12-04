#include "myvector.h"
#include <iostream>

TableauCellule::MyVector() : _data(NULL), _n(0), _alloc(0) {}

MyVector::MyVector(size_t n) : _data(new T[n]), _n(n), _alloc(n) {}

MyVector::MyVector(const MyVector& T) : _data(new T[T._n]), _n(T._n), _alloc(_n)
{
  for(size_t i=0;i<_n;i++){
    _data[i]=T._data[i];
  }
}
MyVector::~MyVector(){ delete[] _data;}
  
MyVector& MyVector::operator=(const MyVector& T)
{
  if (this!=&T){
    delete[] _data;
    _data=new MyVector[T._n];
    _n=T._n;
    _alloc=_n;
    for(size_t i=0;i<_n;i++){
      _data[i]=T._data[i];
    }    
  }
  return *this;
}


T& MyVector::at(size_t i)      {return _data[i];}
const T& MyVector::at(size_t i) const  {return _data[i];}

size_t MyVector::size()const {return _n;}



void MyVector::extend(){
  if (_n<_alloc) return;
  _alloc=2*_n;
  T* tmp=new T[_alloc];
  for(size_t i=0;i<_n;i++){tmp[i]=_data[i];}
  delete[] _data;
  _data=tmp;
}

void MyVector::push_back(const Extensible& C){
  extend();
  _data[_n]=C;
  _n++;
}

void MyVector::erase(int idx){
  if (idx>=0 && idx<(int)_n){
    for(size_t i=idx;i<_n-1;i++)
      _data[i]=_data[i+1];
    _n--;
  }  
}
  

int MyVector::find(const T& C) const{
  for (size_t i=0;i<_n;i++)    
    if (identique(C,_data[i])) return i;		
  return -1;
}

class f{
  size_t _n; T *_data;
  T* find(const T& C) {
    for (size_t i=0;i<_n;i++)    
      if (identique(C,_data[i])) return _data+i;		
    return NULL;
  }
};
