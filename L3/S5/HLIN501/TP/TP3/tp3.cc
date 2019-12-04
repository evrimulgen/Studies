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


void ecritureNiveaux(int n, int niveau[])
{
    int  rep[n]={0};

    for(int i=0;i < n ;i++)
        rep[niveau[i]]++;

    for(int j=0;j < n ;j++)
        cout << "il y a  "<< rep[j] <<" sommets au niveau " << j <<endl;

}

void parcoursProfondeur(int n,vector<int> voisins[],int pere[],int niveau[])
{
int debut[2*n]={0};
int fin [2*n]={0};
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

            }
         }
    }

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
  int pere[n];                              // L'arbre en largeur.
  int ordre[n];                             // L'ordre de parcours.
  int niveau[n]={0};
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

    cout << "Parcours en largeur " << endl;
parcoursLargeur(n,voisins,niveau,ordre,pere);
ecritureNiveaux(n,niveau);
for(int i=0;i<n;i++)
    niveau[i]=0;

    cout << "Parcours en profondeur " << endl;
parcoursProfondeur(n,voisins,pere,niveau);
ecritureNiveaux(n,niveau);



  return EXIT_SUCCESS;
}
