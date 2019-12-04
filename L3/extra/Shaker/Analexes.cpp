#include <cstdlib>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{

  char l1[1000];
  char l2[1000];

  char lesMotsL1[50][30];
  char lesMotsL2[50][30];

  int r1=0,c1=0;
  int r2=0,c2=0;

  while ( l1[c1] != '\0' && l2[c2] != '\0')
    {
      if ( l1[c1] >= 65 && l1[c1] >=90 && l1[c1] >= 97 && l1[c1] <= 122 )
	{
	  
	  lesMotsL1[r1][c1]=l1[c1]
	   c1++;
	}
      else{
	c1++;
	r1++;
      }

      if ( l2[c2] >= 65 && l2[c2] >=90 && l2[c2] >= 97 && l2[c2] <= 122 )
	{
	  
	  lesMotsL1[r2][c2]=l2[c2]
	   c2++;
	}
      else{
	c2++;
	r2++;
      }
    }

  
