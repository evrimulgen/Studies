#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <fstream>
#include <time.h>
#include <stack>
using namespace std;


bool isin(vector<int>voisins[],int a,int x)
{
    bool tr=false;
    for(int i=0;i<voisins[a].size();i++)
        if ( x == voisins[a].at(i) )
            tr=true;
    return tr;
}


void voisins2arete(int n,vector<int>voisins[],int arete[][2])
{
    int x=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<voisins[i].size();j++)
        {
            arete[x][0]=i;
            arete[x][1]=voisins[i].at(j);
            x++;
        }
    }

}

void voisinsRandom(int n, int m, vector<int>voisins[])
{
    srand((unsigned)time(NULL));
    int i=0;
    while(i<m)
      {
        int x=rand()%n;
        int y=rand()%n;
        if( x!= y)
        {
            if(!isin(voisins,x,y))
            {
                voisins[x].push_back(y);
                voisins[y].push_back(x);
                i++;
            }
        }
      }

}

void parcoursLargeur(int n,vector<int> voisins[], int niveau[], int ordre[], int pere[])
{

    int DejaVu[n]={0};
    pere[0]=0;
    ordre[0]=1;
    niveau[0]=0;
    DejaVu[0]=1;
    int t=2;
    queue<int> AT;
    AT.push(0);

  while ( ! AT.empty() )
 {
    int v=AT.front();
    AT.pop();
    for (int a=0;a < voisins[v].size() ; a++)
    {
        if (DejaVu[voisins[v].at(a)] == 0)
        {
            int x= voisins[v].at(a);
            DejaVu[x] =1;
            AT.push(x);
            ordre[x]=t;
            t++;
            pere[x]=v;
            niveau[x]=niveau[v]+1;

        }
    }
}
}


int ecritureNiveaux(int n, int niveau[])
{
    int  rep[n]={0};
    int nbr_niv=niveau[0];
    for(int i=1;i<n;i++)
        if (nbr_niv < niveau[i])
            nbr_niv=niveau[i];

    nbr_niv=nbr_niv+1; //le plus petit niveau étant 0
    for(int i=0;i < n ;i++)
        rep[niveau[i]]++;

    for(int j=0;j < nbr_niv ;j++)
        cout << "il y a  "<< rep[j] <<" sommets au niveau " << j <<endl;

    return nbr_niv;
}

void parcoursProfondeur(int n,vector<int> voisins[],int pere[],int niveau[],int debut[],int fin[])
{

int DejaVu[n]={0};
niveau[0]=0;

DejaVu[0]=1; debut[0]=1; pere[0]=0;
stack<int> AT;
AT.push(0);
int t=2;

    while (! AT.empty())
    {
        int x = AT.top();
        if(voisins[x].empty())
         {
            AT.pop();
            fin[x]=t; t++;
         }
         else
         {
            int y=voisins[x].front();
            voisins[x].erase(voisins[x].begin());
            if(DejaVu[y] == 0)
            {
                DejaVu[y]=1;
                AT.push(y);
                debut[y]=1;
                t++;
                pere[y]=x;
                niveau[y]=niveau[x]+1;
                cout << "niveau_P"<<niveau[y] << endl;

            }
         }
    }

}

int niveauMax(int n,int niveau[])
{
    int maxi=niveau[0];
    for(int i=1;i<n;i++)
        if(maxi<niveau[i])
            maxi=niveau[i];

     return maxi;
}

void Arbre(int n,int nbr_niv,int niveau[],int pere[],int arbre[][2],int &nb)
{
    vector<int> niv[nbr_niv];
    for(int i=0;i<n;i++)
        niv[niveau[i]].push_back(i);

    int x=0;
    for(int i=1;i<nbr_niv;i++)
        for(int j=0;j<niv[i].size();j++)
        {
                arbre[x][0]=pere[niv[i][j]];
                arbre[x][1]=niv[i][j];
                x++;
        }
    nb=x;
}

void affichageGraphique(int n,int m,int arbre [][2],string name)
{
                                                                // les points et l'arbre de Kruskal.
 ofstream output;
 output.open(name.c_str(),ios::out);
 output << " graph {" <<endl;
 for(int i=0;i<n;i++)
     output <<i<<";"<<endl;
 for(int i=0;i<m;i++)
        output <<arbre[i][0]<<" --"<< arbre[i][1]<<";"<<endl;
 output << "}" <<endl;
}



int main()
{
  int n;                                    // Le nombre de sommets.
  int m;                                    // Le nombre d'aretes.
  cout << "Entrer le nombre de sommets: ";
  cin >> n;
  cout << "Entrer le nombre d'aretes: ";
  cin >> m;
  vector<int> voisins[n];                   // Les listes des voisins.
  int pere_L[n]={0};
  int pere_P[n]={0};                              // L'arbre en largeur.
  int ordre[n]={0};                             // L'ordre de parcours.
  int niveau_L[n]={0};
  int niveau_P[n]={0};
  int debut[n]={0};
  int fin [n]={0};
  int nbr_niv_p=0;
  int nbr_niv_l=0;
  int aretes [m][2];
  int arbreL[n][2]={0};
  int arbreP[n][2]={0};
  int nb_arc_L=0;
  int nb_arc_P=0;
                      // Le niveau du point.

  voisinsRandom(n,m,voisins);
  for(size_t i=0;i<n;i++)
    {
        cout <<"voisins["<<i<<"] = ";
         for(size_t k=0;k<voisins[i].size();k++)
        {
            cout << voisins[i].at(k) << "  " ;
        }
      cout << endl;
    }
  voisins2arete(n,voisins,aretes);
  affichageGraphique(n,m,aretes,"graphe.dot"); //le graphe à parcourir
    cout << "Parcours en largeur " << endl;
parcoursLargeur(n,voisins,niveau_L,ordre,pere_L);
cout << "le niveau max dans le parcours en Largeur" << niveauMax(n,niveau_L) <<endl;
nbr_niv_l=ecritureNiveaux(n,niveau_L);
Arbre(n,nbr_niv_l,niveau_L,pere_L,arbreL,nb_arc_L);
for(int i=0;i<nb_arc_L;i++)
    cout << "arbreL["<<i <<"]"<<"["<<0<<"]="<< arbreL[i][0] << "\t" <<"arbreL["<<i <<"]"<<"["<<1<<"]="<< arbreL[i][1] <<endl;
affichageGraphique(n,nb_arc_L,arbreL,"parcoursLargeur.dot");
    cout << "Parcours en profondeur " << endl;
parcoursProfondeur(n,voisins,pere_P,niveau_P,debut,fin);
Arbre(n,niveauMax(n,niveau_P),niveau_P,pere_P,arbreP,nb_arc_P);
affichageGraphique(n,nb_arc_P,arbreP,"parcoursProfondeur.dot");
cout << "le niveau max dans le parcours en profondeur " << niveauMax(n,niveau_P) <<endl;
cout << "Sommets : \t";
for(int i=0;i<n;i++)
    cout << i << "\t";
cout << endl;
cout << "debut : \t";
for(int i=0;i<n;i++)
    cout << debut[i] << "\t";
cout << endl;
cout << "fin : \t\t" ;
for(int i=0;i<n;i++)
    cout << fin[i] << "\t";
cout << endl;

  return EXIT_SUCCESS;
}
