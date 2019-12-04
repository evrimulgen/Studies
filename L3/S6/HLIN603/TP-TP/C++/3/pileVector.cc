#include<iostream>
using namespace std;
#include<string>
#include<vector>

//Atom

template<typename T>
class Pile : private vector<T>
{
public:
  virtual void empiler(T t);
  virtual void empiler(T t,string s);
  virtual void depiler();
  virtual T sommet();
  virtual T base();
  virtual void affiche(ostream & os);
  using vector<T>::size;
  using vector<T>::empty;
  // ou garder ces 2 méthodes plutot qu'emplier et  depiler
  using vector<T>::pop_back;
  using vector<T>::push_back;
  using vector<T>::end;
};

template<typename T>
class pileSpeciale : private Pile<T>
{
public : 
  using Pile<T>::empiler;
  
};


template<typename T>
void Pile<T>:: empiler(T t){this->push_back(t);}


template<typename T>
void Pile<T>:: empiler(T t,string s){this->push_back(t);}


template<typename T>
void Pile<T>:: depiler(){this->pop_back();}

template<typename T>
T Pile<T>:: sommet(){return *(this->begin());}  

template<typename T>
void Pile<T>:: affiche(ostream & os){for(int i=0;i<size();i++) os << (*this)[i]<<" ";}

template<typename T>
T Pile<T>:: base(){return *(this->end());}  


int main()
{
  Pile<int> p;
  p.empiler(2);
  p.empiler(4);
  p.empiler(6);
  p.empiler(8);
  p.empiler(10);
  p.depiler();
  p.affiche(cout);
  cout << p.base() << endl;
  cout << endl << p.size() << endl;

  pileSpeciale<int> r;
  r.empiler(2);
  r.empiler(4, "adel");

  return 0;
}
