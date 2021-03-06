#include <stdio.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ARR_SIZE 12

void bubble_sort(int a[]);
void output(int a[]);
void swap(int *,int *);

int main()
{	
	int a[ARR_SIZE] = {8, 4, 1, 5, 3, 2, 10, 11, 9, 6, 13, 7};
	bubble_sort(a);
	output(a);
	return EXIT_SUCCESS;
}

void bubble_sort(int a[])
{
        int i, n, n1;
	n = ARR_SIZE;
	printf("%d \n",n);
        do {
		n1 = 0;
		for(i = 1; i < n; i++)
			if (a[i - 1] > a[i]) {
				swap(&a[i - 1], &a[i]);
				n1 = i;
			}
		n = n1;	
	} while(n != 0);
		

}

void output(int a[])
{
	int i;
	for(i = 0; i < ARR_SIZE; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
