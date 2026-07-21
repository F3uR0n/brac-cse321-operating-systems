#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
int n;
int done = 0;

pthread_mutex_t mutex;
sem_t supplierSem;
sem_t makerASem;
sem_t makerBSem;
sem_t makerCSem;

void *supplier(void *arg) {
    for (int i = 0; i < n; i++) {

        sem_wait(&supplierSem);
        pthread_mutex_lock(&mutex);
        int random = rand() % 3;

        if (random == 0) {
            printf("Supplier places: Bread and Cheese\n");
            sem_post(&makerCSem);
        }

        else if (random == 1) {
            printf("Supplier places: Bread and Lettuce\n");
            sem_post(&makerBSem);
        }

        else {
            printf("Supplier places: Cheese and Lettuce\n");
            sem_post(&makerASem);
        }
        pthread_mutex_unlock(&mutex);
    }
    sem_wait(&supplierSem);
    done = 1;
    sem_post(&makerASem);
    sem_post(&makerBSem);
    sem_post(&makerCSem);
    pthread_exit(NULL);
}

void *makerA(void *arg) {
    while (1) {
        sem_wait(&makerASem);
        if (done)
            break;

        pthread_mutex_lock(&mutex);
        printf("Maker A picks up Cheese and Lettuce\n");
        printf("Maker A is making the sandwich...\n");
        printf("Maker A finished making the sandwich and eats it\n");
        printf("Maker A signals Supplier\n");
        pthread_mutex_unlock(&mutex);

        sem_post(&supplierSem);
    }
    pthread_exit(NULL);
}

void *makerB(void *arg) {
    while (1) {
        sem_wait(&makerBSem);
        if (done)
            break;

        pthread_mutex_lock(&mutex);
        printf("Maker B picks up Bread and Lettuce\n");
        printf("Maker B is making the sandwich...\n");
        printf("Maker B finished making the sandwich and eats it\n");
        printf("Maker B signals Supplier\n");
        pthread_mutex_unlock(&mutex);

        sem_post(&supplierSem);
    }
    pthread_exit(NULL);
}

void *makerC(void *arg) {
    while (1) {
        sem_wait(&makerCSem);
        if (done)
            break;

        pthread_mutex_lock(&mutex);
        printf("Maker C picks up Bread and Cheese\n");
        printf("Maker C is making the sandwich...\n");
        printf("Maker C finished making the sandwich and eats it\n");
        printf("Maker C signals Supplier\n");
        pthread_mutex_unlock(&mutex);

        sem_post(&supplierSem);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t p1, p2, p3, p4;
    scanf("%d", &n);

    pthread_mutex_init(&mutex, NULL);
    sem_init(&supplierSem, 0, 1);
    sem_init(&makerASem, 0, 0);
    sem_init(&makerBSem, 0, 0);
    sem_init(&makerCSem, 0, 0);

    pthread_create(&p1, NULL, supplier, NULL);
    pthread_create(&p2, NULL, makerA, NULL);
    pthread_create(&p3, NULL, makerB, NULL);
    pthread_create(&p4, NULL, makerC, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&supplierSem);
    sem_destroy(&makerASem);
    sem_destroy(&makerBSem);
    sem_destroy(&makerCSem);
}