/*
 * file:process_control_demo.c
 * description:进程控制的一个程序示例，
 * 该程序的功能是在当前目录下执行shell命令，比如：ls、pwd、who等
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/*定义每行MAXLINE*/
#define MAXLINE 4096

int
main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;
    
    /*需要使用%%来打印符号%*/
    printf("%% ");      
    /*fgets从标准输入一次读取一行；
     *当输入EOF作为行的第一个字符时，fgets返回一个null指针
     */
    while(fgets(buf,MAXLINE,stdin) != NULL){
        if(buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;   /*replace newline with null*/
        if((pid = fork()) < 0){
            /*fork函数返回一个非负process ID（child process）给父进程
             *返回一个0给child进程
             */
            fprintf(stderr,"fork error");
        }else if(pid == 0){ /*child*/
            execlp(buf,buf,(char *)0);
            fprintf(stderr,"couldn't execute:%s",buf);
            exit(127);
        }

        /*parent*/
        if((pid = waitpid(pid,&status,0)) < 0)
            fprintf(stderr,"waitpid error");
        printf("%% ");
    }

    return 0;
}
