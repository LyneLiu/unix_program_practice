/*
 * file:lib/error_functions.h
 * descriptions:常见错误处理函数的声明
 * date:2015/6/14
 */

#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

void errMsg(const char *format, ...);

#ifdef __GNUC__

/* This macro stops 'gcc -Wall' complaining that " control reaches
    end of non-void function" if we use the following functions to
    terminate main() or some other non-void function. */

#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

/*说明：打印出与当前errno值相对应的错误文本，参数列表与printf()所用相同*/
void errExit(const char *format, ...) NORETURN;

void err_exit(const char *format, ...) NORETURN;

void errExitEN(const char *format, ...) NORETURN;

void fatal(const char *format, ...) NORETURN;

void usageErr(const char *format, ...) NORETURN;

void cmdLineErr(const char *format, ...) NORETURN;
