#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void sig_term() {
	exit(0);
}

int main()
{
	pid_t childpid;
	signal(SIGTERM,sig_term);
	if ((childpid = fork()) == -1) {
		perror("fork error\n");
		return 1;
	}
	if (childpid == 0) {
		while(1) {
			printf("I'm alive\n");
			sleep(1);
		}
	} else {
		sleep(10);
		kill(childpid, SIGTERM);
	}
	return 0;
}
