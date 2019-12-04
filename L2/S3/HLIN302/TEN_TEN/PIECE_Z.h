
 

#ifndef __PIECE__H
#define __PIECE__H
  

#include<string>
#include <list>
#include <iostream>
class Piece{
  

 public:
  
  enum Color {
  WBLACK,  // couleur fond = noir ,   couleur texte = blanc
  WCYAN,   // couleur fond = cyan,    couleur texte = blanc
  WBLUE,   // couleur fond = bleu,    couleur texte = blanc
  WYELLOW, // couleur fond = jaune,   couleur texte = blanc
  WGREEN,  // couleur fond = vert,    couleur texte = blanc
  WMAGENTA,// couleur fond = magenta, couleur texte = blanc
  WRED,	   // couleur fond = rouge,   couleur texte = blanc
  BWHITE,  // couleur fond = blanc,   couleur texte = blanc
  BCYAN,   // couleur fond = cyan,    couleur texte = noir
  BBLUE,   // couleur fond = bleu,    couleur texte = noir
  BYELLOW, // couleur fond = jaune,   couleur texte = noir
  BGREEN,  // couleur fond = vert,    couleur texte = noir 
  BMAGENTA,// couleur fond = magenta, couleur texte = noir
  BRED    // couleur fond = rouge,   couleur texte = noir
};
  

 private:
  unsigned int pieceNbr;
  char pivot;
  Color couleur;
  std::list<std::pair<int,int> > listeCoordonnees;
  

 public:
 Piece(Color coul, unsigned int piece  )
 {
    couleur = coul;
    pieceNbr = piece;
    if(pieceNbr == 1)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
    }
    else if(pieceNbr == 2)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,1));
       listeCoordonnees.push_back(tmpPair);
    }
    else if(pieceNbr == 3)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,1));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,2));
       listeCoordonnees.push_back(tmpPair);
    }
    else if(pieceNbr == 4)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,1));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,2));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,3));
       listeCoordonnees.push_back(tmpPair);
    }
    else if(pieceNbr == 5)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,1));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,2));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,3));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,4));
       listeCoordonnees.push_back(tmpPair);
    }
    else if(pieceNbr == 6)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
    }
    else if(pieceNbr == 7)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(1,0));
       listeCoordonnees.push_back(tmpPair);
    }
    else if(pieceNbr == 8)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(1,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(2,0));
       listeCoordonnees.push_back(tmpPair);
    }
    else if(pieceNbr == 9)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(1,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(2,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(3,0));
       listeCoordonnees.push_back(tmpPair);
        
    }
    else if(pieceNbr == 10)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(1,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(1,1));
       listeCoordonnees.push_back(tmpPair);
    }
    else if(pieceNbr == 11)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,1));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(1,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(1,1));
       listeCoordonnees.push_back(tmpPair);
    }
    else if(pieceNbr == 12)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,1));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(1,1));
       listeCoordonnees.push_back(tmpPair);
    }
    else if(pieceNbr == 13)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(1,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(2,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(2,1));
       listeCoordonnees.push_back(tmpPair);
    }
    else if(pieceNbr == 14)
    {
       std::pair<int,int> tmpPair = (std::pair<int,int>(0,0));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(0,1));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(1,1));
       listeCoordonnees.push_back(tmpPair);
       tmpPair = (std::pair<int,int>(1,2));
       listeCoordonnees.push_back(tmpPair);
    } 
    else
    {}
    pivot = 'X';
 };
 
 unsigned int getPieceNbr()
 {
   return pieceNbr;
 };
  

 std::list<std::pair<int,int> > getListeCoordonnees()
 {
   std::cout<<"Test12"<<std::endl; 
   return listeCoordonnees;
 };
  
  
 Color getCouleur()
 {
   return couleur;
 };
 
  
 };

 #endif

