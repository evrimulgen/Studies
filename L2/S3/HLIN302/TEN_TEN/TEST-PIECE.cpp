#include "window.h"
#include "PIECE_Z.h"
#include <stdlib.h>
#include <ctime> 
#include <iostream>
#include <ctype.h>

void myprogram(){
  int ch;
  int chAbs;
  int chOrd;
  int h=10,w=10;
  bool isMauvaiseCordonnee = false;
  Window menu(3,30,1,0);
  Window plateau(h,w,15,6);
  Window piecesSuivante1(5,5,1,20);
  Window piecesSuivante2(5,5,15,20);
  Window piecesSuivante3(5,5,29,20);
 
  Window tableauErreur(30,40,45,6);

  menu.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BBLUE);
  std::string message = "Tapez q pour quitter !!!";
  piecesSuivante1.setCouleurBordure(WGREEN);
  piecesSuivante2.setCouleurBordure(WGREEN);
  piecesSuivante3.setCouleurBordure(WGREEN);
  tableauErreur.setCouleurBordure(WRED);
  srand((unsigned)time(0)); 
  //Piece::Color coule = Piece::WRED; 
  //Piece currentPiece = Piece(Piece::WRED, 5, 2,2,0, 0, false); 
  //Piece(Color coul, unsigned int nbr, unsigned int abs, unsigned int ord, unsigned int abs2, unsigned int ord2, bool yFrst  )
  Piece piece1 = Piece(Piece::WRED,0);
  Piece piece2 = Piece(Piece::WRED,0);
  Piece piece3 = Piece(Piece::WRED,0);
  menu.print(1,1, message ,WRED);

  int tab[3];
  char tableauReel[5][5];
  std::list<std::pair<int, int> >::iterator it;
  while (true)
  {
     if(isMauvaiseCordonnee == false)
     {
        for(int i=0; i<3; i ++)
        {  
           tab[i]=(rand() % 14) + 1;
        }
     
      
        piece1 = Piece(Piece::WRED,tab[0]);
        piece2 = Piece(Piece::WRED,tab[1]);
        piece3 = Piece(Piece::WRED,tab[2]);
     }
     isMauvaiseCordonnee = false;
     //print each element in piece windows

     std::list<std::pair<int,int> > testList1 = piece1.getListeCoordonnees();
     piecesSuivante1.clear();
     for (it=testList1.begin(); it!=testList1.end(); ++it)
     {        
        piecesSuivante1.print(it->first, it->second,'X',WRED);
     }
     //piecesSuivante1.print(1, 1,'X',WGREEN);


     std::list<std::pair<int,int> > testList2 = piece2.getListeCoordonnees();
     piecesSuivante2.clear();
     for (it=testList2.begin(); it!=testList2.end(); ++it)
     {
        piecesSuivante2.print(it->first, it->second,'X',WRED);
     }
     
     piecesSuivante3.clear();
     std::list<std::pair<int,int> > testList3 = piece3.getListeCoordonnees();
     for (it=testList3.begin(); it!=testList3.end(); ++it)
     {
        piecesSuivante3.print(it->first, it->second,'X',WRED);
     }
     //piecesSuivante1.print(0,0,p,col);
     //piecesSuivante2.print(0,0,p,col);
     //piecesSuivante1.print(0,0,p,col);
     tableauErreur.clear();
     for(int i=0;i<3;i++)
     {
     
        std::string input = "";
        //getline(std::cin, input);
        //std::cout << "You entered: " << input << std::endl;
        tableauErreur.print(0,0,"Entrez l'abscisse du pivot de la figure au format x ",WRED);
        //std::cout << "Entrez l'abcisse du pivot de la figure au format x "<< std::endl;
        chAbs = getchar();
        if(chAbs == 'q' )
        {
          //tableauErreur.clear();
          tableauErreur.print(0,0,"vous avez decide de quitter",WRED);
          break;
        }
        else if(!isdigit(chAbs))
        {
           //tableauErreur.clear();
           tableauErreur.print(0,0,"vous avez rentre de  mauvaises coordonnees abscisse",WRED);
           isMauvaiseCordonnee = true;
           break;
        }

        //tableauErreur.clear();
        tableauErreur.print(0,0,"Entrez l'ordonnee du pivot de la figure au format y",WRED);
        chOrd = getchar();
        if(chOrd == 'q' )
        { 
          //tableauErreur.clear();
          tableauErreur.print(0,0,"vous avez decide de quitter",WRED);
          break;
        }
        else if(!isdigit(chOrd))
        {
           //tableauErreur.clear();
           tableauErreur.print(0,0,"vous avez rentre de  mauvaises coordonnees ordonnee",WRED);
           isMauvaiseCordonnee = true;
           break;
        }
        
         

       int abscisse = (int)((char)chAbs - '0');
       int ordonnee = (int)((char)chOrd - '0');

       if(abscisse < 0 || abscisse > 5 || ordonnee < 0 || ordonnee > 5 )
       {
          //tableauErreur.clear();
          tableauErreur.print(0,0,"vous avez rentre de  mauvaises coordonnees",WRED);
          isMauvaiseCordonnee = true;
          break;
       }

       if (i == 0)
       { 
          bool bonnePosition = true;
          int newAbs;
          int newOrd;
          for (it=testList1.begin(); it!=testList1.end(); ++it)
          {
             newAbs = abscisse + it->first;
             newOrd = ordonnee + it->second;
             if(newAbs > 10 || newOrd > 10)
             {
                //tableauErreur.clear();
                tableauErreur.print(0,0,"la position choisie pour la piece 1 \n est mettrai la piece hors des bornes du tableau.\n Choisir une autre position.",WRED);
                isMauvaiseCordonnee = true;
                break;
             }
             char point = tableauReel[newAbs][newOrd];
             if(point == 'X')
             {
                //plateau.print(newAbs, newOrd,'X',WGREEN);
                //tableauReel[newAbs][newOrd] = 'X';
                bonnePosition = false;
             }
             /*else
             {
                //tableauErreur.clear();
                tableauErreur.print(0,0,"la position choisie pour la piece 1\n est deja utilisee dans le tableau.\n Choisir une autre position.",WRED);
                isMauvaiseCordonnee = true;
                break;
             }*/
          }
          for (it=testList1.begin(); it!=testList1.end(); ++it)
          {
             newAbs = abscisse + it->first;
             newOrd = ordonnee + it->second;
             if(bonnePosition == true)
             {
                plateau.print(newAbs, newOrd,'X',WGREEN);
                tableauReel[newAbs][newOrd] = 'X';
             }
             else
             {
                //tableauErreur.clear();
                tableauErreur.print(0,0,"la position choisie pour la piece 1\n est deja utilisee dans le tableau.\n Choisir une autre position.",WRED);
                isMauvaiseCordonnee = true;
                break;
             }
          }
          /*if(isMauvaiseCordonnee == true)
          {
             break;
          }*/

       }
       if (i == 1)
       {
          bool bonnePosition = true;
          int newAbs;
          int newOrd;
          for (it=testList2.begin(); it!=testList2.end(); ++it)
          {
             newAbs = abscisse + it->first;
             newOrd = ordonnee + it->second;
             if(newAbs > 10 || newOrd > 10)
             {
                //tableauErreur.clear();

                tableauErreur.print(0,0,"la position choisie pour la piece 2 est mettrai \nla piece hors des bornes du tableau.\n Choisir une autre position.",WRED);
                isMauvaiseCordonnee = true;
                break;
             }
             char point = tableauReel[newAbs][newOrd];
             if(point == 'X')
             {
                //plateau.print(newAbs, newOrd,'X',WGREEN);
                //tableauReel[newAbs][newOrd] = 'X';
                bonnePosition = false;
             }
             /*else
             {
                //tableauErreur.clear();
                tableauErreur.print(0,0,"la position choisie pour la piece 2 \nest deja utilisee dans le tableau.\n Choisir une autre position.",WRED);
                isMauvaiseCordonnee = true;
                break;
             }*/
          }
          for (it=testList2.begin(); it!=testList2.end(); ++it)
          {
             newAbs = abscisse + it->first;
             newOrd = ordonnee + it->second;
             if(bonnePosition == true)
             {
                plateau.print(newAbs, newOrd,'X',WGREEN);
                tableauReel[newAbs][newOrd] = 'X';
             }
             else
             {
                //tableauErreur.clear();
                tableauErreur.print(0,0,"la position choisie pour la piece 2\n est deja utilisee dans le tableau.\n Choisir une autre position.",WRED);
                isMauvaiseCordonnee = true;
                break;
             }
          }
          /*if(isMauvaiseCordonnee == true)
          {
             break;
          }*/

         
       }
       
       if (i == 2)
       {
          bool bonnePosition = true;
          int newAbs;
          int newOrd;
          for (it=testList3.begin(); it!=testList3.end(); ++it)
          {
             newAbs = abscisse + it->first;
             newOrd = ordonnee + it->second;
             if(newAbs > 10 || newOrd > 10)
             {
                //tableauErreur.clear();
                tableauErreur.print(0,0,"la position choisie pour la piece 3 est mettrai la piece hors des bornes du tableau. Choisir une autre position.",WRED);
                isMauvaiseCordonnee = true;
                break;
             }
             char point = tableauReel[newAbs][newOrd];
             if(point == 'X')
             {
                //plateau.print(newAbs, newOrd,'X',WGREEN);
                //tableauReel[newAbs][newOrd] = 'X';
                bonnePosition = false;
             }
             /*else
             {
                //tableauErreur.clear();
                tableauErreur.print(0,1,"la position choisie pour la piece 3 est deja utilisee dans le tableau. Choisir une autre position.",WRED);
                isMauvaiseCordonnee = true;
                break;
             } */
          }
          for (it=testList3.begin(); it!=testList3.end(); ++it)
          {
             newAbs = abscisse + it->first;
             newOrd = ordonnee + it->second;
             if(bonnePosition == true)
             {
                plateau.print(newAbs, newOrd,'X',WGREEN);
                tableauReel[newAbs][newOrd] = 'X';
             }
             else
             {
                //tableauErreur.clear();
                tableauErreur.print(0,2,"la position choisie pour la piece 3\n est deja utilisee dans le tableau.\n Choisir une autre position.",WRED);
                isMauvaiseCordonnee = true;
                break;
             }
          }
          /*if(isMauvaiseCordonnee == true)
          {
             break;
          }*/
       }



     } 

     if(chAbs == 'q' || chOrd == 'q' )
     {
        break;
     }



  }
 
}

int main(){
  startProgramX();
  myprogram();
  stopProgramX();
  return 0;
}
