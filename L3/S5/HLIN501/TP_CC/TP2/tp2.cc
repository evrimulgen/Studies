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
/*
void pointrandom2(coord point[])
{
  for(int i=0;i<=60;i++)
    {
      point[i].abs=10*i;
      point[i].ord=(60*i-pow(i,2))/2;
    }
}
*/
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
	/*int x =(point[edge[i][0]].abs - point[edge[i][1]].abs);
	int y =(point[edge[i][0]].ord - point[edge[i][1]].ord);
	edge[i][2]=(point[edge[i][0]].abs - point[edge[i][1]].abs)*(point[edge[i][0]].abs - point[edge[i][1]].abs)+(point[edge[i][0]].ord - point[edge[i][1]].ord)*(point[edge[i][0]].ord - point[edge[i][1]].ord);
	edge[i][2]=(int)(x*x)+(int)(y*y);
	*/
	int d=point[edge[i][0]].ord - point[edge[i][1]].ord;
	edge[i][2]=pow(d,2);
    }

}

//Exercice 3


void pivot(int T[][3],int g,int d,int &l){
    int p=T[g][2];
    int inf=g+1,sup=d;
    while( inf <= sup)
    {
      if (T[inf][2] <= p) inf++;
      else if (T[inf][2]>p)
      {
        swap(T[sup][0],T[inf][0]);
        swap(T[sup][1],T[inf][1]);
        swap(T[sup][2],T[inf][2]);
        sup--;
        }
    }
    swap(T[sup][0],T[g][0]);
    swap(T[sup][1],T[g][1]);
    swap(T[sup][2],T[g][2]);


    l=sup;


}
 //le pivot
void Trirapide(int T[][3],int g,int d){
int h;
  if (g<d) {
    pivot(T,g,d,h);
      Trirapide(T,g,h-1);
      Trirapide(T,1+h,d);
    }
}


void tri(int m, int edge[][3])
{
  int i=m-1;
  while(i >= 0)
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

void kruskal2(int n, int m, int edge[][3],int arbre[][2])
{
  int comp[n]={0};
  int x=0;
  int taille[n]={0};
  int compteur = 0;
  vector< vector<int> > L(n, vector<int> () );

  for(int a=0;a<n;a++)
    {
      comp[a]=a;
      L[comp[a]].push_back(a);
      //vector< vector<int> > L ( comp[a], vector<int>(a) );
      taille[comp[a]]=1;
    }

  for(int b=0;b<m;b++)
    {
      int p=edge[b][0];
      int q=edge[b][1];
      if ( comp[p]!= comp[q] )
	{
          arbre[compteur][0] = p;
          arbre[compteur][1] = q;
          compteur++;
          if(taille[comp[p]]>taille[comp[q]])
            swap(p,q);
          x=comp[p];
          taille[comp[q]]=taille[comp[q]]+taille[x];
          int z;
          while(!L[x].empty())
            {
              z=L[x].back();
              comp[z]=comp[q];
              L[comp[q]].push_back(z);
              L[x].pop_back();
            }
	}
    }

}

void kruskal1(int n,int m, int edge[][3], int arbre[][2])
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
  //pointrandom2(point);
  //points
  for(int i=0;i<n;i++)
    cout <<"(" << point[i].abs <<","<< point[i].ord<<")"<<endl;

  distances(n,m,point,edge);
  //avant le tri de edge
  cout << "avant le tri des aretes" <<endl;
   for(int i=0;i<m ; i++)
    for(int j=0;j<3;j++)
      cout << "edge ["<<i<<"] ["<<j<<"] = " << edge[i][j]<<endl;

  //tri(m,edge);
  Trirapide(edge,0,m-1);
  //triparfusion(edge,0,m); // segmentation fault
  kruskal2(n,m,edge,arbre); // avec composante optimisé


  //après le tri edge
  cout << "après le tri des aretes" <<endl;
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
