#include "window.h"
#include<iostream>

void myprogram(){
  int ch;
  int h=10,w=10;
  Window menu(2,30,5,3);
  Window jeu(40,40,1,1);
  Window plateau(h,w,5,10);
  Window vide(6,6,20,22);
  Window vide_1(6,6,20,10);
  Window vide_2(6,6,8,22);
  menu.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BBLUE);
  vide.setCouleurBordure(BBLUE);
  vide_1.setCouleurBordure(BRED);
  vide_2.setCouleurBordure(BRED);
  menu.print(1,1,"Tapez q pour quitter !!!",WRED);
  
  
  Piece p1(3,3,2);
  Piece p2(2,2,3);
  Piece p3(2,2,9);
  Color col=WBLUE;
  vide.print(p1);
  vide_1.print(p2);
  vide_2.print(p3);
  while((ch = getch()) != 'q')
    {
      switch (ch) {
      case '1':
	col=BMAGENTA;
	break;
      case '2':
	col=WCYAN;
	break;
      case 'c':
	plateau.clear();
	break;
      case KEY_UP:
	jeu.deplace(p1);
	p1.translation_P(0,-1);
	jeu.print(p1);
	break;
      case KEY_DOWN:
	jeu.deplace(p1);
	p1.translation_P(0,1);
	jeu.print(p1);
	break;
      case KEY_LEFT:
	jeu.deplace(p1);
      	p1.translation_P(-1,0);
        jeu.print(p1);
	break;
      case KEY_RIGHT:
	jeu.deplace(p1);
       p1.translation_P(1,0);
	jeu.print(p1);
	break;
	 case '\n':
	p1.SetPivot(26,26);
	vide.clear();
       	vide.print(p1);
	break;
	 case '\t':
	Color tmp= menu.getCouleurBordure();
	menu.setCouleurBordure(plateau.getCouleurBordure());
	plateau.setCouleurBordure(tmp);
	break;
      }
    }
}

int main(){
   startProgramX();
   myprogram();
   stopProgramX();
   /*   Piece p(1,2,13);
  std :: cout << p.GetP().GetX() << ";" << p.GetP().GetY() <<std::endl;
  std :: cout << p.GetNb() << std :: endl;
   Case* f=p.GetF();
 
  for(int i=0;i<p.GetNb();i++){
   std :: cout << f[i].GetX() <<";"<<  f[i].GetY() << std :: endl;
   }

  p.SetPivot(8,8);
  

  std :: cout << "après chagement de pivot"<< std :: endl;
  
  
  for(int i=0;i<p.GetNb();i++){
   std :: cout << f[i].GetX() <<";"<<  f[i].GetY() << std :: endl;
   }


  
   Window menu(30,20,5,1);

   std :: cout << menu.getX() << ";"  << menu.getY() <<";" <<    menu.getHauteur() <<";" <<  menu. getLargeur() << std::endl;
   */
  return 0;
}

