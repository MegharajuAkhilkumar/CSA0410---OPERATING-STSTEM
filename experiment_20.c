#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int data = 0;
int readers = 0;

sem_t mutex, write;

void *reader(void *arg) {
    sem_wait(&mutex);

    readers++;

    if(readers == 1)
        sem_wait(&write);

    sem_post(&mutex);

    printf("Reader reads: %d\n", data);

    sem_wait(&mutex);

    readers--;

    if(readers == 0)
        sem_post(&write);

    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg) {
    sem_wait(&write);

    data++;
    printf("Writer writes: %d\n", data);

    sem_post(&write);

    return NULL;
}

int main() {
    pthread_t r1, r2, w;

    sem_init(&mutex, 0, 1);
    sem_init(&write, 0, 1);

    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&w, NULL, writer, NULL);
    pthread_create(&r2, NULL, reader, NULL);

    pthread_join(r1, NULL);
    pthread_join(w, NULL);
    pthread_join(r2, NULL);

    return 0;
}