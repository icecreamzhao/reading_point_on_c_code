#include "stdio.h"

int main()
{
				int c[10] = {1,2,3,4,5,6,7,8,9,10};
				int *cp = c + 2;
				printf("%d", cp[-1]);
}
