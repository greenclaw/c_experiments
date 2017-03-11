#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sig_handler(int signo) {
	if (signo == SIGINT)
		printf("receive CTRL+C SIGINT \n");
}

int main()
{
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		printf("\n can not catch it \n");
	while(1)
		sleep(10);
	return 0;
}
