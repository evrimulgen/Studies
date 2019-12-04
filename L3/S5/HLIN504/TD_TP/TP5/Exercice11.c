#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>



int main(int argc,char** argv)
{
   char * arg[]={"ls","-l","monfic",NULL};

   /* printf("avant exec \n");
    execv("/bin/ls",arg);
    printf("après exec \n");

    chmod("monfic",S_IRWXU);
    chmod("monfic",S_IROTH);
    chmod("monfic",S_IRGRP);

    execv("/bin/ls",arg);
    */

    printf("%d %d %d\n",S_IRWXU,S_IRWXO,S_IRWXG);
    int fichier =open("monfic",O_RDONLY);
    fchmod(fichier,S_IRWXU);
    fchmod(fichier,S_IRWXO);
    fchmod(fichier,S_IRWXG);

    execv("/bin/ls",arg);
    return 0;

    // utilisez stat !!!!!!!!!!!!
}
