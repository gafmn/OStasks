//
// Created by Madina Gafarova on 26/09/2018.
//

#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main(){

    pid_t pipe_id;
    int readWrite1[2];
    int readWrite[2];

    char str1[] = "OS";
    if(pipe(readWrite1) == -1){
        return -1;
    }
    if(pipe(readWrite) == -1){
        return -1;
    }
    pipe_id = fork();

    if(pipe_id > 0 ){
        char str2[] = "";

        close(readWrite1[0]);
        write(readWrite1[1], str1, strlen(str1) + 1);
        close(readWrite1);
        wait(NULL);

        close(readWrite[1]);

        read(readWrite[0], str2, strlen(str1) + 1);
        printf("Upgrade! : %s\n", str2 );
        close(readWrite[0]);

    } else if(pipe_id==0){
        char str2[] = "";

        close(readWrite1[1]);
        read(readWrite1[0], str2, strlen(str1) + 1);

        close(readWrite1[0]);
        close(readWrite[0]);

        write(readWrite[1],str2, strlen(str1) + 1);
        close(readWrite[1]);
        exit(0);
    }
}