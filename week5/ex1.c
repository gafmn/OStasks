#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <zconf.h>

#define  N  10

void *threadFunction(void* var){
    printf("Thread number: %d \n", *(int *) var);
}

int main() {
    int i;


    pthread_t threads[N];

    printf("Parallel: \n");
    for (i = 1 ; i <= N; ++i){
        printf("Thread %d starts \n", i);
        int arg = i;
        pthread_create(&threads[i], 0, threadFunction, &arg);
        printf("Thread %d ends \n", i);

    }


    printf("\n Sequence: \n");
    for (int i = 1; i <= N; ++i){
        printf("Thread %d starts \n", i);
        int arg = i;
        pthread_create(&threads[i], 0, threadFunction, &arg);
        pthread_join(threads[i], 0);
        printf("Thread %d ends \n", i);

    }

    return 0;
}