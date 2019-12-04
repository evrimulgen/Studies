#ifndef CASE_H
#define CASE_H



#include<iostream>


class Case{
 private:
  int x,y;

 public:

  Case();
  Case(int,int);

  //accesseur en écriture
 void SetX(int);
 void SetY(int);

 //accsesseur en lecture
 int GetX () const;
 int GetY () const;

 void translation(int,int);


}

;
#endif
