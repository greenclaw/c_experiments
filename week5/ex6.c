#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/wait.h>

int main()
{
	pid_t childpid;
        int fd[2], p_bytes, c_bytes;
	pid_t cpid1, cpid2, pid;
	int status;
	pipe(fd);
	if ((cpid1 = fork()) == -1) {
		perror("fork error\n");
		return 1;
	}
	if (cpid1 == 0) {
		close(fd[1]);
                read(fd[0], &c_bytes, sizeof(c_bytes));
		printf("Child1: Received pid of child2: %d\n", c_bytes);
		sleep(3);
		printf("Child1: Now child1 will stop child2!\n");
		kill(c_bytes,SIGSTOP);
	} else {
		if ((cpid2 = fork()) == -1) {
                        perror("fork error\n");
                        return 1;
                }
                if (cpid2 == 0) {
			while(1) {
				printf("Child2: I am still alive!\n");
				sleep(1);
			}
		} else {
			p_bytes = cpid2;
			printf("Parent: Sending child2 pid to child1: %d\n",p_bytes);
			close(fd[0]);
                	write(fd[1], &p_bytes, sizeof(p_bytes));
			printf("Parent: Now main process waiting when child2 changes state\n");
			pid = waitpid(cpid2, &status, WUNTRACED);
			printf("Parent: Child2 with pid %d has changed state\n", pid);
                }
	}
	return 0;
}
