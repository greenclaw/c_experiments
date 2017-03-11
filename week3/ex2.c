#include<stdio.h>

int main(void) {
	int n;
	int i;
	for ( i = 0; i < 3; i++) {
	n = fork();
	if (n < 0) {
                //handle_error();
        } else if (n > 0) {
                printf(" Hello from parent [PID - %d \n", n);
		sleep(5);
        } else {
                printf(" Hello from child [PID - %d \n", n);
		sleep(5);
        }
	}
	sleep(5);
}
