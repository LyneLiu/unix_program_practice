/*
 * file:copy_demo.c
 * description:将标准输入拷贝到标准输出
 * date:2015/7/14
 */

#include <stdio.h>

int 
main(void)
{
    int c;
    /*
     * getc每次从stdin读取一个character，使用putc打印字符
     */
    while((c = getc(stdin)) != EOF)
        if(putc(c,stdout) == EOF)
            fprintf(stderr,"output error");

    if(ferror(stdin))
        fprintf(stderr,"input error");

    return 0;
}
