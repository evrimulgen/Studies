#ifndef __TABLEAUCELLULE__H
#define __TABLEAUCELLULE_H
#include"Cellule.h"


class TableauCellule{
 private:
  Cellule *   _data;
  size_t     _n;
  size_t _alloc;

  void extend();
 public:
  TableauCellule();
  TableauCellule(size_t);
  TableauCellule(const Cellule&);
  TableauCellule &operator=(const TableauCellule&);
  ~TableauCellule();
  size_t size()const;
  Cellule& at(size_t);
  const Cellule& at(size_t)const;
  void push_back(Cellule);
};

void write(std::ostream&, const TableauCellule&);

int rechrechedicho(TableauCellule t,Cellule c){
  for(size_t i=0;i<t.size();i++){
    

#endif



