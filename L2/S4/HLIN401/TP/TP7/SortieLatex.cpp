//SortieLatex.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>

typedef int Valeur;

class SommetABR;

typedef SommetABR* ABR;

void SortieLatex(ABR Ar,std::string filepath);

class SommetABR {
  protected: 	
  Valeur racine;
  ABR Pere,SAG,SAD;
  bool FGP; 

  // Unused:
  // int hauteur,balanceGmoinsD;

  public:
  SommetABR(Valeur v);
  SommetABR(SommetABR& s);

  ABR remonterToutEnHaut();

  void GrefferSAG(ABR g);
  void GrefferSAD(ABR d);

  void SupprimerSAG();
  void SupprimerSAD();

  bool FeuilleP();

  void RemplacerPourLePerePar(ABR);

  friend std::string* TikzRecursABR(int ligne,int gauche, int droite, int numeroPere, int typeFils, ABR Ar);


};

std::string* TikzRecursABR(int ligne,int gauche, int droite, int numeroPere, int typeFils, ABR Ar);



std::string * TikzRecursABR(int ligne,int gauche, int droite, int numeroPere, int typeFils, ABR Ar){
  std::ostringstream ossnum, osslign,osscol,ossnumPere, ossbal, ossnum2Pere,ossnumRac;

      std::string stres("");

      if (Ar) {
    ossnumPere<<numeroPere;
    ossnumRac<<"(\\textcolor{red}{" << Ar->racine << "})\\\\this=\\textcolor{red}{" <<Ar <<"}\\\\Pere=\\textcolor{red}{"<<Ar->Pere << "} (FGP=\\textcolor{red}{" << (Ar->FGP?"Gauche":"Droit") <<"})";

    if (Ar->Pere )ossnum2Pere<<Ar->Pere->racine; else ossnum2Pere<<0;

    int numero;
    if (typeFils==-1) { numero=1; } else { numero= 2*numeroPere + typeFils; }
    ossnum<<numero;
    osslign<<ligne;
    int mil = (gauche + droite)/2;

    osscol<<mil;

    stres="\\node[draw, color=black, rounded corners=5pt, text width=3cm, text centered] (SZ" + ossnum.str()    + ") at " +
	  "("   + osscol.str()    + ", " + osslign.str() + ") " + 
	  "{ "  + ossnumRac.str() + "};\n";

    if (typeFils!=-1) stres+="\\draw[->, >=latex, color=blue] (SZ"+ossnumPere.str()+") -- (SZ"+ossnum.str() +");\n";

    if (Ar->SAG) stres+=*TikzRecursABR(ligne-3,gauche,mil-13,numero,0,Ar->SAG);
    if (Ar->SAD) stres+=*TikzRecursABR(ligne-3,mil+13,droite,numero,1,Ar->SAD); 
 }
  return new std::string(stres);
}

std::string * TikzABR(ABR Ar){
  return TikzRecursABR(1,1,10,1,-1,Ar);
}

 void SortieLatex(ABR Ar, std::string filepath){ //don't insert garbage in filepath, its std::system-ised.
 std::ofstream fichier(filepath.c_str(), std::ios::out | std::ios::trunc);
 std::string preamb ("\\documentclass{article} \n \\usepackage{tikz} \n \\begin{document} \n \\resizebox{300pt}{!}{\n \\begin{tikzpicture}\n");
  std::cout<<preamb<<"\n";
std::string post("\\end{tikzpicture}\n } \\end{document} \n"); //rsz box end?
  std::cout<<post<<"\n";
 std::cout<<*TikzABR(Ar)<<"\n";
std::string   res1(preamb + *TikzABR(Ar));
 std::string   res(res1 + post);
 //std::cout<<res1<<"\n";
  fichier <<res<<"\n";
  fichier.close();

  std::ostringstream system_CARE;
  // /dev/null 2>&1 isnt enough to mute pdflatex...
  system_CARE << "mkdir pdflatex_temp > /dev/null 2>&1;" 
              << "pdflatex -output-directory=\"./pdflatex_temp\" -interaction=nonstopmode \"" << filepath << "\" >/dev/null 2>&1;"
	      << "mv ./pdflatex_temp/*.pdf ./ > /dev/null 2>&1;";
  std::system(system_CARE.str().c_str());
  return;
}



// g++ -c SortieLatex.cpp
