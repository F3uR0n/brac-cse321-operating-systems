#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *func_thread(void *v);
int main() {
    pthread_t t1;
    int n;
    void *res; 
    int *t_ret;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    pthread_create(&t1, NULL, func_thread, &n);
    pthread_join(t1, &res);
    t_ret = (int *)res;
    
    for (int i = 0; i < n; i++) {
        printf("a[%d]: %d\n", i, t_ret[i]);
    }

    free(t_ret);
    return 0;
}

void *func_thread(void *v) {
    int len = *(int *)v;
    
    int *a = malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++) {
        printf("Enter value in a[%d]:\n", i);
        scanf("%d", &a[i]);
    }
    return (void *)a;
}
