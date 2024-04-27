#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS1 15
int shared_variable1 = 0;
pthread_mutex_t mutex;

void *threadFunction1(void *threadId) {
    long tid;
    tid = (long)threadId;
    shared_variable1++;
    printf("Hello World! It's me, thread #%ld! shared var %d\n", tid,shared_variable1);
    pthread_exit(NULL);
}

int example1() {
    pthread_t threads[NUM_THREADS1];
    int rc;
    long t;

    for(t = 0; t < NUM_THREADS1; t++) {
        printf("In example1: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, threadFunction1, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    for(t = 0; t < NUM_THREADS1; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads completed. Exiting...\n");

    pthread_exit(NULL);
}


int main() {
    example1();
}
