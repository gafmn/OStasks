//
// Created by Madina Gafarova on 10/10/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <zconf.h>

int main(){
    char* data;
    struct rusage usage;
    int bytes = (1024*1024);
    for (int i = 0; i < 10; i++){
        data = (char*) malloc(10 * bytes);
        memset(data, '0',10*bytes );
        getrusage(RUSAGE_SELF, &usage);
        printf("%d", i);
        printf("%ld\n", usage.ru_maxrss);
        sleep(1);
    }
    return 0;
}
