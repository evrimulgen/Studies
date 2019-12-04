#include<iostream>
#inculde"noeud.h"



template <typename T>
Noeud<T> :: Noeud(){};

template <typename T>
Noeud<T> :: Noeud(*Noeud,*Noeud,T){gauche(NULL); droit(NULL); val(T);}

template <typename T>
Noeud<T> :: ~Noeud(){};

template <typename T>
T Noeud<T> :: &getval()const{ return val;}

template <typename T>
T Noeud<T> :: &setval(const T x){ val=x; return val;}


 }
