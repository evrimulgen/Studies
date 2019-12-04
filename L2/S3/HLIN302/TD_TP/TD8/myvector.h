#ifndef MY_VECTOR_H
#define MY_VECTOR_H


#include <iostream>
template <typename T>
class MyVector{

 private:
   T  *_data;
  size_t   _n;
  size_t   _alloc;

  void extend();
 public:

  MyVector<T>();
  MyVector<T>(size_t);
  MyVector<T>(const MyVector<T>&);
  ~MyVector<T>();
  
  MyVector<T>& operator=(const MyVector<T>&);
  
  T   &at(size_t);
  const T&  at(size_t) const;

  size_t size()const;

  void read(std::istream&);
  void write(std::ostream&)const;

  void push_back(const T&); // add the cell at the end (possibly extend array)
  
  void erase(int);          // remove the element at the given position
  int  find(const T&) const; // return the position of the cell or -1
  
};







template <typename T>
bool identique(const T&,const T&);

#endif

#include"myvector.tcc"
