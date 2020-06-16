/*
CS5007
Homework 6 - Problem 1: Multiple threads and shared variable
2020/06/16
Randy Lirano
*/

/*
This program provides excercise working with multiple threads and shared variable.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 40000
#define NGROUPS 4

// Shared variable
int counter = 0;

// Lock variable
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// Group 1 Thread - unspecified variable arguments
void *thread1(void *vargp) {
    pthread_mutex_lock(&mutex1);
    counter = counter + 1;
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

// Group 2 Thread - unspecified variable arguments
void *thread2(void *vargp) {
    pthread_mutex_lock(&mutex1);
    counter = counter + 5;
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

// Group 3 Thread - unspecified variable arguments
void *thread3(void *vargp) {
    pthread_mutex_lock(&mutex1);
    counter = counter - 2;
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

// Group 4 Thread - unspecified variable arguments
void *thread4(void *vargp) {
    pthread_mutex_lock(&mutex1);
    counter = counter - 10;
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

int main() {
    // Array to keep PThread IDs of created thread
    pthread_t tid[NTHREADS];
    int i;

    printf("Counter start at: %d\n", counter);

    // Create and run the thread
    for (i = 0; i < (NTHREADS / NGROUPS) * 1; i++) {
        pthread_create(&(tid[i]), NULL, thread1, NULL);
    }

    for (i = 10000; i < (NTHREADS / NGROUPS) * 2; i++) {
        pthread_create(&(tid[i]), NULL, thread2, NULL);
    }

    for (i = 20000; i < (NTHREADS / NGROUPS) * 3; i++) {
        pthread_create(&(tid[i]), NULL, thread3, NULL);
    }

    for (i = 30000; i < (NTHREADS / NGROUPS) * 4; i++) {
        pthread_create(&(tid[i]), NULL, thread4, NULL);
    }

    // Wait until all threads are done
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    printf("Counter ends at: %d\n", counter);

    return 0;
}
