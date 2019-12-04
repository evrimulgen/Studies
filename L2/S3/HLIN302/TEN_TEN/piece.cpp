#include<iostream>
#include"case.h"
#include"piece.h"

Piece :: Piece(){};

Piece :: Piece(int x,int y,int num){
  
  pivot.SetX(x); pivot.SetY(y);
  this->numero=num;
  switch ( num ) { 
  

  case 1:  {forme[0].SetX(x); forme[0].SetY(y);nbr_case=1; };break;
  case 6:  {forme[0].SetX(x); forme[0].SetY(y);nbr_case=1;};break;
  case 2: {for(int i=0;i<2;i++){if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(x);forme[i].SetY(++y);} this->nbr_case=2;} };break;
  case 7: {for(int i=0;i<2;i++) {if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(++x);forme[i].SetY(y);} this->nbr_case=2;} };break;
  case 3: {for(int i=0;i<3;i++) {if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(x);forme[i].SetY(++y);}  this->nbr_case=3;} };break;
  case 8: { for(int i=0;i<3;i++) {if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(++x);forme[i].SetY(y);} this->nbr_case=3;}};break;
  case 10:{ for(int i=0;i<3;i++){ if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else if (i >= 2) {forme[i].SetX(x); forme[i].SetY(++y);}else{forme[i].SetX(++x); forme[i].SetY(y);}this->nbr_case=3;}};break;
  case 11:{ for(int i=0;i<3;i++){ if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else if(i == 2) {forme[i].SetX(++x); forme[i].SetY(y);}else {forme[i].SetX(x); forme[i].SetY(y+=i);}this->nbr_case=3;}};break;
  case 4 :{for(int i=0;i<4;i++) {if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(x);forme[i].SetY(++y);} this->nbr_case=4;}};break;
  case 9 :{for(int i=0;i<4;i++){if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(++x);forme[i].SetY(y);} this->nbr_case=4;}};break;	    
  case 12:{for(int i=0;i<4;i++){ if ( i == 0){ forme[i].SetX(x); forme[i].SetY(y);}else if( i==2 ) {forme[i].SetX(++x); forme[i].SetY(y);}else {forme[i].SetX(x); forme[i].SetY(++y);}this->nbr_case=4;}};break;
  case 13:{ for(int i=0;i<4;i++){ if( i == 0 ){forme[i].SetX(x); forme[i].SetY(y);}else if(i == 3) {forme[i].SetX(x); forme[i].SetY(++y);}else{forme[i].SetX(++x); forme[i].SetY(y);}this->nbr_case=4;} };break;
  case 14:{forme[0].SetX(x); forme[0].SetY(y); forme[1].SetX(x+1); forme[1].SetY(y); forme[2].SetX(x); forme[2].SetY(y+1);
      forme[3].SetX(x+1); forme[3].SetY(y+1);this->nbr_case=4;};break;
  case  5: {for(int i=0;i<5;i++) {if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(x);forme[i].SetY(++y);}  this->nbr_case=5; }};break; } 	 
}
 
//accesseur en ecriture

void Piece :: SetPivot(int x,int y){
  pivot.SetX(x); pivot.SetY(y);
  Case* f=GetF();
      
  switch ( numero ){
  case 1:  {forme[0].SetX(x); forme[0].SetY(y);nbr_case=1;};break;
  case 6:  {forme[0].SetX(x); forme[0].SetY(y);nbr_case=1;};break;
  case 2: {for(int i=0;i<2;i++){if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(x);forme[i].SetY(++y);} this->nbr_case=2;}};break;
  case 7: {for(int i=0;i<2;i++) {if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(++x);forme[i].SetY(y);} this->nbr_case=2;}};break;
  case 3: {for(int i=0;i<3;i++) {if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(x);forme[i].SetY(++y);}  this->nbr_case=3;}};break;
  case 8: { for(int i=0;i<3;i++) {if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(++x);forme[i].SetY(y);} this->nbr_case=3;}};break;
  case 10:{ for(int i=0;i<3;i++){ if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else if (i >= 2) {forme[i].SetX(x); forme[i].SetY(++y);}else{forme[i].SetX(++x); forme[i].SetY(y);}this->nbr_case=3;}};break;
  case 11:{ for(int i=0;i<3;i++){ if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else if(i == 2) {forme[i].SetX(++x); forme[i].SetY(y);}else {forme[i].SetX(x); forme[i].SetY(y+=i);}this->nbr_case=3;}};break;
  case 4 :{for(int i=0;i<4;i++) {if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(x);forme[i].SetY(++y);} this->nbr_case=4;}};break;
  case 9 :{for(int i=0;i<4;i++){if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(++x);forme[i].SetY(y);} this->nbr_case=4;}};break;	    
  case 12:{for(int i=0;i<4;i++){ if ( i == 0){ forme[i].SetX(x); forme[i].SetY(y);}else if( i==2 ) {forme[i].SetX(++x); forme[i].SetY(y);}else {forme[i].SetX(x); forme[i].SetY(++y);}this->nbr_case=4;}};break;
  case 13:{ for(int i=0;i<4;i++){ if( i == 0 ){forme[i].SetX(x); forme[i].SetY(y);}else if(i == 3) {forme[i].SetX(x); forme[i].SetY(++y);}else{forme[i].SetX(++x); forme[i].SetY(y);}this->nbr_case=4;}};break;
  case 14:{forme[0].SetX(x); forme[0].SetY(y); forme[1].SetX(x+1); forme[1].SetY(y); forme[2].SetX(x); forme[2].SetY(y+1);
      forme[3].SetX(x+1); forme[3].SetY(y+1);this->nbr_case=4;};break;
  case  5: {for(int i=0;i<5;i++) {if (i == 0){forme[i].SetX(x); forme[i].SetY(y);}else{forme[i].SetX(x);forme[i].SetY(++y);}  this->nbr_case=5; }};break; } 	 

}

  

  

//accsesseur en lecture

Case Piece :: GetP()const{ return pivot;} 

Case* Piece ::GetF(){return forme;} 

int  Piece :: GetNb()const{return this->nbr_case;}  

int Piece :: GetNum()const{return this->numero;}


void Piece :: translation_P(int v,int u){
  int n=this->nbr_case;
  for (int i=0;i<n;i++)
    forme[i].translation(v,u); }
