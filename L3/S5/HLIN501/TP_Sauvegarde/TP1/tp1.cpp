#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void grapherandom(int n,int m, int edge[][2])
{
  srand(time(NULL));
  for(int a=0;a<m;a++){
    for(int b=0;b<2;b++){
      edge[a][b]=rand()%n;
      cout << "edge ["<< a <<"] ["<<b<<"] = "<< edge[a][b]<< endl;
    }
  }

}

void AffichageGraphique(int n,int m,int edge[][2],string name)
{
 ofstream output;
 output.open(name.c_str(),ios::out);
 output << " graph {" <<endl;
 for(int i=0;i<n;i++)
     output <<i<<";"<<endl;
 for(int i=0;i<m;i++)
          output <<edge[i][0]<<" -- "<<edge[i][1] <<";"<<endl;
  output << "}" <<endl;
}


void composantes(int n, int m, int edge[][2], int comp[])
{
  int x=0;
  cout << " début de Composantes " << endl;
  for(int a=0;a<n;a++)
    comp[a]=a;

  for(int b=0;b<m;b++)
    {
      int p=edge[b][0];
      int q=edge[b][1];
      if ( comp[p]!= comp[q] )
	{
	  x=comp[p];
	  for(int k=0;k<n;k++)
	    {
	      if(comp[k] == x)
		comp[k]=comp[q];
	    }
	}
    }
  for(int a=0;a<n;a++)
    cout<<"comp["<<a<<"]="<< comp [a] <<endl;
}

void ecrituretailles(int n, int m, int comp[])
{
  cout<<"il y a "<<n<<" sommets"<<endl;
  int taille[n]={0};
  for(int i=0;i<n;i++) taille[comp[i]]++;


  int total[n]={0};
  for(int i=0;i<n;i++) total[taille[i]]++;
  cout<<"il y a "<<total[1]<<" points isolés"<<endl;
  for(int i=2;i<n;i++)
    cout<< "il y a "<< total[i] <<" composantes de taille "<<i<<endl;
}

void composantesO(int n, int m, int edge[][2], int comp[])
{
  cout << " début de Composantes Optimisé " << endl;
  int x=0;
  int taille[n];
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

  for(int a=0;a<n;a++)
    cout<<"comp["<<a<<"]="<< comp [a] <<endl;
}

int main()
{
  int n;     // Nombre de sommets.
  int m;     // Nombre d'aretes.
  cout << "Entrer le nombre de sommets:";
  cin >> n;
  cout << "Entrer le nombre d'aretes:";
  cin >> m;
  int edge[m][2];    // Tableau des aretes.
  int comp[n];       // comp[i] est le numero de la composante contenant i.

  grapherandom(n,m,edge);
  AffichageGraphique(n,m,edge,"graphe.dot");
  composantes(n,m,edge,comp);
  composantesO(n,m,edge,comp);
  ecrituretailles(n,m,comp);
  return EXIT_SUCCESS;

}
