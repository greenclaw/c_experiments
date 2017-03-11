#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
 
int main() {
   
    int i;
    struct rusage r_usage;
    const int memory = 1024 *1024;
    for (i = 0; i< 10; i++) {
        void *a = malloc(10 * memory);
        memset(a, 0, 10 * memory);
        getrusage(RUSAGE_SELF, &r_usage);
        printf("Memory used = %ld\n", r_usage.ru_maxrss);         
        sleep(1);
    }
    return 0;
}
