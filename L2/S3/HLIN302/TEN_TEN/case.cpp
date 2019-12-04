#include<iostream>
#include"case.h"

using namespace std;


Case :: Case(){this->x=0; this->y=0;}
Case :: Case(int X,int Y) {this->x=X; this->y=Y;}

  //accesseur en écriture
void Case::SetX(int X){
  this->x=X;
}

void Case::SetY(int Y){
 this->y=Y;
}

 //accsesseur en lecture
int Case :: GetX ()const{return x;}
int Case :: GetY ()const{return y;}

void Case :: translation(int v,int u){
  this->x+=v;  this->y+=u; }
