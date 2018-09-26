//
// Created by Madina Gafarova on 26/09/2018.
//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main(){
    int readWrite[2];

    char str[] = "OS";
    char res[] = "";

    if(pipe(readWrite) == -1){
        return -1;
    }

    write(readWrite[1], str, strlen(str) + 1);
    close(readWrite[1]);
    read(readWrite[0], res, strlen(str) + 1);
    close(readWrite[0]);
    printf("Second pipe %s\n", res);
    return 0;
}
