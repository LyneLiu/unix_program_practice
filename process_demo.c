/*
 * file:process_demo.c
 * description:获取一个进程的PID
 */
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    printf("hello world,my ID is:%ld\n",(long)getpid());

    return 0;
}
