/*
 * file:more01.c -- version of more
 * read and print 24 lines then pause for a few special commands
 */

#include <stdio.h>
#include <stdlib.h>
#define PAGELEN 24
#define LINELEN 512

void do_more(FILE *);
int see_more();

int main(int argc,char *argv[])
{
    FILE *fp;
    if(argc == 1)
    {
        do_more(stdin);
    }
    else 
        while(--argc)
        if((fp = fopen(* ++argv, "r")) != NULL)
        {
                do_more(fp);
                fclose(fp);
        }
    else
        exit(1);

    return 0;
}

void do_more(FILE *fp)
{/*
  * read PAGELEN lines,then call see_more() for further instructions
  */ 
    char line[LINELEN];
    int num_of_lines = 0;
    int reply;
    
    while(fgets(line,LINELEN,fp))
    {
        if(num_of_lines == PAGELEN)
        {
            /*achieve the reply from the command line*/
            reply = see_more();
            if(reply == 0)
                break;
            num_of_lines -= reply;
        }

        /*read from the file,and judge the number of lines we had read*/
        if(fputs(line,stdout) == EOF)
            exit(1);
        num_of_lines++;
    }
}


int see_more()
{
    int c;
    printf("\033[7m more \033[m");
    while((c = getchar()) != EOF)
    {
        switch(c)
        {
        case 'q': return 0;break;
        case ' ': return PAGELEN;break;
        case '\n': return 1;break;
        default: break;
        }
    }

    return 0;
}

