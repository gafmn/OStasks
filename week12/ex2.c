//
// Created by Madina Gafarova on 08/11/2018.
//
#include <stdio.h>
#include <stdio.h>
#include <memory.h>
#include <fcntl.h>
#include <stdlib.h>

#define SIZE 256

int main(int argc, char* argv[]){

    char buffer[SIZE];
    const char* fl_mode;
    int append = 0;
    FILE* fl;

    for (int i = 1; i < argc; i ++){
        if (strcmp(argv[i], "-a") == 0){
            append = 24000;
        }
    }

    if (append != 0){
        fl_mode = "a";
    } else{
        fl_mode = "w";
    }

    fread(buffer, 1, SIZE, stdin);

    for (int i = 1; i < argc; i ++){
        if (strcmp(argv[i], "-a") == 0){
            continue;
        }
        fl = fopen(argv[i], fl_mode);
        fprintf(fl, "%s", buffer);
        fclose(fl);

    }
    printf("%s", buffer);
    return 0;
}