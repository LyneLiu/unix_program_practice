/*
 * file:error_info
 * description:strerror、perror函数打印出错信息实例
 * date：2015/7/14
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>

 int
 int main(int argc, char const *argv[])
 {
 	/* strerror将参数errno的值映射为一个出错消息字符串*/
 	fprintf(stderr, "EACCES:%s\n", strerror(EACCES));
 	/* perror基于errno的当前值，输出由参数msg指向的字符串，
 	 * 然后加冒号和空格，接着是errno值对应的错误信息
 	 */
 	errno = ENOENT;
 	perror(argv[0]);

 	exit(0);
 }