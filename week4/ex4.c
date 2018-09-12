#include <stdlib.h>
#include <stdio.h>

//
// Created by Madina Gafarova on 12/09/2018.
//


int main(){
    char cmnd[10];
    while (1) {
        printf("> ");
        fgets(cmnd, sizeof(cmnd), stdin);
        system(cmnd);
    }
}
