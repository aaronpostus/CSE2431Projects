#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#define ARRAY_SIZE 1000000
#define THREAD_NO 10
long sum = 0;

void *mythread(void* arg) {
    int *numbersToSum = (int*) arg;
    for(int i = 0; i < ARRAY_SIZE / THREAD_NO; i++) {
	sum += numbersToSum[i];
    }
    return 0;
}

int main(){

    int num[THREAD_NO][ARRAY_SIZE/THREAD_NO];
    void *threadSum;

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

    for(int i=0; i< THREAD_NO; i++){
	pthread_create(&p[i], &attr, mythread, (void*) num[i]);
    }
    for(int i=0; i< THREAD_NO; i++) {
    	pthread_join(p[i], NULL);
    }
    printf("sum = %d\n", sum);
    return 0;
}
