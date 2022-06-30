#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*************************************************************************
 * file       : ch01/rearrage.c                                          *
 * author     : littleboy                                                *
 * date       : 2022/06/26                                               *
 * description: 本程序为c和指针1.1简介中的示例程序, 首先读取一串列标号,  *
 *              这些列标号成对出现, 表示输入行的列范围, 以负值结尾, 剩余 *
 *              的输入行, 被列标号选中范围内的字符被提取并打印。         *
 ************************************************************************/

#define MAX_COLS 20
#define MAX_INPUT 1000

int read_column_numbers(int columns[], int max);
void rearrage(char *ouput, char const *input, int n_columns, int const columns[]);

int main()
{
    // 思路:
    // 读入列标号(需要检测是否是成对出现, 以负值结尾)
    // 将列标号作为下标, 循环读入的字符串, 并通过下标输出
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
	char output[MAX_INPUT];
    n_columns = read_column_numbers(columns, MAX_COLS);
    while (fgets(input, MAX_INPUT, stdin))
    {
        printf("original input: %s\n", input);
        rearrage(output, input, n_columns, columns);
        printf("rearrage line: %s\n", output);
	}
    return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max)
{
    int num = 0;
	int ch;

	// 读入列标号, 并判断是否输入了负值
	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
	num += 1;

	// 判断了是否成对出现
	if (num % 2 != 0)
	{
        puts("Last column number is not paired.");
		exit(EXIT_FAILURE);
	}

	// 当scanf函数对输入值进行转换时, 它只读取需要读取的字符, 而剩下的
	// 字符会一直等待被读取。这里的作用就是将剩下的字符读取并丢弃, 防止
	// 被解释为第一行数据
	// 这里的ch类型为整形的原因是需要容纳EOF这样的字符,位数比字符类型要多
	while ((ch = getchar()) != EOF && ch != '\n')
		;
	return num;
}

void rearrage(char *output, char const *input, int n_columns, int const columns[])
{
	int col;
	int output_col;
	int len;

	len = strlen(input);
	output_col = 0;
	for (col = 0; col < n_columns; col += 2)
	{
		int nchars = columns[col + 1] - columns[col] + 1;
		if (columns[col] >= len || output_col == MAX_INPUT - 1)
		    break;

			if (output_col + nchars > MAX_INPUT - 1)
			    nchars = MAX_INPUT - output_col - 1;
		strncpy(output + output_col, input + columns[col], nchars);
		output_col += nchars;
	}
	output[output_col] = '\0';
}
