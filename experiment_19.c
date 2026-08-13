#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mutex;

void *process(void *arg) {
    int i;

    for(i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        count++;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, process, NULL);
    pthread_create(&t2, NULL, process, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Count = %d\n", count);

    pthread_mutex_destroy(&mutex);

    return 0;
}