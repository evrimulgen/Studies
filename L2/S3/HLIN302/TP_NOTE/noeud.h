#ifndef NOEUD_H
#define NOEUD_H



template <typename T> 
Class Noeud {
private :
T val ;
Noeud<T>∗ gauche;
Noeud<T>∗ droit;

 public:
 
 Noeud(const T&);
 Noeud(*Noeud,*Noeud,T);

 ~Noeud();


 T &getval()const;
 
 T &setval(const T x);


 };

#endif

#include"noeud.tcc"
