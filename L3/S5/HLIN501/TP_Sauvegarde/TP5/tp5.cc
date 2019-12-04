#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

const int N=5;
const int INF=9999;



/*void floydWarshall(int longueur[][N], int dist[][N])
{
    for(int k=0;k<N;k++)
         for(int i=0;i<N;i++)
             for(int j=0;j<N;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];

            }

    for(int i=0;i<N;i++)
        if (dist[i][i] < 0)
            cout << "il existe un cycle orienté de poids <0" <<endl;

}
*/
void copieMatrice(int M1[][N],int M2[][N])
{
     for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            M1[i][j]=M2[i][j];
}


void floydWarshall(int longueur[][N],int dist[][N],int chemin[][N])
{
    for(int k=0;k<N;k++)
         for(int i=0;i<N;i++)
             for(int j=0;j<N;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    chemin[i][j]=chemin[i][k];
                }
            }

    for(int i=0;i<N;i++)
        if (dist[i][i] < 0)
            cout << "il existe un cycle orienté de poids <0" << endl;

}
void affichage(int matrice[][N],string name)
{
    cout <<"***********"<<name<<"***********" << endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
        cout << matrice[i][j] << " \t ";
        }
        cout << endl;
      }
      cout << endl;
}
void itineraire(int i,int j,int chemin[][N])
{
    if ( i < N && j < N)
    {
        vector<int> s;
        s.push_back(i);
        int k=i;
        while(chemin[k][j] != j && chemin[k][j] != -1)
        {
            k=chemin[k][j];
            s.push_back(k);
        }

        if(chemin[k][j] == j)
        {
            cout << "L'itinéraire est : ";
            for(int i=0;i<s.size();i++)
                cout <<" "<< s.at(i) ;
            cout << " " << j << endl;
        }else if (chemin[k][j] == -1 )
        {
            cout << " incomposanteslet  :";
                for(int i=0;i<s.size();i++)
                cout <<" "<< s.at(i) ;
            cout << "........ " << j << endl;
        }

    }
    else
     cout << "sommets inexistant " << endl;


}

void AffichageGraphique(int n,int arc[][N],string name)
{
 ofstream output;
 output.open(name.c_str(),ios::out);
 output << " digraph {" <<endl;
 for(int i=0;i<n;i++)
     output <<i<<";"<<endl;
 for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
         if(arc[i][j] == 1)
        {
          output <<i<<" -> "<< j <<";"<<endl;
        }
    }
  output << "}" <<endl;
}


void AffichageGraphiqueAvecPoids(int n,int arc[][N],int l[][N],string name)
{
 ofstream output;
 output.open(name.c_str(),ios::out);
 output << " digraph {" <<endl;
 for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
         if(arc[i][j] == 1)
        {
          output <<i<<" -> "<< j <<"[label = "<<l[i][j]<<"];"<<endl;
        }
    }
  output << "}" <<endl;
}



void fermetureTransitive(int arc[][N], int fermeture[][N])
{


     for(int k=0;k<N;k++)
         for(int i=0;i<N;i++)
             for(int j=0;j<N;j++)
            {
                if((arc[i][k]==1) && (arc[k][j]==1))
                   fermeture[i][j]=1;


            }
}

void composantesFortConnexe(int n, int fermeture[][N])
{

vector<int> composantes[N];
vector<int> sommets_nonTR;

for(int i=0;i<N;i++)
    sommets_nonTR.push_back(i);

int nbr_composantes=0;
int nbr_sommetsTR=0;


    while( nbr_sommetsTR < N)
    {
      while(!sommets_nonTR.empty())
      {
         int x=sommets_nonTR.front();
         sommets_nonTR.erase(sommets_nonTR.begin());
         composantes[nbr_composantes].push_back(x);
         nbr_sommetsTR++;
         for(int j=0;j<N;j++)
            if ( fermeture[x][j] == 1 && fermeture[j][x] == 1)
                {
                    composantes[nbr_composantes].push_back(j);
                    nbr_sommetsTR++;
                }
         nbr_composantes++;
      }

    }

            cout << "Les composantesosantes fortement connexes sont : " ;
    for(int i=0;i<N;i++)
         {

             if(!composantes[i].empty())
             {
                 cout << "{";
                 for(int j=0;j<composantes[i].size();j++)
                 {
                    if(j != composantes[i].size()-1)
                    cout <<composantes[i].at(j)<<",";
                    else cout <<composantes[i].at(j);
                  }
                 cout << "}  ;   ";
             }
          }
    cout << endl;
}

void matriceAdj(int L[][N],int arc[][N])
{

       for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if (L[i][j]!=INF && L[i][j]!=0)
                    arc[i][j]=1;
                else arc[i][j]=0;

}

int main()
{

  int longueur[N][N]={{0,2,INF,4,INF},   //Les longueurs des arcs.
		      {INF,0,2,INF,INF}, //longueur[i][j]=INF si l'arc ij n'existe pas
		      {INF,INF,0,2,INF},
		      {INF,-3,INF,0,2},
		      {2,INF,INF,INF,0}};
  int dist[N][N];                        //Le tableau des disttances.
  int chemin[N][N];                    //Le tableau de la premiere etape du chemin de i a j.
  /*int arc[N][N]={{0,0,0,1,0,1},//La matrice d’adjacences du graphe oriente D.
                 {1,0,1,1,0,0},
                 {0,0,0,1,0,0},
                 {0,0,0,0,1,1},
                 {0,0,1,0,0,1},
                 {0,0,1,0,0,0}};
*/
  int FW[N][N];
  matriceAdj(longueur,FW);

  int fermeture[N][N];
//copieMatrice(&fermeture,&arc);
 copieMatrice(dist,longueur);
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        if(longueur[i][j] != INF)
        {                                //Initialisation des matrices arc et chemain
            chemin[i][j]=j;
        }
        else
        {
           chemin[i][j]= -1;
        }

  AffichageGraphiqueAvecPoids(N,FW,longueur,"FW.dot");
  cout << "*******************Initialistaion*******************" << endl;
  affichage(longueur,"longueur");
  affichage(chemin,"chemin");
   floydWarshall(longueur,dist,chemin);
  cout << "*******************Sorties*******************" << endl;
  affichage(dist,"Distances");
  affichage(chemin,"Chemins");
  cout << "Entrer le depart : ";
  int d;
  cin >> d;
  cout << endl;
  cout << "Entrer la destination : ";
  int a;
  cin >> a;
  cout << endl;
  itineraire(d,a,chemin);

/*
  fermetureTransitive(arc,fermeture);
  pointRandom(N,point);
  affichage(arc,"arc");
  affichage(fermeture,"fermeture");
  composantesFortConnexe(N,fermeture);
  AffichageGraphique(N,arc,"graphe.dot");
  AffichageGraphique(N,fermeture,"fermetureTransitive.dot");
*/
}
