#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_rsu_triangle(int n, int f);

int main(int argc, char *argv[])
{
        int n, i, j;

        if (sscanf(argv[1], "%d", &n) != 1) {
		printf("Wrong parameter value\n");
		return EXIT_FAILURE;
	}

	int choise;
	if (sscanf(argv[1], "%d", &choise) != 1)
		return EXIT_FAILURE;

	print_rsu_triangle(n, choise);
	return EXIT_SUCCESS;
}

void print_rsu_triangle(int n, int f)
{
	int i, j, k, c;
	switch(f) {
	case 1:
		c = 0;
		break;
	case 2:
		c = -n;
		break;
	}
	for (i = 1; i <= n; i++) {
		for (k = n - i + c ; k < n + i - 1; k++) {
			putchar('*');
		}
		putchar('\n');
	}
}
