//
// Created by Madina Gafarova on 26/09/2018.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#define TRUE 1

void handler(int sign){
    printf("Catch signal %d", sign );
    exit(1);
}

int main(){
    signal(SIGINT, handler);
    while(TRUE){
        printf("Sleep...");
        sleep(1);
    }
}