#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define N 100
#define L 100
#define N_THREADS 2

int buffer_size = 0;
int buffer[N];
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;


void *consumer(void* arg);
void *producer(void* arg);

int main(int argc, char *argv[])
{
        int i;
        pthread_t threads[N_THREADS];
	pthread_attr_t attr;

	pthread_mutex_init(&count_mutex, NULL);
	pthread_cond_init(&count_threshold_cv, NULL);

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	pthread_create(&threads[0],
                                &attr,
                                producer,
                                (void*)1);
	pthread_create(&threads[1],
                                &attr,
                                consumer,
                                (void*)2);

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&count_threshold_cv);
	pthread_exit(NULL);
}

void *producer(void* arg)
{
	int i;
	int product;
	for (i = 0; i < L; i++)
	{
		pthread_mutex_lock(&count_mutex);
		product = i;
		if (buffer_size == N)
                {
			pthread_cond_wait(&count_threshold_cv, &count_mutex);
                }
		buffer[buffer_size++] = product;
		printf("thread: %ld produced the item:%d\n",(long)arg, buffer_size);
		if (buffer_size == 1)
		{
			pthread_cond_signal(&count_threshold_cv);
		}
		pthread_mutex_unlock(&count_mutex);
		sleep(1);
	}
	pthread_exit(NULL);
}

void *consumer(void* arg)
{
        int i;
        int product;
	for (i = 0; i < L; i++)
        {
		pthread_mutex_lock(&count_mutex);
		if (buffer_size == 0)
		{
			pthread_cond_wait(&count_threshold_cv,&count_mutex);
		}
		product = buffer[--buffer_size];
		if (buffer_size == N - 1)
		{
			pthread_cond_signal(&count_threshold_cv);
		}
                printf("thread: %ld consumed the item %d\n\n",(long)arg, buffer_size);
		pthread_mutex_unlock(&count_mutex);
		sleep(2);
        }
	pthread_exit(NULL);
}
