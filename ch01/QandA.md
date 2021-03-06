# Q1
> C是一种自由形式的语言, 也就是说并没有规则规定他的外观究竟应该怎样。但本章的例子程序遵循了一定的空白使用规则。你对此有何想法?

我在阅读代码时确实注意到了空白使用规则, 我认为规则是为了提高代码的可读性, 而团队之间合作更应该注意代码规范, 制定统一的规范有助于提升团队工作效率。

# Q2
> 把声明(如函数原型的声明)放在头文件中, 并在需要时用#include 指令把他们包含于源文件中, 这种做法有什么好处?

这样做可以避免重复声明相同的函数, 从而造成多余的维护工作

# Q3
> 使用#define指令给字面值常量取名有什么好处?

好处是当在程序中需要多次用到同一个字面值常量时, 使用#define指令命名可以避免当修改时需要找到所有位置的字面值常量。

# Q4
> 依次打印一个十进制整数, 字符串和浮点值, 你应该在 prinf 函数中分别使用什么格式的代码? 试编一例, 让这些打印值以空格分隔, 并在输入行的末尾添加一个换行符。

见Q4.c

# Q5
> 编写一条scanf语句, 他需要读取两个整数, 分别保存于quantity和price变量, 然后在读取一个字符串, 保存一个名叫department的字符串数组中。

见Q45.c

# Q6
> C 语言并不执行数组下标的有效性检查, 你觉得为什么这个明显的安全手段会从语言中省略?

因为指针的原因, 如果一个指针指向的是另一个数组的中间元素, 而当使用下标访问该指针的时候, 下标可以为负, 具体例子为:

```c
int array[5];
// 这里ip指向的元素是array[2]
int *ip = array + 2;
// ip[-1] 对应的是array[1]
```

这种情况下如果执行下标的有效性检查, 则是一个相当困难且开销大的工作。

# Q7
> 本章描述的rearrange程序包含下面的语句
```c
strncpy( output + ouput_col, input + columns[col], nchars);
```
strcpy函数只接受两个参数, 所以它实际上所复制的字符数由第二个参数指定。在本程序中, 如果用strcpy函数取代strncpy函数会出现什么结果？

strncpy指定复制的字符数, 如果使用strcpy的话, 则是直接从目标起始处复制到结尾。

# Q8
> rearrange 程序中包含下面的语句
```c
while( gets( input ) != NULL)
``
你认为这段代码可能会出现什么问题?

gets并不能保证最大输入字符数, 会溢出。
