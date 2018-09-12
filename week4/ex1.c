//
// Created by Madina Gafarova on 12/09/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

int main(){
    int pid = fork();
    int n = 234;

    if (pid > 0){
        printf("Hello from parent [%d - %d]\n" , pid, n);
    } else if (pid == 0){
        printf("Hello from child [%d - %d]\n" , pid, n);

    }
    return 0;
}