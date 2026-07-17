#include <stdio.h>
#include <pthread.h>

void *func_thread(void *arg){
    int *v = (int *)arg;
    *v = *v * 5;
    return NULL;
}

int main(){
    pthread_t t1;
    int n = 5;

    pthread_create(&t1, NULL, func_thread, &n);
    pthread_join(t1, NULL);

    printf("Thread returned: %d\n", n);

    return 0;
}
