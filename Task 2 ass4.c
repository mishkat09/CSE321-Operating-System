#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRODUCTS 5
#define WAREHOUSE_SIZE 5

sem_t empty, full;
pthread_mutex_t mutex;
char products[WAREHOUSE_SIZE] = {'A', 'B', 'C', 'D', 'E'};
char warehouse[WAREHOUSE_SIZE] = {'N'};

void *producer(void *arg) {
    int producer_id = *(int*)arg;
    srand(time(NULL));
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        char product = products[rand() % WAREHOUSE_SIZE];
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        warehouse[i] = product;
        printf("Producer %d: Insert product %c at %d\n", producer_id, product, i);
        for (int j = 0; j < WAREHOUSE_SIZE; j++) printf("%c", warehouse[j]);
        printf("\n");
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int consumer_id = *(int*)arg;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        char product = warehouse[i];
        warehouse[i] = 'N';
        printf("Consumer %d: Remove product %c from %d\n", consumer_id, product, i);
        for (int j = 0; j < WAREHOUSE_SIZE; j++) printf("%c", warehouse[j]);
        printf("\n");
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producers[5], consumers[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, WAREHOUSE_SIZE);
    sem_init(&full, 0, 0);
    int producer_ids[5] = {1, 2, 3, 4, 5};
    int consumer_ids[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        pthread_create(&producers[i], NULL, producer, &producer_ids[i]);
        pthread_create(&consumers[i], NULL, consumer, &consumer_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
