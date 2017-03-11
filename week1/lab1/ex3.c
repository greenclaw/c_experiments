#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_rsu_triangle(int n);

int main(int argc, char *argv[])
{
        int n, i, j;

        puts("Enter number of lines:");
        if (sscanf(argv[1], "%d", &n) != 1) {
		printf("Wrong parameter value\n");
		return EXIT_FAILURE;
	}

	puts("Enter figure which must be printed:");
	int choise;
	switch(choise):
	case 0:
		
	print_rsu_triangle(n);
	return EXIT_SUCCESS;
}

void print_rsu_triangle(int n)
{
	int i, j, k;

	for (i = 1; i <= n; i++) {
		for (j = 0; j < n - i; j++){
			putchar(' ');
		}
		for (k = n -i; k < n + i -1; k++) {
			putchar('*');
		}
		putchar('\n');
	}
}
