#include "window.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void positionner(Color *PieceMenu,Piece* piecechoisie,Window* menuchoisie,Window* menuchoix,Window* menudest){

int x,y;
Piece nouvellepiece(0,0,rand()%15+1);
menuchoix->clear();
menuchoix->print(1,1,"Entrez la coordonnées x de la pièce");
cin>>x;
menuchoix->clear();
menuchoix->print(1,1,"Entrez la coordonnées y de la pièce");
cin>>y;
menuchoix->clear();
menudest->print(*piecechoisie,x,y);
menuchoix->print(1,1,"Tapez 1,2 ou 3 pour     placés la pièces choisies");
menuchoisie->clear();
menuchoisie->print(nouvellepiece,(menuchoisie->getLargeur()/2),(menuchoisie->getHauteur()/2),*PieceMenu);


  return;
}

void myprogram(){
  Piece piecechoisie();
  Window menuchoisie();
  srand(time(NULL));
  int ch;
  int h=10,w=10;
  Window menu(3,30,3,1);
  Window plateau(h,w,10,7);
  
  Window menu1(7,7,2,20);
  Window menu2(7,7,11,20);
  Window menu3(7,7,20,20);

  Window menuchoix(4,26,2,30);
  menuchoix.print(1,1,"Tapez 1,2 ou 3 pour placés la pièces choisies");


  
  //Initialisation des pièces dans leurs menus aléatoirement
  Color PieceMenu=WGREEN;
  Piece p1(0,0,rand()%15+1);
  menu1.print(p1,(menu1.getLargeur()/2),(menu1.getHauteur()/2),PieceMenu);
  Piece p2(0,0,rand()%15+1);
  menu2.print(p2,(menu2.getLargeur()/2),(menu2.getHauteur()/2),PieceMenu);
  Piece p3(0,0,rand()%15+1);
  menu3.print(p3,(menu3.getLargeur()/2),(menu3.getHauteur()/2),PieceMenu);




  menu.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BBLUE);


  menu.print(1,1,"Tapez q pour quitter !!!",WRED);

  Color col=WBLUE;
  



  while((ch = getch()) != 'q')
    {
      switch (ch) {
      case '1':
      positionner(&PieceMenu,&p1,&menu1,&menuchoix,&plateau);
  break;
      case '2':
      positionner(&PieceMenu,&p2,&menu2,&menuchoix,&plateau);
  break;
      case'3':
      positionner(&PieceMenu,&p3,&menu3,&menuchoix,&plateau);
      case 'c':
      plateau.clear();
  break;
      case KEY_UP:
      plateau.print(1,1,"WESH");
       
  break;
      case KEY_DOWN:
      plateau.clear();
       
  break;
      case KEY_LEFT:

  break;
      case KEY_RIGHT:/*
  jeu.deplace(p1);
       p1.translation_P(1,0);
  jeu.print(p1);*/
  break;
   case '\n':
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
   /** Piece p(5,5,13);
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


  
  // Window menu(30,20,5,1);

  // std :: cout << menu.getX() << ";"  << menu.getY() <<";" <<    menu.getHauteur() <<";" <<  menu. getLargeur() << std::endl;
  */
  return 0;
}
