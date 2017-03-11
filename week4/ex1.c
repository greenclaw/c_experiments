#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>
#define N 10

void *func(int *arg)
{
	printf("I'm thread number %d\n", (int)arg);
	return 0;
}

int main(int argc, char *argv[])
{
	int s,i ;
	pthread_t threads[N];
	for (i = 0;i < N; i++) {
		s = pthread_create(&threads[i],
					NULL,
					func,
					(void *)i);
		 pthread_join(threads[i], NULL);
	}
	return 0;
}

