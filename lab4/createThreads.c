#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#define THREAD_NO 10

void *mythread(void *arg) {
    int idNum = (intptr_t) arg;
    printf("my id is %d\n", idNum);
}

//this code is highly inspired by the PthreadsIntro repl.it 
int main(){
    pthread_t p[THREAD_NO];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
    pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
    int i = 0;
    for(i=0; i<THREAD_NO; i++){
        pthread_create(&p[i], &attr, mythread, (void*)(intptr_t)i);
    }

    for(i=0; i<THREAD_NO; i++){
	pthread_join(p[i], NULL);
    }
    return 0;
}
