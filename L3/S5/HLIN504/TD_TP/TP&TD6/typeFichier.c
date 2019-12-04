#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc,char** argv)
{
struct stat  etat;
stat(argv[1],&etat);
printf("%s \n",argv[1]);
 switch(etat.st_mode & S_IFMT)
 {
    case S_IFREG : printf("le fichier %s est un régulier \n",argv[1]);break;
    case S_IFDIR : printf("le fichier %s est un répertoire \n",argv[1]);break;
    case S_IFLNK : printf("le fichier %s est un lien symbolique \n",argv[1]);break;
 }

 return 0;
}
