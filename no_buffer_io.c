/*
 * file:no_buffer_io.c
 * description:不带缓冲的I/O实现实例
 * date：2015/7/14
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>

 #define BUFFSIZE 4096

 int
 main(void)
 {
 	int n;
 	char buf[BUFFSIZE];

 	while((n = read(STDIN_FILENO,buf,BUFFSIZE)) > 0)
 		if(write(STDOUT_FILENO,buf,n) != n)
 			fprintf(stderr, "write error!\n");

 	if(n < 0)
 		fprintf(stderr, "read error!\n");

 	exit(0);
 }