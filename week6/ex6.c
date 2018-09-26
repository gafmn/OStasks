//
// Created by Madina Gafarova on 26/09/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#define TRUE 1
void handler(int sign);
int main(){
    int readWrite1[2];
    int readWrite2[2];
    pipe(readWrite1);
    pipe(readWrite2);

    pid_t child1;
    pid_t child2;

    child1 = fork();

    if (child1){
        child2 = fork();
    } else {
        pid_t rv;
        read(readWrite1[0], &rv, sizeof(rv));
        printf("Child 1 recieved PID %d, going to sleep... ", rv);
        sleep(7);
        printf("Child 1 awake, stopping the process %d\n", rv);
        kill(rv, SIGSTOP);
        printf("Child 1 stopped, going to sleep... \n");
        sleep(5);
        printf("Child 1 awake, resuming the process %d\n", rv);
        kill(rv, SIGSTOP);
        printf("Child 1 resumed, going to sleep... \n");
        sleep(5);
        printf("Child 1 awake, asking process %d to terminate.\n", rv);
        kill(rv, SIGINT);
        printf("Child 1 awake, asking process %d to terminate.\n", rv);
    }
    if (!child2){
        signal(SIGINT,handler);
        while (TRUE){
            printf("child 2 doing some interesting things");
            sleep(1);
        }
    }

    if (child1 && child2){
        printf("Parent is sending 2nd Child PID %d to 1st Child\n", child2);
        write(readWrite1[1], &child2, sizeof(child2));
        close(readWrite1[1]);
        printf("Parent sent PID. Waiting for changes in 2nd Child...\n");
        pid_t child2Wait = waitpid(child2, 0, 0);
        printf("Child 2 terminated");
    }
    return 0;
}

void handler(int sign){
    switch (sign) {
        case SIGINT:
            printf("Stopped.\n");
            exit(0);
        default:
            break;
    }
}
