#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#define ARRAY_SIZE 1000000
#define THREAD_NO 10
long sum = 0;
pthread_mutex_t threadLock;

void *mythread(void* arg) {
    int *numbersToSum = (int*) arg;
    long threadSum = 0;
    for(int i = 0; i < ARRAY_SIZE / THREAD_NO; i++) {
		threadSum += numbersToSum[i];
    }
	pthread_mutex_lock(&threadLock);
	sum += threadSum;
	pthread_mutex_unlock(&threadLock);
    return 0;
}

int main(){

    int num[THREAD_NO][ARRAY_SIZE/THREAD_NO];

    srand(100);
    //initialize arrays
    for(int i=0; i< THREAD_NO; i++){
		for(int j=0; j< ARRAY_SIZE/THREAD_NO; j++){
		        num[i][j] = rand() % 100;
		}
    }
    //create threads
    pthread_t p[THREAD_NO];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
    pthread_attr_setschedpolicy(&attr, SCHED_OTHER);

	pthread_mutex_init(&threadLock, NULL);
    for(int i=0; i< THREAD_NO; i++){
		pthread_create(&p[i], &attr, mythread, (void*) num[i]);
    }
    for(int i=0; i< THREAD_NO; i++) {
    	pthread_join(p[i], NULL);
    }
	pthread_mutex_destroy(&threadLock);
    printf("sum = %d\n", sum);
    return 0;
}
