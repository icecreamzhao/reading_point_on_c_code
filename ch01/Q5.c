#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*********************************************************************
 * file       : Q5.c                                                 *
 * date       : 2022-06-27                                           *
 * author     : littleboy                                            *
 * description: 使用scanf函数读取两个整数, 分别保存玉quantity和price *
 *              变量, 然后再读取一个字符串, 保存在一个名叫department *
 *              的字符数组中                                         *
 ********************************************************************/

#define MAX_INPUT 1000

int main()
{
    int quantity, price;
	if (scanf("%d", &quantity) == 1 && scanf("%d", &price) == 1)
	{
					printf("%d\t%d\n", quantity, price);
	}
	int ch;
	if ((ch = getchar() != EOF) && ch != '\n')
					;
	char s[MAX_INPUT];
	if (fgets(s, MAX_INPUT, stdin) != NULL)
	{
					printf("%s\n", s);
	}
}
