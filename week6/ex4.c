//
// Created by Madina Gafarova on 26/09/2018.
//
#include<stdio.h>
#include<signal.h>
#include <zconf.h>

void handle_signal(int sig){
    if (sig == SIGUSR1)
        printf(" SIGUSR1\n");
    else if (sig == SIGKILL)
        printf(" SIGKILL\n");
    else if (sig == SIGSTOP)
        printf(" SIGSTOP\n");

}

int main(){
    if (signal(SIGUSR1, handle_signal) == SIG_ERR)
        printf("\ncan't catch SIGUSR1\n");
    if (signal(SIGKILL, handle_signal) == SIG_ERR)
        printf("\ncan't catch SIGKILL\n");
    if (signal(SIGSTOP, handle_signal) == SIG_ERR)
        printf("\ncan't catch SIGSTOP\n");
    while(1){
        sleep(1);
        printf("%d\n",getpid());
    }
}
