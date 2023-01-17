/******************************************************************************
 * Assignment 4: Multi-threaded Producer Consumer Counter
 * Name: Ethan Largent
 * Class: Operating Systems 1 - Benjamin Brewster
 * Due date: 11/21/2022
 * Description: Counts to 10 using two threads communicating between eachother
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define COUNT_TO 10 //The value to be counted to

int myCount = 0;

pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t myCond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t myCond2 = PTHREAD_COND_INITIALIZER;


/********************
 * CONSUMER THREAD
********************/
void *consumer() {
    while(myCount != COUNT_TO) {
        printf("CONSUMER: myMutex locked\n");
        pthread_mutex_lock(&myMutex);
        printf("CONSUMER: waiting on myCond2\n");
        while(myCount % 2 == 1)
            pthread_cond_wait(&myCond2, &myMutex);
        if(myCount == COUNT_TO)
            break;
        printf("myCount: %d -> %d\n", myCount - 1, (myCount++) + 1);
        printf("CONSUMER: myMutex unlocked\n");
        pthread_mutex_unlock(&myMutex);
        printf("CONSUMER: signaling myCond1\n");
        pthread_cond_signal(&myCond1);
    }
    return NULL;
}

/********************
 * PRODUCER THREAD
********************/
int main() {
    printf("PROGRAM START\n");

    pthread_t consumer_thread;
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    printf("CONSUMER THREAD CREATED\n");

    while(myCount != COUNT_TO) {
        printf("PRODUCER: myMutex locked\n");
        pthread_mutex_lock(&myMutex);
        printf("PRODUCER: waiting on myCond1\n");
        while(myCount % 2 == 0)
            pthread_cond_wait(&myCond1, &myMutex);
        if(myCount == COUNT_TO)
            break;
        printf("myCount: %d -> %d\n", myCount - 1, (myCount++) + 1);
        printf("PRODUCER: myMutex unlocked\n");
        pthread_mutex_unlock(&myMutex);
        printf("PRODUCER: signaling myCond2\n");
        pthread_cond_signal(&myCond2);
    }

    pthread_join(consumer_thread, NULL);
    printf("PROGRAM END\n");
    return 0;
}
