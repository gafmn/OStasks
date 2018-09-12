//
// Created by Madina Gafarova on 12/09/2018.
//
#include <stdio.h>
#include <stdlib.h>

int main(){
    char cmnd[10];
    while (1) {
        printf("> ");
        scanf("%s", cmnd);
        system(cmnd);
    }
}

