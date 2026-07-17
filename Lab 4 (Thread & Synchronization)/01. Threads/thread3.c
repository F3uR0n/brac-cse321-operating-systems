#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *func_thread(void *arg);
int num = 5;
int main() {
    pthread_t t1;
    void *t_ret; 
    pthread_create(&t1, NULL, func_thread, (void *)&num);
    pthread_join(t1, &t_ret);
    printf("Thread returned: %d\n", (int)t_ret);
    
    return 0;
}

void *func_thread(void *arg) {
    int *n = (int *)arg;
    printf("Entered in Thread:\n");
    if (*n % 2 == 0) {
        int result = (int)(*n * *n);
        pthread_exit((void *)result);
        printf("Terminating\n");
    } 
    else {
        int result = (int)(*n * *n * *n);
        pthread_exit((void *)result);
        printf("Terminating\n");
    }
}
