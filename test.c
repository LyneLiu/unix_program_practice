/*
 * file:copy_demo.c
 * description:将标准输入拷贝到标准输出
 */

#include <stdio.h>

int 
main(void)
{
    int c;
    while((c = getc(stdin)) != EOF)
        if(putc(c,stdout) == EOF)
            fprintf(stderr,"output error");

    if(ferror(stdin))
        fprintf(stderr,"input error");

    return 0;
}
