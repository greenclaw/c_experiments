#include<stdio.h>
#include<stdlib.h>

void* realloc_usr(void * ptr, size_t s) {
	if (ptr == NULL) return NULL;
	if (s == NULL) { free(ptr); return NULL;}
	void* new_ptr = (void *)malloc(s);
	memcpy(new_ptr, ptr, s);
	free(ptr);
	return new_ptr;
}

int main()
{
	int n1 = 0;
	scanf("%d", &n1);
	int* ptr = malloc(n1 * sizeof(int));
	int i;
	for(i = 0; i < n1; i++) {
		*(ptr + i) = i;
		printf("%d ", *(ptr+i));
	}
	printf("\n");
	int n2 = 0;
	scanf("%d", &n2);
	
	ptr = (int *)realloc_usr((void *)ptr, n2*sizeof(int));
	
	for(i = 0; i < n2; i++) {
		printf("%d ", *(ptr+i));
	}
	printf("\n");
}
