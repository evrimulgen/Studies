#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



int main(int argc,char** argv)
{
  pid_t pid;
  switch( pid = fork() )
    {
    case -1:
      {
	fprintf(stderr,"impossible fork! \n");
	exit(1);
	break;
      }
    case 0: //enfant
      {
	printf("enf : je suis %d de parent %d \n",getpid(),getppid());
	return 4;
	break;
      }
    default : //parent
      {
	printf("parent :  je suis %d de parent %d et d'enfant %d\n",getpid(),getppid(),pid);
	return 5;
	break;
      }
    }
  return 0;
}
