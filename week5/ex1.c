#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	char string1[] = "Hello!\n";
	char string2[80];
	int fd[2], nbytes;
	pipe(fd);
	write(fd[1], string1, (strlen(string1) + 1));
	nbytes = read(fd[0], string2, sizeof(string2));
	close(fd[0]);
	close(fd[1]);
	printf("Pipe tranfer is done: %s\n", string2);
}
