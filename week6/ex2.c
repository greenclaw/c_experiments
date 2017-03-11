#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = 0;
	printf("Enter size of array\n");
        scanf("%d", &n);
        int* ptr = malloc(n * sizeof(int));
        int i;
        for(i = 0; i < n; i++) {
                *(ptr + i) = i;
                printf("%d ", *(ptr+i));
        }
	printf("\nNow going to free memory\n");
	free(ptr);
}
