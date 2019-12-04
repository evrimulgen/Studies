#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>

using namespace std;

const int N=1400;
const int M=(N*(N-1))/2;

typedef struct coord{int abs; int ord;} coord;


bool isin(vector<int>voisins[],int a,int x)
{
    bool tr=false;
    for(int i=0;i<voisins[a].size();i++)
        if ( x == voisins[a].at(i) )
            tr=true;
    return tr;
}

void pointRandom(int n,coord point[])
{
 srand(time(NULL));
  for(int i=0;i<n;i++)
    {
      point[i].abs=rand()%612;
      point[i].ord=rand()%792;
    }
}
float mydistance(coord p1,coord p2)
{
    return sqrt(pow(p1.abs-p2.abs,2)+pow(p1.ord-p2.ord,2)) ;
}
void voisins(int n,int dmax,coord point[],vector<int> voisin[],int &m)
{
    int nb_aretes=0;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
              {

                if( i != j)
                {
                    if(!isin(voisin,i,j) && mydistance(point[i],point[j]) <= dmax)
                    {
                        cout << mydistance(point[i],point[j]) << endl;
                        voisin[i].push_back(j);
                        voisin[j].push_back(i);
                        nb_aretes++;
                    }
                }
                }
          }
      m=nb_aretes;

}

void voisins2arete(int n,vector<int>voisins[],int arete[][2])
{
    int x=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<voisins[i].size();j++)
        {
            arete[x][0]=i;
            arete[x][1]=voisins[i].back();
            x++;
            voisins[i].pop_back();
        }
    }

}
void affichageGraphique(int n,coord point[],vector<int>voisins[],string name)
{
                                                                // les points et l'arbre de Kruskal.
 ofstream output;
 output.open(name.c_str(),ios::out);
 output << "%!PS-Adobe-3.0" << endl;
 output << "%%BoundingBox: 0 0 612 792" << endl;
 output << endl;
 for(int i=0;i<n;i++)
 {
   output << 0 <<" "<< 255 <<" "<< 0 << " setrgbcolor"<<endl;
   output << point[i].abs << " " << point[i].ord << " 3 0 360 arc" <<endl;
   output << "0 setgray" <<endl;
   output << "fill" <<endl;
   output << "stroke"<<endl;
   output << endl;
   }
 output << endl;

 for(int i=0;i<n;i++)
    for(int j=0;j<voisins[i].size();j++)
   {output << point[i].abs << " " << point[i].ord
	   << " moveto" << endl;
   output << point[voisins[i].at(j)].abs << " " << point[voisins[i].at(j)].ord
	  << " lineto" << endl;
   output << "stroke" << endl;
   output << endl;
   }
 output << "showpage";
 output << endl;
}

void affichageArbre(int n,coord point[],int  arbre[][2],int pere[],string name)
{
                                                                // les points et l'arbre de Kruskal.
 ofstream output;
 output.open(name.c_str(),ios::out);
 output << "%!PS-Adobe-3.0" << endl;
 output << "%%BoundingBox: 0 0 612 792" << endl;
 output << endl;
 for(int i=0;i<n;i++)
 {
    output << 0 <<" "<< 255 <<" "<< 0 << " setrgbcolor"<<endl;
    if(pere[i] != -1){
   output << point[i].abs << " " << point[i].ord << " 3 0 360 arc" <<endl;
   output << "0 setgray" <<endl;
   output << "fill" <<endl;
   output << "stroke"<<endl;
   output << endl;
   }
  }
 output << endl;
 for(int i=0;i<(n-1);i++)
   {output << point[arbre[i][0]].abs << " " << point[arbre[i][0]].ord
	   << " moveto" << endl;
   output << point[arbre[i][1]].abs << " " << point[arbre[i][1]].ord
	  << " lineto" << endl;
   output << "stroke" << endl;
   output << endl;
   }
 output << "showpage";
 output << endl;
}

//le postscript
int minimum(int n,int T[],int r)
{
int k=0;
for(int i=1;i<n;i++)
{

        if (T[k]>T[i])
        k=i;
        if (i == r) i++;

}
return k;
}

bool existe(int n,int dis[],bool traite[],int &x)
{
    bool tr=false;
    int h,r;
    int i=0;
    while(!tr && i<n)
    {
        h=minimum(n,dis,r);
        if (traite[h])
        {
            r=h;
            i++;
        }
        else
        {   x=h;
            tr=true;
        }
    }


    return tr;
}
bool existe1(int n,int dis[],bool traite[],int &x)
{
    int exis[n][3];
    bool tr=0;
    int k=0;
    for(int i=0;i<n;i++)
    {
        if (traite[i] == 0)
        {   tr=1;
            exis[k][0]=i;
            exis[k][1]=dis[i];
            exis[k][2]=traite[i];
            k++;
        }
    }
    int m=0;
    if(tr)
    {
      m=0;
      for(int j=1;j<k;j++)
        if (exis[m][1]>exis[j][1])
            m=j;
    }
    x=exis[m][0];
    return tr;
}
void dijkstra(int n,vector<int> voisin[],coord point[],int pere[])
{
    bool traite[n];
    int dis[n];

    for(int i=0;i<n;i++)
    {
        traite[i]=0;
        dis[i]=4000;
    }
    pere[0]=0;dis[0]=0;
    int x=0;
    int i=0;
    while(existe1(n,dis,traite,x))
    {   i++;
        traite[x]=1;
        for(int i=0;i<voisin[x].size();i++)
        {
            int y=voisin[x].at(i);
             //cout << "dis["<<y<<"]= "<<dis[y]<<endl;
              cout << "dis["<<x<<"]= "<<dis[x]<<endl;
            if((traite[y] == 0) && (dis[y] > dis[x]+(int)mydistance(point[x],point[y])))
            {
                dis[y]=dis[x]+(int)mydistance(point[x],point[y]);

                pere[y]=x;
            }
        }
    }

    cout <<"nombre de passage dans le while de djisk "<<i<<endl;
     for(int i=0;i<n;i++)
      cout << "dis["<<i<<"]= "<<dis[i]<<endl;
}
int construireArbre(int n,int arbre[][2],int pere[])
{

    for(int i=0;i<(n-1);i++)
    {

        if(pere[i] != -1)
        {
         arbre[i][0]=i;
         arbre[i][1]=pere[i];

        }
    }

    return n-1;
}

int
main()
{

  int n;                           // Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int dmax=50;                     // La distance jusqu'a laquelle on relie deux points.
  coord point[N];                  // Les coordonnees des points.
  vector<int> voisin[N];           // Les listes de voisins.
  int arbre[N-1][2]={0};               // Les aretes de l'arbre de Dijkstra.
  int pere[N];
  coord point_arbre[N];       //les coordonnes des points de l'arbre
  for(int i=0;i<N;i++)
                        pere[i]=-1;// La relation de filiation de l'arbre de Dijkstra.
  int m;                           // Le nombre d'aretes
  int arete[M][2]={0};                 // Les aretes du graphe


  pointRandom(n,point);
  for(int i=0;i<n;i++)
    cout <<"(" << point[i].abs <<","<< point[i].ord<<")"<<endl;

  voisins(n,dmax,point,voisin,m);
  for(size_t i=0;i<n;i++)
    {
        cout <<"voisins["<<i<<"] = ";
         for(size_t k=0;k<voisin[i].size();k++)
        {
            cout << voisin[i].at(k) << "  " ;
        }
      cout << endl;
    }
  voisins2arete(n,voisin,arete);

  cout << m << endl;
  for(int i=0;i<m;i++)
    {


            cout << "arete["<<i<<"][0]="<< arete[i][0] << endl ;
            cout << "arete["<<i<<"][1]="<< arete[i][1] << endl ;
    }
  affichageGraphique(n,point,voisin,"graphe.ps");
  dijkstra(n,voisin,point,pere);
  cout << construireArbre(n,arbre,pere) <<endl;
  for(size_t i=0;i<n;i++)
    cout <<"pere["<<i<<"] = "<<pere[i]<<endl;

   for(int i=0;i<(n-1);i++)
    {


            cout << "arbre["<<i<<"][0]="<< arbre[i][0] << endl ;
            cout << "arbre["<<i<<"][1]="<< arbre[i][1] << endl ;
    }
  affichageArbre(n,point,arbre,pere,"arbre.ps");


  return EXIT_SUCCESS;
}
