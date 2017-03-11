#include<stdio.h>
#include<stdlib.h>

void main()
{
    int j;
 
    for (j = 0; j < 10; j++) {
        const int memory = 1024 * 1024;
        void *a = malloc(10*memory);
        memset(a, 0, 10*memory);;
        sleep(1);
    }
}
