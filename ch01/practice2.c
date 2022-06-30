#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/********************************************************
 * @file       : ch01/practice2.c                       *
 * @author     : littleboy                              *
 * @date       : 2022/06/30                             *
 * @description: 编写一个程序, 从标准输入读取几行输入。 *
 *               每行输入都要打印到标准输出上。前面要加 *
 *               上行号。在编写这个程序时要试图让程序能 *
 *               够处理的输入行的长度没有限制。         *
 *******************************************************/

#define MAX_INPUT 1000;

void printChar(char input[], int max);

int main()
{
    char input[MAX_INPUT];
    printChar(input, MAX_INPUT);
    return 0;
}

void printChar(char input[], int max)
{
    int lineNum = 0;
    while( fget(input, max, stdin) )
        printf("%d %s", ++lineNum, input);
}
