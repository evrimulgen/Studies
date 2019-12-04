#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/*
S_IRUSR
S_IWUSR
S_IXUSR

S_IRGRP
S_IWGRP
S_IXGRP

S_IRWXO
S_IROTH
S_IWOTH
*/
int main (int argc,char** argv)
{
struct stat  etat;
stat(argv[1],&etat);
char droits[10]=" ";
switch(etat.st_mode & S_IFMT)
 {
    case S_IFREG : droits[0]='-';break;
    case S_IFDIR : droits[0]='d';break;
    case S_IFLNK : droits[0]='l';break;
 }

// faire 9 if
printf("%s \n",argv[1]);
printf("%o \n",rights);

return 0;
}
