#ifndef   _PIECE_H  
#define   _PIECE_H


#include<iostream>
#include"case.h"



class Piece {

 private :
  Case pivot;
  Case forme[5];
  int  nbr_case;
  int numero;
  

 public :
  
  Piece();
  Piece(int,int,int);

  //accesseur en ecriture

  void SetPivot(int,int);
  void SetForme(Case*);
  void SetNbrC(int);
  
  //accsesseur en lecture

  Case GetP() const;
  Case* GetF();
  int GetNb() const;
  int  GetNum()const;
  void translation_P(int,int);

  

};

#endif
