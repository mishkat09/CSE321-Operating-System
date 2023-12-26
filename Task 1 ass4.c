#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_ITEMS 10
#define BUFLEN 6
#define NUM_THREADS 2

char buffer[BUFLEN];
char source[] = "abcdef";
int producer_count = 0, consumer_count = 0, source_len;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER, full = PTHREAD_COND_INITIALIZER;

void *producer(void *id) {
    int tid = *(int *)id;
    while (producer_count < MAX_ITEMS) {
        pthread_mutex_lock(&count_mutex);
        while (strlen(buffer) == BUFLEN) {
            pthread_cond_wait(&full, &count_mutex);
        }
        buffer[strlen(buffer)] = source[producer_count % source_len];
        printf("%d produced %c by Thread %d\n", producer_count, source[producer_count % source_len], tid);
        producer_count++;
        pthread_cond_signal(&nonEmpty);
        pthread_mutex_unlock(&count_mutex);
        usleep(500);
    }
    pthread_exit(NULL);
}

void *consumer(void *id) {
    int tid = *(int *)id;
    while (consumer_count < MAX_ITEMS) {
        pthread_mutex_lock(&count_mutex);
        while (strlen(buffer) == 0) {
            pthread_cond_wait(&nonEmpty, &count_mutex);
        }
        char c = buffer[strlen(buffer) - 1];
        buffer[strlen(buffer) - 1] = '\0';
        printf("%d consumed %c by Thread %d\n", consumer_count, c, tid);
        consumer_count++;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&count_mutex);
        usleep(500);
    }
    pthread_exit(NULL);
}

int main() {
    int i, thread_id[NUM_THREADS] = {0, 1};
    pthread_t thread[NUM_THREADS];
    source_len = strlen(source);
    pthread_create(&thread[0], NULL, producer, &thread_id[0]);
    pthread_create(&thread[1], NULL, consumer, &thread_id[1]);
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    return 0;
}
