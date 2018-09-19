//
// Created by Madina Gafarova on 19/09/2018.
//
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define SIZEBUFFER 5
#define MAX 1000000

int i = 0;
int j = 0;
int count = 0;
int buffer[SIZEBUFFER];
int sleepness = 0;

void sleep();
void wakeup();

void* consumerFunction(void* var){
    while (i < MAX){
        printf("From consumer\n");
        if (count == 0){
            printf("Consumer is sleeping\n");
            sleep();
        } else{
            int number = buffer[count - 1];
            count--;
            if (count == SIZEBUFFER - 1){
                printf("Consumer waked up\n");
                wakeup();
            }
        }
        i++;
    }
    pthread_exit(NULL);
}

void* procedureFunction(void* var){
    while (j < MAX){
        printf("From procedure\n");
        if (count == SIZEBUFFER){
            printf("Procedure is sleeping");
             sleep();
        } else{
            buffer[count - 1] = (int) SIZEBUFFER / 2;
            count++;
            if (count == 1){
                printf("Procedure waked up\n");
                wakeup();
            }
        }

        j++;
    }
    pthread_exit(NULL);
}
int main(){

    pthread_t procedure;
    pthread_t consumer;

    pthread_create(&consumer, NULL, consumerFunction, NULL);
    pthread_create(&procedure, NULL, procedureFunction, NULL);

    pthread_join(consumer, NULL);
    pthread_join(procedure, NULL);


    return 0;
}

void sleep(){
    sleepness = 1;
    while (sleepness){}
}

void wakeup(){
    sleepness = 0;
}
