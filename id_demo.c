/*
 * file:id_demo.c
 * description:打印用户ID和组ID
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int
main(void)
{
    printf("uid is :%d,gid is :%d.\n",getuid(),getgid());

    return 0;
}
