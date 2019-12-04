#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

int main(int argc,char** agrv)
{
   int edge[6][2];

   int k=0,l=0,j=0;
  
  for(int i=0;i<10;i++)
    {
      if(j > 5-1)
	{
	  l++;
	  j=l;
	}
      edge[i][0]=l;
      j++;
      edge[i][1]=j;
    }

  for(int i=0;i<10 ; i++)
    for(int j=0;j<2;j++)
      cout << "edge ["<<i<<"] ["<<j<<"] = " << edge[i][j]<<endl;
  
}
