/*
 * file:myls.c
 * description:ls命令的一个简要实现
 * date：2015/6/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int
main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argc != 2)
        fprintf(stderr,"usage:ls directory_name\n");

    if((dp = opendir(argv[1])) == NULL)
        fprintf(stderr,"can't open %s.\n",argv[1]);

    while((dirp = readdir(dp)) != NULL)
        fprintf(stdout,"%s\n",dirp->d_name);

    closedir(dp);

    exit(0);
}
