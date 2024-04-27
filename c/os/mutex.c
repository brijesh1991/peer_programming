#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t mutex;
int shared_variable = 0;

void *threadFunction(void *threadId) {
    long tid;
    tid = (long)threadId;

    pthread_mutex_lock(&mutex);
    shared_variable++;
    printf("Thread #%ld incremented the shared variable to %d\n", tid, shared_variable);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    pthread_mutex_init(&mutex, NULL);

    for(t = 0; t < NUM_THREADS; t++) {
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, threadFunction, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("All threads completed. Final value of shared variable: %d\n", shared_variable);

    pthread_exit(NULL);
}