#ifndef __CASIER6__H
#define __CASIER6__H

template<typename T>
class Casier6{
 private:
  T* cases[6];
 public:
  Casier6();
  virtual ~Casier6();
  virtual void range(T* produit,int numeroCase);
}
