#include <stdio.h>

void plusOne(int *i)
{
	*i = *i + 1;
	*i = 100;
}

int main()
{
	int i = 1;
	printf("Before - %d\n",i);
	plusOne(&i);
	printf("After - %d",i);
}
