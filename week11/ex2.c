//
// Created by Madina Gafarova on 01/11/2018.
//
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    setvbuf(stdout, NULL, _IOLBF, 0);
    char buffer[5] = "Hello";
    for (int i = 0; i < 5; i++) {
        printf("%c", buffer[i]);
        sleep(1);
    }
    return 0;
}
