#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sig_handler(int signo) {
	printf("received CTRL+C SIGINT \n");
}

void sig_stop(int signo) {
        printf("received SIGSTOP \n ");
}

void sig_kill(int signo) {
	printf("received SIGKILL \n");
}

void sig_usr1(int signo) {
        printf("received SIGUSR1 \n");
}

int main()
{
	signal(SIGSTOP, sig_stop);
	signal(SIGKILL, sig_kill);
	signal(SIGUSR1, sig_usr1);
	while(1)
		sleep(10);
	return 0;
}
