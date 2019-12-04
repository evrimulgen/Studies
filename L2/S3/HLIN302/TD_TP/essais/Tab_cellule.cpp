#include"Cellule.h"
#include"Tab_cellule.h"



void TableauCellule::extend() {
  if (_n<_alloc) return;
  _alloc=2*_n;
  Cellule* tmp=new Cellule[_alloc];
  for(size_t i=0;i<_n;i++){tmp[i]=_data[i];}
  delete[] _data;
  _data=tmp;
}
TableauCellule::TableauCellule() : _data(new Cellule[1]), _n(0), _alloc(1) {}

TableauCellule::TableauCellule(size_t n) : _data(new Cellule[n]), _n(n), _alloc(n) {}

TableauCellule::TableauCellule(const TableauCellule& T): _data(new Cellule[T._n]), _n(T._n), _alloc(_n) {
  for(size_t i=0;i<_n;i++)
    _data[i]=T._data[i];
}

TableauCellule& TableauCellule::operator=(const TableauCellule& T){
  if (this!= &T){
    delete[] _data;
    _data=new Cellule[T._n];
    _n=T._n;
    _alloc=_n;
    for(size_t i=0;i<_n;i++)
      _data[i]=T._data[i];    
  }
  return *this;
}
TableauCellule::~TableauCellule(){delete[] _data;}

size_t TableauCellule::size()const {return _n;}

Cellule& TableauCellule::at(size_t i) {return _data[i];}

const Cellule& TableauCellule::at(size_t i)const {return _data[i];}

void TableauCellule::push_back(Cellule x) {
  extend();
  _data[_n]=x;
  _n++;
}
  
