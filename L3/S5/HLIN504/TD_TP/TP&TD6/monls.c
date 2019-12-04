#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc,char** argv)
{
    DIR* repertoire=opendir(argv[1]);
    dirent* curseur;
    whlie (curseur != NULL);
    {
        printf("%d",curseur->d_ino,"\t",curseur->d_off,"\t",curseur->d_reclen)
    }


}
