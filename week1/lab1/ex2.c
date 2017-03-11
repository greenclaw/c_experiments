#include <stdio.h>
#include <string.h>
#define MAX_LEN 41

int main(void)
{
	char s[MAX_LEN];
	int i;

	puts("Enter");
	fgets(s, MAX_LEN, stdin);
	printf("Your sentence in reverse:\n");

	for (i = strlen(s) - 1; i >= 0; i--)
	{
		if (s[i] == '\n')
			continue;
		else
			putchar(s[i]);
	}
}
