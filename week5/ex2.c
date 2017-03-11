#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t childpid;
	char string1[] = "Hello!\n";
	char string2[80];
	int fd[2], nbytes;
	pipe(fd);
	if ((childpid = fork()) == -1) {
		perror("fork\n");
		exit(1);
	}
	if (childpid == 0) {
		close(fd[0]);
		write(fd[1], string1, (strlen(string1) + 1));
	} else {
		close(fd[1]);
		nbytes = read(fd[0], string2, sizeof(string2));
		printf("Pipe tranfer is done: %s\n", string2);
	}
}
