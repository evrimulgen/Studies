#include<stdlib.h>
#include<stdio.h>

int main(int argc,char* argv[]){
  int max=atoi(argv[1]),min=atoi(argv[1]);

  for(int i=0;i<argc;i++){
    if (max < atoi(argv[i])){max=atoi(argv[i]);}
    if (min > atoi(argv[i])){min=atoi(argv[i]);}
	}

  printf("max = %i \n",max);
  printf("min = %i \n",min);
  printf("argv[1]= %i",atoi(argv[1]));

	return 0; }
