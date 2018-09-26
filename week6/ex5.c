//
// Created by Madina Gafarova on 26/09/2018.
//
#include<stdio.h>
#include<signal.h>
#include <zconf.h>

void handle_signal(int sig){
    if (sig == SIGTERM)
        printf("SIGTERM\n");

}

void send_signal(int pid){
    int ret = kill(pid, SIGTERM);
}

int main(){
    pid_t p;
    p = fork();

    if(p > 0){
        sleep(10);
        kill(p, SIGTERM);
    }else if(p==0){
        signal(SIGTERM,handle_signal);
        while(1){
            printf("I am alive\n");
            sleep(1);
        }
    }
    return 0;

}