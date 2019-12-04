#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;
typedef struct coord{int abs; int ord;} coord;

void AffichageGraphique(int n, coord point[], int arbre[][2]);

//Exercice 1

void pointrandom(int n, coord point[])
{
  srand(time(NULL));
  for(int i=0;i<n;i++)
    {
      point[i].abs=rand()%612;
      point[i].ord=rand()%792;
    }
}

//Exercice 2

void distances(int n, int m, coord point[], int edge[][3])
{
  int l=0,j=0;

  for(int i=0;i<m;i++)
    edge[i][2]=0;

  for(int i=0;i<m;i++)
    {
      if(j >= (n-1))
	{
	  l++;
	  j=l;
	}
      	edge[i][0]=l;
	j++;
	edge[i][1]=j;
	int x =(point[edge[i][0]].abs - point[edge[i][1]].abs);
	int y =(point[edge[i][0]].ord - point[edge[i][1]].ord);
	//edge[i][2]=(point[edge[i][0]].abs - point[edge[i][1]].abs)*(point[edge[i][0]].abs - point[edge[i][1]].abs)+(point[edge[i][0]].ord - point[edge[i][1]].ord)*(point[edge[i][0]].ord - point[edge[i][1]].ord);
	edge[i][2]=(int)(x*x)+(int)(y*y);
	//edge[i][2]=(int)pow(x,2)+(int)pow(y,2);
    }

}

//Exercice 3
//tri rapide
void tri(int m, int edge[][3])
{
  int i=m-1;
  while(i >= 1)
    {
      for(int j=0;j<i;j++)
	{

	  if (edge[j][2]>edge[j+1][2])
	    {
	      swap(edge[j][0],edge[j+1][0]);
	      swap(edge[j][1],edge[j+1][1]);
	      swap(edge[j][2],edge[j+1][2]);
	    }

	}

      i--;
    }
}


//Exercice 4
void kruskal(int n,int m, int edge[][3], int arbre[][2])
{
  int comp[n];
  int r=0;

  for(int i=0;i<n;i++)
    comp[i]=i;


  for(int b=0;b<m;b++)
    {
      int aux=0;
      if ( comp[edge[b][0]]!= comp[edge[b][1]] )
	{
	  aux=comp[edge[b][0]];
	  arbre[r][0]=edge[b][0];
	  arbre[r][1]=edge[b][1];
	  r++;
	  for(int i=0;i<n;i++)
	    {
	      if( comp[i] == aux )
		{
		  comp[i]=comp[edge[b][1]];
		}
	    }
	}
    }
}





int
main()
{
  int n;             //Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int m=n*(n-1)/2;   // Le nombre de paires de points.
  coord point[n];    // Les coordonnees des points dans le plan.
  int edge[m][3];    // Les paires de points et le carre de leur longueur.
  int arbre[n-1][2]; // Les aretes de l'arbre de Kruskal.


  pointrandom(n,point);
  distances(n,m,point,edge);
  tri(m,edge);
  kruskal(n,m,edge,arbre);

  //points
  for(int i=0;i<n;i++)
    cout <<"(" << point[i].abs <<","<< point[i].ord<<")"<<endl;

  //edge
  for(int i=0;i<m ; i++)
    for(int j=0;j<3;j++)
      cout << "edge ["<<i<<"] ["<<j<<"] = " << edge[i][j]<<endl;

  //arbre
  for(int i=0;i< n-1 ; i++)
    for(int j=0;j<2;j++)
      cout << "arbre ["<<i<<"] ["<<j<<"] = " << arbre[i][j]<<endl;
  AffichageGraphique(n,point,arbre);

  return EXIT_SUCCESS;
}
