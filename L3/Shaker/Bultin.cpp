#include <cstdlib>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
int Nj; //Note de JACK
char maxmin[6];
float Moy;
int nb_cmds;
char N_cmds[2001];

cin >> Nj;
cin >> maxmin;
cin >> Moy;
cin >> nb_cmds;
cin >> N_cmds;

char max[3];
int pmax=0;
int pmin=0;  
char min[3];
  
int taille = strlen(maxmin);
for(int i=0;i<taille;i++)
  {
if (i < 2)
  {
min[pmin]=maxmin[i];
pmin++;
}
 else if (i > 2)
   {
max[pmax]=maxmin[i];
pmax++;
}
      
}

int note_max,note_min;
note_max=atoi(max);
note_min=atoi(min);

char note_jack[3];
sprintf(note_jack,"%d",Nj);

if  ( note_max >= Nj && note_min <= Nj && strstr(note_jack,N_cmds) != NULL )
  cout << "RAS" << endl;
 else
   cout << " Jack viens ici " << endl;

return 0;
}
