#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(int argc, char *argv[])
{
	int a,b;

	if (sscanf(argv[1], "%d", &a) != 1)
		return EXIT_FAILURE;
	if (sscanf(argv[2], "%d", &b) != 1)
		return EXIT_FAILURE;

	swap(&a,&b);
	printf("a = %d, b = %d\n", a, b);

	return EXIT_SUCCESS;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
